#include <iostream>
using namespace std;

class Calculator {
private:
    double num1, num2, num3, num4; // Four data members for arithmetic operations

public:
    // Default constructor (sets default values)
    Calculator() {
        num1 = 0;
        num2 = 0;
        num3 = 0;
        num4 = 0;
    }

    // Parameterized constructor to initialize the four data members
    Calculator(double a, double b, double c, double d) {
        num1 = a;
        num2 = b;
        num3 = c;
        num4 = d;
    }

    // Function to perform addition
    double add() {
        return num1 + num2 + num3 + num4;
    }

    // Function to perform subtraction
    double subtract() {
        return num1 - num2 - num3 - num4;
    }

    // Function to perform multiplication
    double multiply() {
        return num1 * num2 * num3 * num4;
    }

    // Function to perform division (handling division by zero)
    double divide() {
        if (num2 == 0 || num3 == 0 || num4 == 0) {
            cout << "Error: Division by zero!" << endl;
            return 0; // Return 0 for division by zero
        }
        return num1 / num2 / num3 / num4;
    }

    // Function to display the values of data members
    void displayValues() {
        cout << "Number 1: " << num1 << endl;
        cout << "Number 2: " << num2 << endl;
        cout << "Number 3: " << num3 << endl;
        cout << "Number 4: " << num4 << endl;
    }
};

int main() {
    // Initialize the calculator with four values using the parameterized constructor
    Calculator calc(10.5, 5.2, 2.5, 1.5);

    // Display the values of the data members
    cout << "Values in the calculator:" << endl;
    calc.displayValues();

    // Perform arithmetic operations and display the results
    cout << "\nAddition of values: " << calc.add() << endl;
    cout << "Subtraction of values: " << calc.subtract() << endl;
    cout << "Multiplication of values: " << calc.multiply() << endl;
    cout << "Division of values: " << calc.divide() << endl;

    return 0;
}
