

#ifndef ShuntingYard_hpp
#define ShuntingYard_hpp

#include <iostream>
#include <string>
#include <sstream>

#include "SimpleList.hpp"
#include "Queue.hpp"
#include "Stack.hpp"
#include "Token.hpp"
#include "Operand.hpp"
#include "Operator.hpp"
#include "Variable.hpp"
#include "Constants.hpp"

class Shunting {
public:
    Shunting() {
        userInput(); // get the expression string
    }
    
    //get the expression for calculation from user input
    void userInput() {
        cout << "Enter an expression, i.e. 5.5 ( 4.0 ^ 2 + X ) sin ( 0.9 ) \n";
        cout << "My expression: ";
        getline(cin, _expression);
    }
    
    //parse the user-input string into tokens and store them in queue
    Queue<Token*> toToken();
    
    //convert the infix queue to a post-fix queue using Shunting-Yard algorithm
    Queue<Token*> toPostFix(Queue<Token*> infix);
    
    //get a queue of Token* as an RPN equation
    Queue<Token*> getRPN() {
        Queue<Token*> equation = toPostFix(toToken());
        return equation;
    }
    string getExpression() {return _expression;}
    //evaluate the postfix queue
    double Eval(Queue<Token*> postfix, double var_num);
    
    //void test_eval();
    void test_shunting();
    
private:
    string _expression;
    
};

#endif /* ShuntingYard_hpp */
