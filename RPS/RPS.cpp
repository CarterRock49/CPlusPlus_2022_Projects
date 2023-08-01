#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


class RPS
{
private:
    int a[9] = {1,1,1,2,2,2,3,3,3}; //1 = rock, 2 = paper, 3 = scissors
    int comp;
public:
    void listupdate(int num){
        for (int i = 9; i >= 0; i--){
            if(!(i == 0)){
                a[i] = a[i-1];
            } else {
                a[i] = num;
            }
        }
    }

    void resolve(string userchoice){
        comp = rand() % 9 + 1;
        if(userchoice == "ROCK"){
            if(a[comp] == 1){
                cout << "Computer plays Rock: Draw";
            } else if (a[comp] == 2){
                cout << "Computer plays Paper: Lose";
            } else {
                cout << "Computer plays Scissors: Win";
            }
            listupdate(2);
        } else if (userchoice == "PAPER"){
            if(a[comp] == 1){
                cout << "Computer plays Rock: Win";
            } else if (a[comp] == 2){
                cout << "Computer plays Paper: Draw";
            } else {
                cout << "Computer plays Scissors: Lose";
            }
            listupdate(3);
        } else if (userchoice == "SCISSORS"){
            if(a[comp] == 1){
                cout << "Computer plays Rock: Lose";
            } else if (a[comp] == 2){
                cout << "Computer plays Paper: Win";
            } else {
                cout << "Computer plays Scissors: Draw";
            }
            listupdate(1);
        } else {
            cout << "\nError unaccounted for input";
        }
    }
};

int main(){
    string userchoice;
    RPS r1;
    while (true)
    {
        cout << "\nPlease enter Rock, Paper, or Scissors: ";
        cin >> userchoice;
        transform(userchoice.begin(), userchoice.end(), userchoice.begin(), ::toupper);
        r1.resolve(userchoice);
    }
    
}