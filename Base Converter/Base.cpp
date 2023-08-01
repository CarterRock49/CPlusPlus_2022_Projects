#include <iostream>

using namespace std;

int main() {
    string output = "";
    int num;
    int base;
    string hexa = "0123456789ABCDEF";
    cout << "Please enter an integer: ";
    cin >> num;
    cout << "\nPlease enter a base integer: ";
    cin >> base;
    while (num > 0)
    {
        output = hexa[num%base] + output;
        num /= base;
    }
    cout << "\nYour output is " + output + "\n";
    system("pause");
    return 0;
}
