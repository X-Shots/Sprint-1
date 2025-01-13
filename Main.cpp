#include <iostream>
using namespace std;
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
};


int main() {         
    int UserInput;
    int a;
    int b;
    int ans = 1;
    FourFunction calc;
    cout << "Welcome to the Four Function Calculator!\n\nThe Four Functions are:\n ";
    cout << "\n\t1. Addition\n\t2. Subtraction\n\t3. Multiplication\n\t4. Division";
    cout << "\nWhat is the number of the function you would like to use?";
    cin >>   UserInput;
    cout <<"\nWhat is the first number? ";
    cin >> a;
    cout <<"\nWhat is the seccond number? ";
    cin >> b;
    cout << "\nThe answer is: ";
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
    else{
        cout <<"Invalid input please try again!";
    }
    cout << ans;
    cout << "\n";
    return 0;
}

