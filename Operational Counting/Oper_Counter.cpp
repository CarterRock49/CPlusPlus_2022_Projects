#include <iostream>

using namespace std;

int counting(int input, int& count){
    int total = 0;
    for (int i = 1; i < input+1; i++)
    {
        total = i + total;
        count++; // this loop counts one operation per loop unless you count the iterator increasing but the assignment felt vague in that regard.
    }
    return total;
}
int formula(int input){
    return (input*(input+1))/2; //this formula always uses three operations.
}
int main(){
    int input = 0;
    int output = 0;
    int count = 0;
    cout << "Please enter a number above 0: ";
    cin >> input;

    output = counting(input, count);
    cout << "\nYour answer via for-loop: " << output << ", The number of operations for this loop was " << count;

    output = formula(input);
    cout << "\nYour answer via formula: " << output << ", The number of operations for this formula is always 3\n";
    system("pause");
}