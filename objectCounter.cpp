#include <iostream>
using namespace std;

class ObjectCounter {
private:
    static int count; // Static variable to count the number of objects

public:
    // Constructor: Increment count when an object is created
    ObjectCounter() {
        count++;
        cout << "Object created. Current object count: " << count << endl;
    }

    // Destructor: Decrement count when an object is destroyed
    ~ObjectCounter() {
        count--;
        cout << "Object destroyed. Current object count: " << count << endl;
    }

    // Static function to get the current object count
    static int getObjectCount() {
        return count;
    }
};

// Initialize the static variable
int ObjectCounter::count = 0;

int main() {
    cout << "Main Block Start\n";

    // Create objects in the main block
    ObjectCounter obj1;
    ObjectCounter obj2;

    {
        cout << "\nNested Block Start\n";

        // Create objects in the nested block
        ObjectCounter obj3;
        ObjectCounter obj4;

        cout << "\nNested Block End\n";
    }

    // After the nested block, obj3 and obj4 are destroyed

    cout << "\nMain Block End\n";

    return 0;
}
