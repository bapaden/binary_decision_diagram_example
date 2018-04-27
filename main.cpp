#include <iostream>
#include <vector>
#include <bdd.h>
#include <assert.h>

/**
 * Applies the interpretation of propositional symbols stored in order in "interpretation"
 * to the boolean formula "formula". The output is a trivial boolean formula obtained from the 
 * restriction of the variables to the values.
 */
bdd evaluate(const std::vector<bool>& interpretation, const bdd& formula){
  bdd eval = formula;
  for(int i=0;i<4;i++){
    if(interpretation[i]){
      bdd var_i = bdd_ithvar(i);
      eval = bdd_restrict(eval,var_i);
    }
    else{
      bdd var_i = bdd_nithvar(i);
      eval = bdd_restrict(eval,var_i);
    }
  }
  return eval;
}

int main(int argc, char **argv) {
  bdd_init(100, 1000);
  bdd_setvarnum(4);
  
  //These are the actual propositional symbols
  bdd s1 = bdd_ithvar(0);
  bdd s2 = bdd_ithvar(1);
  bdd s3 = bdd_ithvar(2);
  bdd s4 = bdd_ithvar(3);
  
  //This is a sample boolean formula
  bdd boolean_formula = s1 & s2 | s3 & s4;
  
  //Prints the bdd array-based data structure
  bdd_printtable(boolean_formula);

  //Create an interpretation of the variables we want to evaluate
  std::vector<bool> interpretation({true, true, false, true});
  
  //Call the evaluate method to determine if the interpretation satisfies the formula
  bdd eval = evaluate(interpretation,boolean_formula);
  
  //The result should be a trivial bdd with one node 1/0 for satisfied or not satisfied
  bdd_printtable(eval);
  
  //Access to the truth value of the formula restricted to the assignment of the variables
  if(eval.id()){std::cout << "The formula was satisfied by the variable assignment " << std::endl;}
  else{std::cout << "The formula was not satisfied " << std::endl;}
    return 0;
}
