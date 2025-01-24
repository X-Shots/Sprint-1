#include <wx/wx.h>
#include <wx/grid.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>
#include <stack>
#include <string>
#include <sstream>
#include <cmath>
#include <cctype>
#include <stdexcept>
#include <iostream>
#include <map>
#include <vector>

//class FourFunction {
//public:
//    double add(double a, double b) { return a + b; }
//    double subtract(double a, double b) { return a - b; }
//    double multiply(double a, double b) { return a * b; }
//    double divide(double a, double b) { return b != 0 ? a / b : throw std::runtime_error("Division by zero"); }
//    double exponent(double a, double b) { return pow(a, b); }
//    double squareRoot(double a) { return a >= 0 ? sqrt(a) : throw std::runtime_error("Invalid square root"); }
//    double sine(double a) { return sin(a); }
//    double cosine(double a) { return cos(a); }
//    double tangent(double a) { return tan(a); }
//    
//    
//};



//Methods for the FourFunction class
class MathFunction {
public:
    double add(double a, double b) {
        return a + b;
    }
    double subtract(double a, double b) {
        return a - b;
    }
    double multiply(double a, double b) {
        return a * b;
    }
    double divide(double a, double b) {
        return a / b;
    }

    double exponent(double a, double b) {
        return pow(a, b);
    }
    double squareRoot(double ans) {
        return sqrt(ans);
    }
    double log(double ans) {
        return log(ans);
    }
    double log10(double ans) {
        return log10(ans);
    }
    double sine(double ans) {
        return sin(ans);
    }
    double cosine(double ans) {
        return cos(ans);
    }
    double tangent(double ans) {
        return tan(ans);
    }
    double secant(double ans) {
        return 1 / cos(ans);
    }
    double cosecant(double ans) {
        return 1 / sin(ans);
    }
    double cotangent(double ans) {
        return 1 / tan(ans);
    }
    // double pi = 2 * acos(0.0);
    double remainder(double a, double b) {
        return remainder(a, b);
    }
    double tithing(double ans) {
        return ans / 10;
    }
    double tip(double a, double b) {
        return (a / 100) * b;
    }
    double discount(double a, double b) {
        return a - (a * (b / 100));
    }
    double pi(double ans) {
		return ans * 3.14159;
    }
};

//Main Method
//int main() {
//    //Variables for User Input and Calculations
//    int UserInput;
//    double a;
//    double b;
//    double ans = 1;
//    //Initialize an object of the FourFunction class named "calc"
//    MathFunction calc;
//    //Welcome text
//    cout << "Welcome to the Four Function Calculator! ";
//    cout << "\n";
//    //User Input for starting value
//    cout << "What number would you like to start with? ";
//    cin >> ans;
//    cout << "\n";
//    //Loops to allow the user to make as many calculations as they want using the FourFunction class
//    do {
//        //displays the current value and asks which function to use
//        cout << "The current number is: " << ans << "\n\n";
//        cout << "The four functions are: ";
//        cout << "\n\t1. Addition\n\t2. Subtraction\n\t3. Multiplication\n\t4. Division\n\t5. Exponent\n\t6. Square Root\n\t7. Log\n\t8. Log 10\n\t9. sin\n\t10. cos\n\t11. tan\n\t12. sec\n\t13. csc\n\t14. cot\n\t15. PI\n\t16. Remainder\n\t17. Tithing\n\t18. Calculate tip";
//        cout << "\nWhat is the number of the function you would like to use?(Type 0 to quit) ";
//        cin >> UserInput;
//        cout << "\n";
//        // Asks the user for the second number and calculates the answer based on the user input
//        if (UserInput == 1) {
//            cout << "How much would you like to add? ";
//            cin >> b;
//            ans = calc.add(ans, b);
//        }
//        else if (UserInput == 2) {
//            cout << "How much would you like to subtract? ";
//            cin >> b;
//            ans = calc.subtract(ans, b);
//        }
//        else if (UserInput == 3) {
//            cout << "How much would you like to multiply by? ";
//            cin >> b;
//            ans = calc.multiply(ans, b);
//        }
//        else if (UserInput == 4) {
//            cout << "How much would you like to divide by? ";
//            cin >> b;
//            ans = calc.divide(ans, b);
//        }
//        else if (UserInput == 5) {
//            cout << "What is the exponent? ";
//            cin >> b;
//            ans = calc.exponent(ans, b);
//        }
//        else if (UserInput == 6) {
//            ans = calc.squareRoot(ans);
//        }
//        else if (UserInput == 7) {
//            ans = calc.log(ans);
//        }
//        else if (UserInput == 8) {
//            ans = calc.log10(ans);
//        }
//        else if (UserInput == 9) {
//            ans = calc.sine(ans);
//        }
//        else if (UserInput == 10) {
//            ans = calc.cosine(ans);
//        }
//        else if (UserInput == 11) {
//            ans = calc.tangent(ans);
//        }
//        else if (UserInput == 12) {
//            ans = calc.secant(ans);
//        }
//        else if (UserInput == 13) {
//            ans = calc.cosecant(ans);
//        }
//        else if (UserInput == 14) {
//            ans = calc.cotangent(ans);
//        }
//        // else if(UserInput == 15){
//        //     ans = calc.pi()
//        // }
//        else if (UserInput == 16) {
//            ans = calc.remainder(ans, b);
//        }
//
//        else if (UserInput == 17) {
//            ans = calc.tithing(ans);
//        }
//        else if (UserInput == 18) {
//            cout << "What '%' do you want to tip? ";
//            cin >> b;
//            ans = calc.tip(ans, b);
//        }
//
//        // Input for user to exit program
//        else if (UserInput == 0) {
//            cout << "Goodbye!";
//        }
//        //Error message for invalid input(Program loops back to allow the user to continue calculating)
//        else {
//            cout << "Invalid input please try again!";
//        }
//        cout << "\n";
//    } while (UserInput != 0);
//
//    return 0;
//}

