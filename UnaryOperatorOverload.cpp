// Overloading unary operator "++" both when used as prefix and postfix

#include <iostream>
using namespace std;

class Count {
   private:
    int value;

   public:

    // Constructor to initialize count to 5
    Count() : value(5) {}


    // Overload ++ when used as prefix
    void operator ++ () {
        ++value;
    }


    // Overload ++ when used as postfix
    void operator ++ (int) {
        value++;
    }

    void display() {
        cout << "Value of c1 variable: " << value << endl;
    }
};

int main() {
    Count c1;

    // Call the "void operator ++ (int)" function
    c1++;
    c1.display();

    // Call the "void operator ++ ()" function
    ++c1;

    c1.display();
    return 0;
}

/*
OP:
Value of c1 variable: 6
Value of c1 variable: 7
*/