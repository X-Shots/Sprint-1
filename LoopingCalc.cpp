#include <iostream>
using namespace std;
#include <cmath>

//Methods for the FourFunction class
class MathFunction{
    public:
        double add(double a, double b){
            return a + b;
        }
        double subtract(double a, double b){
            return a - b;
        }
        double multiply(double a, double b){
            return a * b;
        }
        double divide(double a, double b){
            return a / b;
        }
        
        double exponent(double a, double b){
            return pow(a,b);
        }
        double squareRoot(double ans){
             return sqrt(ans);
        }
        double log(double ans){
            return log(ans);
        }
        double log10(double ans){
            return log10(ans);
        }
        double sine(double ans){
            return sin(ans);
        }
        double cosine(double ans){
            return cos(ans);
        }
        double tangent(double ans){
            return tan(ans);
        }
        double secant(double ans){
            return 1 / cos(ans);
        }
        double cosecant(double ans){
            return 1 / sin(ans);
        }
        double cotangent(double ans){
            return 1 / tan(ans);
        }
        // double pi = 2 * acos(0.0);
        double remainder(double a, double b){
            return remainder(a, b);
        }
        double tithing(double ans){
            return ans / 10;
        }
        double tip(double a, double b){
            return (a / 100) * b;
        }
        double discount(double a, double b){
            return a - (a * (b / 100));
        }
};

//Main Method
int main() {         
    //Variables for User Input and Calculations
    int UserInput;
    double a;
    double b;
    double ans = 1;
    //Initialize an object of the FourFunction class named "calc"
    MathFunction calc;
    //Welcome text
    cout << "Welcome to the Four Function Calculator! ";
    cout << "\n";
    //User Input for starting value
    cout << "What number would you like to start with? ";
    cin >> ans;
    cout << "\n";
    //Loops to allow the user to make as many calculations as they want using the FourFunction class
    do{
        //displays the current value and asks which function to use
        cout << "The current number is: " << ans << "\n\n";
        cout << "The four functions are: ";
        cout << "\n\t1. Addition\n\t2. Subtraction\n\t3. Multiplication\n\t4. Division\n\t5. Exponent\n\t6. Square Root\n\t7. Log\n\t8. Log 10\n\t9. sin\n\t10. cos\n\t11. tan\n\t12. sec\n\t13. csc\n\t14. cot\n\t15. PI\n\t16. Remainder\n\t17. Tithing\n\t18. Calculate tip\n\t19. Discount";
        cout << "\nWhat is the number of the function you would like to use?(Type 0 to quit) ";
        cin >>   UserInput;
        cout << "\n";
        // Asks the user for the second number and calculates the answer based on the user input
        if (UserInput == 1){
            cout<< "How much would you like to add? ";
            cin >> b;
            ans = calc.add(ans,b);
        }
        else if (UserInput == 2){
            cout << "How much would you like to subtract? ";
            cin >> b;
            ans = calc.subtract(ans,b);
        }
        else if(UserInput == 3){
            cout << "How much would you like to multiply by? ";
            cin >> b;
            ans = calc.multiply(ans,b);
        }
        else if(UserInput == 4){
            cout << "How much would you like to divide by? ";
            cin >> b;
            ans = calc.divide(ans,b);
        }
        else if(UserInput == 5){
            cout << "What is the exponent? ";
            cin >> b;
            ans = calc.exponent(ans,b);
        }
        else if(UserInput == 6){
            ans = calc.squareRoot(ans);
        }
        else if(UserInput == 7){
            ans = calc.log(ans);
        }
        else if(UserInput == 8){
            ans = calc.log10(ans);
        }
        else if (UserInput == 9){
            ans = calc.sine(ans);
        }
        else if(UserInput == 10){
            ans = calc.cosine(ans);
        }
        else if(UserInput == 11){
            ans = calc.tangent(ans);
        }
        else if(UserInput == 12){
            ans = calc.secant(ans);
        }
        else if(UserInput == 13){
            ans = calc.cosecant(ans);
        }
        else if(UserInput == 14){
            ans = calc.cotangent(ans);
        }
        // else if(UserInput == 15){
        //     ans = calc.pi()
        // }
        else if(UserInput == 16){
            ans = calc.remainder(ans, b);
        }

        else if(UserInput == 17){
            ans = calc.tithing(ans);
        }
        else if(UserInput == 18){
            cout << "What percent do you want to tip? ";
            cin >> b;
            ans = calc.tip(ans,b);
        }
        else if(UserInput == 19){
            cout << "What is the percentage of the discount? ";
            cin >> b;
            ans = calc.discount(ans,b);
        }

        // Input for user to exit program
        else if(UserInput == 0){
            cout << "Goodbye!";
        }
        //Error message for invalid input(Program loops back to allow the user to continue calculating)
        else{
            cout <<"Invalid input - please try again!";
        }
        cout << "\n";
    }while(UserInput != 0);
    
    return 0;
}

