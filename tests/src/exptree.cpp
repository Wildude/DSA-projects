#include "../../core/tree/tree.hpp"
#include <vector>
#include <iostream>
#include <sstream>
bool isOperator(char token){
    if(token == '+' || 
       token == '-' || 
       token == '*' || 
       token == '/'
       ){
        return true;
    }
    return false;
}
treeNode<char>* formExpressionTree(const std::string& expression){
    std::vector<treeNode<char>*> expStack;
    for(char token: expression){
        if(isalnum(token)){
            expStack.push_back(new treeNode<char>(token));
            //std::cout << " pushed num: "<< expStack.back()->value << std::endl;
        }
        else if(isOperator(token)){
            treeNode<char>* rhs = expStack.back();
            expStack.pop_back();
            treeNode<char>* lhs = expStack.back();
            expStack.pop_back();
            expStack.push_back(new treeNode<char>(token, lhs, rhs));
            //std::cout << " pushed exp: " << lhs->value << ' ' << expStack.back()->value << ' ' << rhs->value << std::endl;
        }
    }
    return expStack.back();
}
std::string postfixToInfix(const std::string& expression){
    treeNode<char>* root = formExpressionTree(expression);
    std::ostringstream captured_output;
    inorder<char>(root, captured_output);
    // free memory used by the tree
    eraseTree<char>(root);
    // Get the entire captured string
    return captured_output.str();    
}
int main(){
    std::cout << postfixToInfix("ab+cde+**");
}