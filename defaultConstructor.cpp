#include <iostream>
using namespace std;

class MyClass {
private:
    int number;
    string name;

public:
    // Default constructor to initialize data members
    MyClass() {
        number = 0;     // Initializing number to 0
        name = "Unknown"; // Initializing name to "Unknown"
    }

    // Member function to display the values of data members
    void display() {
        cout << "Number: " << number << endl;
        cout << "Name: " << name << endl;
    }
};

int main() {
    // Creating an object of MyClass, which automatically calls the default constructor
    MyClass obj;

    // Calling the member function to display the values
    obj.display();

    return 0;
}
