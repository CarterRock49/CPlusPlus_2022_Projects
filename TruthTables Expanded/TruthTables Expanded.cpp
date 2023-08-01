#include <iostream>

using namespace std;
class advancedgates{
public:
    bool NOR(bool x, bool y){
        if (x == false && y == false){
            return true;
        } else {
            return false;
        }
    }
    bool XOR(bool x, bool y){
        if (x == y){
            return false;
        } else {
            return true;
        }
    }
    bool IMPLIES(bool x, bool y){
        if (x == true && y == false){
            return false;
        } else {
            return true;
        }
    }
    bool NAND(bool x, bool y){
        if(x == true && y == true){
            return false;
        } else {
            return true;
        }
    }
    bool XNOR(bool x, bool y){
        if (x == y){
            return true;
        } else {
            return false;
        }
    }
};

//checks problem questions for true or false for a specfic requested row
bool logicstatments(int problemnum, bool a, bool b, bool c){
    bool placeholder1;
    bool placeholder2;
    advancedgates G;
    switch (problemnum)
    {
    case 0:
        placeholder1 = !(G.XOR(a, c));
        return G.NAND(placeholder1, (b || a));
        break;
    case 1:
        placeholder1 = G.IMPLIES(b, c);
        placeholder2 = G.NOR(a, b);
        return G.NAND(placeholder1, placeholder2);
        break;
    case 2:
        placeholder1 = G.XOR(a, b);
        placeholder2 = G.XNOR(b, c);
        return G.IMPLIES(placeholder1, placeholder2);
        break;
    case 3:
        placeholder1 = G.IMPLIES(a ,b);
        return G.IMPLIES(placeholder1, !c);
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

    for (int i = 0; i < 1; i++)//this outer loop is to go through each question given
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