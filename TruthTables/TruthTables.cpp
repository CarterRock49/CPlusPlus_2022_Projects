#include <iostream>

using namespace std;

//checks problem questions for true or false for a specfic requested row
bool logicstatments(int problemnum, bool a, bool b, bool c){
    switch (problemnum)
    {
    case 0:
        return (a && b) || (a && c);
        break;
    case 1:
        return (a && c) && (b && !c);
        break;
    case 2:
        return (a || b) && !(b || c);
        break;
    case 3:
        return (a || (b && c)) && (!a && !b);
        break;
    case 4:
        return ((b && c) || (c && a)) && (!(a || b) && c);
        break;
    default:
        break;
    }
}

int main(){
    bool loggates[8][3]; //array to hold all combinations of a b and c
    int iterator = 0;
    bool answers[8]; //holds the answers that the above function returns
    for (int i = 0; i < 2; i++)//populates the array with all combinations of a b and c
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                loggates[iterator][0] = i;
                loggates[iterator][1] = j;
                loggates[iterator][2] = k;
                iterator++;
            }   
        }
    }
    
    cout << "This is the table with all possible combinations.\nA B C\n";
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << loggates[i][j] << " ";
        }
        cout << "\n";
    }

    iterator = 0;

    for (int i = 0; i < 5; i++)//this outer loop is to go through each question given
    {
        cout << "\nProblem " << iterator+1 << "\n";
        cout << "A B C Answer\n";
        for (int i = 0; i < 8; i++)
            {
                answers[i] = logicstatments(iterator, loggates[i][0], loggates[i][1], loggates[i][2]);
                cout << loggates[i][0] << " " << loggates[i][1] << " " << loggates[i][2] << " " << answers[i] << "\n";
            }
        iterator++;
    }
    return 0;
}