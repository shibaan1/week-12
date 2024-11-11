#include <iostream>
#include <cmath> // For sqrt() function
using namespace std;

class Triangle {
private:
    double base, height; // Private instance variables for base and height

public:
    // Constructor to initialize base and height
    Triangle(double b, double h) {
        base = b;
        height = h;
    }

    // Function to calculate the length of the hypotenuse
    double hypo() {
        return sqrt(base * base + height * height); // Pythagoras' theorem
    }

    // Function to calculate the area of the triangle
    double area() {
        return 0.5 * base * height; // Area of a right triangle: (1/2) * base * height
    }
};

int main() {
    double base, height;

    // Input the base and height of the triangle
    cout << "Enter the base of the triangle: ";
    cin >> base;
    cout << "Enter the height of the triangle: ";
    cin >> height;

    // Create an object of Triangle class
    Triangle t(base, height);

    // Display the hypotenuse and area
    cout << "The hypotenuse of the triangle is: " << t.hypo() << endl;
    cout << "The area of the triangle is: " << t.area() << endl;

    return 0;
}
