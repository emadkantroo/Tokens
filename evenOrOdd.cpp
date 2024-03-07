#include <iostream>
using namespace std;

// Function to check if a number is even or odd
void checkEvenOdd(int n) {
    if (n & 1) // Bitwise AND operation with 1
        cout << n << " is odd" << endl;
    else
        cout << n << " is even" << endl;
}

int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;
    checkEvenOdd(number);
    return 0;
}
