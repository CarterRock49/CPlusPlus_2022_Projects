#include <iostream>
#include <string>
using namespace std;

class HammingRec
{
private:
    int code[7];
    int p0;
    int p1;
    int p3;
    int total = 0;
public:
    void setup(string input){
        cout << "Your code is " << input << endl;
        for (int i = 0; i < 7; i++)
        {
            code[i] = int(input[i] - 48);
        }
        p0 = (code[0] + code[2] + code[4] + code[6])%2;
        p1 = (code[1] + code[2] + code[5] + code[6])%2;
        p3 = (code[3] + code[4] + code[5] + code[6])%2;
    }

    bool checkNcorrect(){
        if(p0 == 1){
            total = total + 1;
        }
        if(p1 == 1){
            total = total + 2;
        }
        if(p3 == 1){
            total = total + 4;
        }
        if(total == 0){
            cout << "There is no error in the given code\n";
            return false;
        } else {
            cout << "There is an error on bit " << total << endl;
            if(code[total-1] == 0){
                code[total-1] = 1;
            } else {
                code[total-1] = 0;
            }
            return true;
        }
    }

    void print(bool error){
        if(error){
            cout << "The corrected code is as follows: ";
            for(int i = 0; i < 7; i++){
                cout << code[i];
            }
        } else {
            cout << "The code remains as follows: ";
            for(int i = 0; i < 7; i++){
                cout << code[i];
            }
        }

        total = 0;
        if(code[2] == 1){
            total = total + 8;
        }
        if(code[4] == 1){
            total = total + 4;
        }
        if(code[5] == 1){
            total = total + 2;
        }
        if(code[6] == 1){
            total = total + 1;
        }
        cout << "\nThe decimal form of the message is: " << total << endl;
        total = 0;
    }
};



int main(){
    bool error;
    string i1 = "0111101";
    string i2 = "0010111";
    string i3 = "1010101";
    string i4 = "1001001";
    string i5 = "0110011";
    HammingRec h;
    h.setup(i1);
    error = h.checkNcorrect();
    h.print(error);
    /*
    h.setup(i2);
    error = h.checkNcorrect();
    h.print(error);
    
    h.setup(i3);
    error = h.checkNcorrect();
    h.print(error);
    
    h.setup(i4);
    error = h.checkNcorrect();
    h.print(error);
    
    h.setup(i5);
    error = h.checkNcorrect();
    h.print(error);
    */
}