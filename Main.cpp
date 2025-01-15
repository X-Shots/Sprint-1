#include <iostream>
using namespace std;
#include <cmath>

//Methods for the FourFunction class
class FourFunction{
    public:
        int add(int a, int b){
            return a + b;
        }
        int subtract(int a, int b){
            return a - b;
        }
        int multiply(int a, int b){
            return a * b;
        }
        int divide(int a, int b){
            return a / b;
        }
        int exponent(int a){
            return exp(a);
        }
        int squareRoot(int a){
            return sqrt(a);
        }
};

//Main Method
int main() {         
    //Variables for User Input and Calculations
    int UserInput;
    int a;
    int b;
    int ans = 1;
    //Initialize an object of the FourFunction class named "calc"
    FourFunction calc;
    //User Input for the calculation
    cout << "Welcome to the Four Function Calculator!\n\nThe Four Functions are:\n ";
    cout << "\n\t1. Addition\n\t2. Subtraction\n\t3. Multiplication\n\t4. Division\n\t5. Squared\n\t6. Square Root";
    cout << "\nWhat is the number of the function you would like to use?";
    cin >>   UserInput;
    cout <<"\nWhat is the first number? ";
    cin >> a;
    cout <<"\nWhat is the seccond number? ";
    cin >> b;
    cout << "\nThe answer is: ";
    //Calculate the answer based on the user input
    if (UserInput == 1){
        ans = calc.add(a,b);
    }
    else if (UserInput == 2){
        ans = calc.subtract(a,b);
    }
    else if(UserInput == 3){
        ans = calc.multiply(a,b);
    }
    else if(UserInput == 4){
        ans = calc.divide(a,b);
    }
    else if(UserInput == 5){
        ans = calc.exponent(a);
    }
    else if(UserInput == 6){
        ans = calc.squareRoot(a);
    }
    else{
        cout <<"Invalid input please try again!";
    }
    //Print the calculated answer
    cout << ans;
    cout << "\n";
    return 0;
}

