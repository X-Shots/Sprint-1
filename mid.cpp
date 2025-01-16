#include <iostream>
#include <sstream>
#include <stack>
#include <cmath>
#include <map>
#include <cctype>
#include <vector>

using namespace std;
//returns true if the character is a number
bool isOperand(char c){
    return isdigit(c);
}
//returns true if the character is an operator
bool isOperator(char c){
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}
//returns the precedence of the operator
int precedence(char c){
    if(c == '^'){
        return 3;
    }
    else if(c == '*' || c == '/'){
        return 2;
    }
    else if(c == '+' || c == '-'){
        return 1;
    }
    else{
        return -1;
    }
}
//converts infix expression to postfix expression
vector<string> toPostfix(string infix){
    stack<char> operators;
    vector<string> postfix;
    string number;

    for (char c : infix){
        
        //if the character is a number, add it to the postfix expression
        if(isOperand(c)){
            number += c;
        } else{
            if(!number.empty()){
                postfix.push_back(number);
                number.clear();
            }
            if (c == ' ') {
                // Skip spaces 
                continue;
            }
        //if the character is an operator, check the precedence and add it to the postfix expression accordingly
        else if(isOperator(c)){
            if(operators.empty() || precedence(c) > precedence(operators.top())||  operators.top() == '('){
                operators.push(c);
            }
            else{
                while(!operators.empty() && precedence(c) <= precedence(operators.top())){
                    postfix.push_back(string(1,operators.top()));
                    operators.pop();
                }
                operators.push(c);
            }
            
        }
        
        //deal with parentheses
        else if(c == '('){
            operators.push(c);
        }
        else if(c == ')'){
            while(!operators.empty() && operators.top() != '('){
                postfix.push_back(string(1,operators.top()));
                operators.pop();
            }
            operators.pop();
        }
        }
    }
    // If a number remains at the end, add it to the postfix vector
    if (!number.empty()) {
        postfix.push_back(number);
    }
    
    //add the remaining operators to the postfix expression
    while (!operators.empty()){
        postfix.push_back(string(1,operators.top()));
        operators.pop();
    }
    return postfix;


}
double postfixToNumerical(vector<string> postfix){
    stack <double> numbers;
    for (string s : postfix){
        if(isOperand(s[0])){
            numbers.push(stod(s));
        }
        else{
            double b = numbers.top();
            numbers.pop();
            double a = numbers.top();
            numbers.pop();
            if(s == "+"){
                numbers.push(a + b);
            }
            else if(s == "-"){
                numbers.push(a - b);
            }
            else if(s == "*"){
                numbers.push(a * b);
            }
            else if(s == "/"){
                numbers.push(a / b);
            }
            else if(s == "^"){
                numbers.push(pow(a,b));
            }
        }
    }
    return numbers.top();
}


int main(){
    string infix;
    cout << "Enter an infix expression: ";
    getline(cin, infix);;
    vector<string> postfix = toPostfix(infix);
    cout << "Postfix expression: "<< postfixToNumerical(postfix) << endl;
    return 0;
}