class CalculatorFrame : public wxFrame {
public:
    CalculatorFrame()
        : wxFrame(nullptr, wxID_ANY, "Calculator", wxDefaultPosition, wxSize(350, 450)) {
        wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);

        // Create a text control for the display (read-only)
        display = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(-1, 50),
            wxTE_RIGHT | wxTE_READONLY);
        display->SetFont(wxFont(18, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
        vbox->Add(display, 0, wxEXPAND | wxALL, 10);
        
        wxGridSizer* grid = new wxGridSizer(4, 8, 5, 5);

        const wxString buttons[] = {
            "7", "8", "9", "/", "tan", "(","cse","tith",
            "4", "5", "6", "*", "sin", ")","cot","t",
            "1", "2", "3", "-", "cos", "^","csc","d",
			"C", "0", "=", "+", "log", "sqrt","pi","rem"
        };

        for (const auto& label : buttons) {
            wxButton* button = new wxButton(this, wxID_ANY, label);
            grid->Add(button, 1, wxEXPAND);
            button->Bind(wxEVT_BUTTON, &CalculatorFrame::OnButtonClicked, this);
        }

        vbox->Add(grid, 1, wxEXPAND | wxALL, 10);
        SetSizer(vbox);




     

            //using namespace std;
            //double degreeToRadian(double degree) {
            //    return degree * M_PI / 180;
            //}
            ////returns true if the character is a number
            //bool isOperand(char c){
            //    return isdigit(c);
            //}
            //bool isFunction(const std::string& s) {
            //    return s == "sin" || s == "cos" || s == "tan" || s == "log" || s == "sqrt";
            //}
            ////returns true if the character is an operator
            //bool isOperator(char c){
            //    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
            //}

            ////returns the precedence of the operator
            //int precedence(const std::string& c) {
            //    if (c == "sin" || c == "cos" || c == "tan" || c == "log" || c == "sqrt") {
            //        return 4;
            //    } else if (c == "^") {
            //        return 3;
            //    } else if (c == "*" || c == "/") {
            //        return 2;
            //    } else if (c == "+" || c == "-") {
            //        return 1;
            //    } else {
            //        return -1;
            //    }
            //}
            ////converts infix expression to postfix expression
            //vector<string> toPostfix(string infix){
            //    stack<string> operators;
            //    vector<string> postfix;
            //    string number;
            //    string function;
            //    for (int i = 0; i < infix.length(); ++i) {
            //        char c = infix[i];
            //        std::string str(1, c);
            //        //method to check for and account for functions like sin tan and log

            //        if (isalpha(c)) {
            //            function += c;
            //            if (!isalpha(infix[i + 1])) {
            //                if (isFunction(function)) {
            //                    operators.push(function);
            //                }
            //                function.clear();
            //            }
            //        }

            //        //if the character is a number, add it to the postfix expression
            //        else if (isOperand(c)) {
            //            number += c;
            //        }
            //        else {
            //            if (!number.empty()) {
            //                postfix.push_back(number);
            //                number.clear();
            //            }
            //            if (c == ' ') {
            //                // Skip spaces 
            //                continue;
            //            }
            //            //if the character is an operator, check the precedence and add it to the postfix expression accordingly
            //            else if (isOperator(c)) {
            //                if (operators.empty() || precedence(string(1, c)) > precedence(operators.top()) || operators.top() == string(1, '(')) {
            //                    operators.push(string(1, c));
            //                }
            //                else {
            //                    while (!operators.empty() && precedence(string(1, c)) <= precedence(operators.top())) {
            //                        postfix.push_back(operators.top());
            //                        operators.pop();
            //                    }
            //                    operators.push(string(1, c));
            //                }

            //            }

            //            //deal with parentheses
            //            else if (c == '(') {
            //                operators.push(string(1, c));
            //            }
            //            else if (c == ')') {
            //                while (!operators.empty() && operators.top() != string(1, '(')) {
            //                    postfix.push_back(operators.top());
            //                    operators.pop();
            //                }
            //                operators.pop();
            //            }
            //        }
            //    }
            //    // If a number remains at the end, add it to the postfix vector
            //    if (!number.empty()) {
            //        postfix.push_back(number);
            //    }
    
            //    //add the remaining operators to the postfix expression
            //    while (!operators.empty()){
            //        postfix.push_back(operators.top());
            //        operators.pop();
            //    }
            //    return postfix;


            //}
            //double postfixToNumerical(vector<string> postfix){
            //    stack <double> numbers;
            //    for (string s : postfix){
            //        if (isdigit(s[0]) || (s[0] == '-' && s.size() > 1)) { // Handle negative numbers
            //            numbers.push(stod(s));
            //        } else if (isFunction(s)) {
            //            double a = numbers.top();
            //            numbers.pop();
            //            if (s == "sin") {
            //                numbers.push(sin(degreeToRadian(a))); // a in radians
            //            } else if (s == "cos") {
            //                numbers.push(cos(degreeToRadian(a)));
            //            } else if (s == "tan") {
            //                numbers.push(tan(degreeToRadian(a)));
            //            } else if (s == "log") {
            //                numbers.push(log(a));
            //            } else if (s == "sqrt") {
            //                numbers.push(sqrt(a));
            //            }
            //        }
            //        else{
            //            double b = numbers.top();
            //            numbers.pop();
            //            double a = numbers.top();
            //            numbers.pop();
            //            if(s == "+"){
            //                numbers.push(a + b);
            //            }
            //            else if(s == "-"){
            //                numbers.push(a - b);
            //            }
            //            else if(s == "*"){
            //                numbers.push(a * b);
            //            }
            //            else if(s == "/"){
            //                numbers.push(a / b);
            //            }
            //            else if(s == "^"){
            //                numbers.push(pow(a,b));
            //            }
            //        }
            //    }
            //    return numbers.top();
            //}
            //double evaluate(string infix){
            //    return postfixToNumerical(toPostfix(infix));
            //}


            //int main(){
            //    string infix;
            //    cout << "Enter an infix expression: ";
            //    getline(cin, infix);;
            //    cout << "Postfix expression: ";
            //    vector<string> postfix = toPostfix(infix);
            //    for(string in : postfix){
            //        cout << in << " ";
            //    }
            //    cout << "Numerical expression: "<< postfixToNumerical(postfix) << endl;
            //    return 0;
            //}
                }

private:
    wxTextCtrl* display;
    wxString currentInput;
    MathFunction calculator;
    wxTextCtrl* inputTextBox;
    wxStaticText* resultLabel;

    void OnButtonClicked(wxCommandEvent& event) {
        wxString label = static_cast<wxButton*>(event.GetEventObject())->GetLabel();

        try {
            if (isdigit(label[0])) {
                currentInput += label;
            }
            else if (label == "C") {
                currentInput.clear();
            }
            else if (label == "=") {
                double result = EvaluateExpression(currentInput.ToStdString());
                currentInput = wxString::Format("%.2f", result);
            }
            else if (label == "+" || label == "-" || label == "*" || label == "/" || label == "^" || label == "(" || label == ")" || label == "t" || label == "d") {
                currentInput += label;
            }
            else if (label == "sqrt") {
                double result = calculator.squareRoot(wxAtof(currentInput));
                currentInput = wxString::Format("%.2f", result);
            }
            else if (label == "sin") {
                double result = calculator.sine(wxAtof(currentInput));
                currentInput = wxString::Format("%.2f", result);
            }
            else if (label == "cos") {
                double result = calculator.cosine(wxAtof(currentInput));
                currentInput = wxString::Format("%.2f", result);
            }
            else if (label == "tan") {
                double result = calculator.tangent(wxAtof(currentInput));
                currentInput = wxString::Format("%.2f", result);
            }
			else if (label == "cse") {
				double result = calculator.secant(wxAtof(currentInput));
				currentInput = wxString::Format("%.2f", result);
			}
			else if (label == "csc") {
				double result = calculator.cosecant(wxAtof(currentInput));
				currentInput = wxString::Format("%.2f", result);
			}
			else if (label == "cot") {
				double result = calculator.cotangent(wxAtof(currentInput));
				currentInput = wxString::Format("%.2f", result);
			}
			else if (label == "pi") {
				double result = calculator.pi(wxAtof(currentInput));
				currentInput = wxString::Format("%.2f", result);
			}
			else if (label == "rem") {
				double result = calculator.remainder(wxAtof(currentInput), wxAtof(currentInput));
				currentInput = wxString::Format("%.2f", result);
			}
			else if (label == "log") {
				double result = calculator.log(wxAtof(currentInput));
				currentInput = wxString::Format("%.2f", result);
			}
			else if (label == "log10") {
				double result = calculator.log10(wxAtof(currentInput));
				currentInput = wxString::Format("%.2f", result);
			}
			else if (label == "tith") {
				double result = calculator.tithing(wxAtof(currentInput));
				currentInput = wxString::Format("%.2f", result);
			}
            else if (label == "tip_of") {
                double result = calculator.tip(wxAtof(currentInput), wxAtof(currentInput));
                currentInput = wxString::Format("%.2f", result);
            }
            else if (label == "dis") {
                double result = calculator.discount(wxAtof(currentInput), wxAtof(currentInput));
                currentInput == wxString::Format("%.2f", result);
            
			}
			else {
				currentInput = "Error";
			}

        }
        catch (const std::exception& e) {
            currentInput = "Error";
        }

        display->SetValue(currentInput);
    }

    int GetPrecedence(char op) {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;
        if (op == '^') return 3;
        return 0;
    }

    bool IsOperator(char c) {
        return c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c =='t' || c =='d';
    }

    std::string InfixToPostfix(const std::string& infix) {
        std::stack<char> opStack;
        std::ostringstream postfix;

        for (size_t i = 0; i < infix.length(); ++i) {
            char c = infix[i];
            if (isdigit(c) || c == '.') {
                postfix << c;
            }
            else if (c == '(') {
                opStack.push(c);
            }
            else if (c == ')') {
                while (!opStack.empty() && opStack.top() != '(') {
                    postfix << ' ' << opStack.top();
                    opStack.pop();
                }
                if (!opStack.empty()) opStack.pop(); // Remove '('
            }
            else if (IsOperator(c)) {
                postfix << ' ';
                while (!opStack.empty() && GetPrecedence(opStack.top()) >= GetPrecedence(c)) {
                    postfix << opStack.top() << ' ';
                    opStack.pop();
                }
                opStack.push(c);
            }
        }

        while (!opStack.empty()) {
            postfix << ' ' << opStack.top();
            opStack.pop();
        }

        return postfix.str();
    }

    double EvaluatePostfix(const std::string& postfix) {
        std::stack<double> valueStack;
        std::istringstream tokens(postfix);
        std::string token;

        while (tokens >> token) {
            if (isdigit(token[0])) {
                valueStack.push(std::stod(token));
            }
            else {
                double b = valueStack.top();
                valueStack.pop();
                double a = valueStack.top();
                valueStack.pop();

                switch (token[0]) {
                case '+': valueStack.push(calculator.add(a, b)); break;
                case '-': valueStack.push(calculator.subtract(a, b)); break;
                case '*': valueStack.push(calculator.multiply(a, b)); break;
                case '/': valueStack.push(calculator.divide(a, b)); break;
                case '^': valueStack.push(calculator.exponent(a, b)); break;
				case 't': valueStack.push(calculator.tip(a, b)); break;
                case 'd': valueStack.push(calculator.discount(a, b)); break;
                default: throw std::runtime_error("Unknown operator");
                }
            }
        }

        return valueStack.top();
    }

    double EvaluateExpression(const std::string& infix) {
        std::string postfix = InfixToPostfix(infix);
        return EvaluatePostfix(postfix);
    }
};



class CalculatorApp : public wxApp {
public:
    virtual bool OnInit() {
        CalculatorFrame* frame = new CalculatorFrame();
        frame->Show();
        return true;
    }
};




wxIMPLEMENT_APP(CalculatorApp);
