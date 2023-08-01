#include <iostream>
#include <string>
using namespace std;


class HammingTrans
{
private:
    int hamcode[7];
public:
    HammingTrans(){
        for (int i = 0; i < 7; i++){
            hamcode[i] = 0;
        }
    }
    
    void convertdec(int num){
        if(num >= 8){
            num = num - 8;
            hamcode[2] = 1;
        }
        if(num >= 4){
            num = num - 4;
            hamcode[4] = 1;
        }
        if(num >= 2){
            num = num - 2;
            hamcode[5] = 1;
        }
        if(num >= 1){
            num = num - 1;
            hamcode[6] = 1;
        }
        hamcode[0] = (hamcode[2]+hamcode[4]+hamcode[6])%2;
        hamcode[1] = (hamcode[2]+hamcode[5]+hamcode[6])%2;
        hamcode[3] = (hamcode[4]+hamcode[5]+hamcode[6])%2;
    }

    void reset(){
        for (int i = 0; i < 7; i++){
            hamcode[i] = 0;
        }
    }

    void print(int num){
        cout << "\nYour original decimal number: " << num << endl;
        cout << "Your Encoded decimal: ";
        for (int i = 0; i < 7; i++){
            cout << hamcode[i];
        }
    }
};


int main() {
    int num1 = 12;
    int num2 = 7;
    int num3 = 12;
    int num4 = 2;
    int num5 = 6;
    HammingTrans H;
    H.convertdec(num1);
    H.print(num1);
    H.reset();
    /*
    H.convertdec(num2);
    H.print(num2);
    H.reset();

    H.convertdec(num3);
    H.print(num3);
    H.reset();

    H.convertdec(num4);
    H.print(num4);
    H.reset();

    H.convertdec(num5);
    H.print(num5);
    H.reset();
    */
    return 0;
}
