#include <vector>
#include <iostream>
#include <unordered_map>
// converts infix into postfix expression
// + and - have equal priority
// / and * have equal priority
// ( can only be popped by )
std::unordered_map<char, int> precedence = {
    {'+', 1},
    {'-', 1},
    {'*', 2},
    {'/', 2},
    {'(', 3}
};
bool isOperator(char token){
    if(token == '+' || 
       token == '-' || 
       token == '*' || 
       token == '/' ||
       token == '(' ||
       token == ')'){
        return true;
    }
    return false;
}
bool balanceCheck(const std::string& expression){
    int balance = 0;
    for(char token: expression){
        if(token == '(') balance++;
        else if(token == ')') balance--;
        if(balance < 0) return false;
    }
    return balance == 0;
}
std::string infixToPostfix(const std::string& expression){
    if(!balanceCheck(expression)){
        return "unbalanced parentheses";
    }
    std::vector<char> opStack;
    std::string postfix = "";
    for(char token: expression){
        // std::cout << " current token: " << token << ": ";
        if(isalnum(token)){
            // std::cout << "isalnum\n";
            postfix += token;
        }
        else if(isOperator(token)){
            // std::cout << "isOperator:";
            if(opStack.empty()){
                // std::cout << " empty stack(pushed)\n";
                opStack.push_back(token);
                continue;
            } 
            if(token == ')'){
                // std::cout << " right parenthesis (popping)\n";
                while(opStack.back() != '('){
                    postfix += opStack.back();
                    opStack.pop_back();
                }
                opStack.pop_back(); // pop the '('
                continue;
            }
            while(!opStack.empty() && opStack.back() != '('){
                if(precedence.at(opStack.back()) >= precedence.at(token)){
                    // std::cout << " pop_back higher or equal precedence\n";
                    postfix += opStack.back();
                    opStack.pop_back();
                }
                else break;
            }
            // std::cout << " pushing\n";
            opStack.push_back(token);
            // std::cout << " current stack: ";
            // for(char t: opStack)std::cout << t << ' ';
            // std::cout << std::endl;
        }
        //std::cout << " current exp: " << postfix << std::endl;
    }
    while(!opStack.empty()){
        postfix += opStack.back();
        opStack.pop_back();
    }
    return postfix;
}
int postFixEvaluater(const std::string& expression){
    std::vector<int> evalStack;
    for(char token: expression){
        if(isalpha(token)){
            std::cerr << "<invalid expression>" << std::endl;
            return -1;
        }
        if(isalnum(token)){
            evalStack.push_back(token - '0'); // convert char to int
            // std::cout << " pushing number: " << evalStack.back() << std::endl;
            continue;
        }
        else if(isOperator(token)){
            if(evalStack.empty()){
                std::cerr << "<invalid expression>" << std::endl;
                return -1;
            }
            int rhs = evalStack.back();
            evalStack.pop_back();
            int lhs = evalStack.back();
            evalStack.pop_back();
            // std::cout << " popping: " << lhs << ' ' << token << ' ' << rhs << " = ";
            switch (token)
            {
                case '+':
                    evalStack.push_back(lhs + rhs);
                    break;
                case '-':
                    evalStack.push_back(lhs - rhs);
                    break;
                case '*':
                    evalStack.push_back(lhs * rhs);
                    break;
                case '/':
                    evalStack.push_back(lhs / rhs);
                    break;
                default:
                    break;
            }
            // std::cout << evalStack.back() << std::endl;
        }
    }
    return evalStack.back();
}
int main(){
    std::cout << infixToPostfix("a+b*c+(d*e+f)*g") << std::endl;
    std::cout << postFixEvaluater("6523+8*+3+*") << std::endl;
    return 0;
}