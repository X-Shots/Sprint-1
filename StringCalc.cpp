#include <iostream>
#include <sstream>
#include <stack>
#include <cmath>
#include <map>
#include <cctype>
#include <vector>

using namespace std;

// Helper function to determine if a string is a number
bool isNumber(const string& s) {
    stringstream ss(s);
    double val;
    return (ss >> val) && ss.eof();
}

// Function precedence map
map<string, int> precedence = {
    {"+", 1}, {"-", 1},
    {"*", 2}, {"/", 2},
    {"^", 3}, {"sin", 4},
    {"cos", 4}, {"tan", 4}
};

// Check if the token is an operator
bool isOperator(const string& op) {
    return precedence.find(op) != precedence.end();
}

// Convert infix to postfix (shunting-yard algorithm)
vector<string> infixToPostfix(vector<string> tokens) {
    stack<string> operators;
    vector<string> postfix;

    for (const string& token : tokens) {
        if (isNumber(token)) {
            postfix.push_back(token); // Numbers go directly to output
        } else if (isOperator(token)) {
            // While top of stack has higher precedence, pop operators to output
            while (!operators.empty() && precedence[operators.top()] >= precedence[token]) {
                postfix.push_back(operators.top());
                operators.pop();
            }
            operators.push(token);
        } else if (token == "(") {
            operators.push(token); // Left parenthesis goes to stack
        } else if (token == ")") {
            // Pop until left parenthesis is found
            while (!operators.empty() && operators.top() != "(") {
                postfix.push_back(operators.top());
                operators.pop();
            }
            operators.pop(); // Remove left parenthesis
        }
    }

    // Pop remaining operators
    while (!operators.empty()) {
        postfix.push_back(operators.top());
        operators.pop();
    }

    return postfix;
}

// Evaluate postfix expression
double evaluatePostfix(vector<string> postfix) {
    stack<double> values;

    for (const string& token : postfix) {
        if (isNumber(token)) {
            values.push(stod(token)); // Convert string to double and push
        } else if (isOperator(token)) {
            // Handle basic operators
            double b = values.top(); values.pop();
            double a = values.top(); values.pop();
            if (token == "+") values.push(a + b);
            else if (token == "-") values.push(a - b);
            else if (token == "*") values.push(a * b);
            else if (token == "/") values.push(a / b);
            else if (token == "^") values.push(pow(a, b));
        } else if (token == "sin" || token == "cos" || token == "tan") {
            // Handle math functions
            double a = values.top(); values.pop();
            if (token == "sin") values.push(sin(a));
            else if (token == "cos") values.push(cos(a));
            else if (token == "tan") values.push(tan(a));
        }
    }

    return values.top(); // The result is at the top of the stack
}

// Tokenize the input string
vector<string> tokenize(string expression) {
    vector<string> tokens;
    string current;

    for (char c : expression) {
        if (isspace(c)) continue; // Ignore spaces
        if (isdigit(c) || c == '.') {
            current += c; // Build multi-digit numbers
        } else {
            if (!current.empty()) {
                tokens.push_back(current); // Add the number to tokens
                current.clear();
            }
            if (c == '(' || c == ')') {
                tokens.push_back(string(1, c)); // Parentheses
            } else {
                tokens.push_back(string(1, c)); // Operators
            }
        }
    }

    if (!current.empty()) tokens.push_back(current); // Add the last number

    return tokens;
}

// Main program
int main() {
    cout << "Enter a mathematical expression: ";
    string input;
    getline(cin, input);

    // Tokenize the input
    vector<string> tokens = tokenize(input);

    // Convert to postfix notation
    vector<string> postfix = infixToPostfix(tokens);

    // Evaluate the postfix expression
    double result = evaluatePostfix(postfix);

    cout << "Result: " << result << endl;

    return 0;
}