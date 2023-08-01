#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class CodeCracker
{
private:
    const int ASCII = 65;
    char alphabet[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    string output = "";
    int shiftcounter = 1;
public:
    void shift(string s){
        cout << "Original string: " << s << endl;
        for (int i = 0; i < 26; i++)
        {
            for (int j = 0; j < s.length(); j++)
            {
                if(s.at(j) == ' '){
                    output.push_back(' ');
                } else {
                    for (int l = 0; l < 26; l++)
                    {
                        if(s.at(j) == alphabet[l]){
                            output.push_back(alphabet[(l+shiftcounter)%26]);
                        }
                    }
                }
            }
            cout << "\n" << output;
            output.clear();
            shiftcounter++;
        }
    }
};



int main(){
    string s1 = "Wkh qljkw lv orqj dqg zh doo suhwhqg wr vohhs";
    string s2 = "F xrfqq hnyd mfx gjjs inxhtajwji zsijw ymj gtbqnsl fqqjd";
    string s3 = "Yx Drebcnki dro vslbkbi gsvv lo exuxygklvo";
    string s4 = "Epht bsf opu bmmpxfe jo uif eph qbsl";
    string s5 = "Lo cebo dy nbsxu iyeb Yfkvdsxo";

    transform(s1.begin(), s1.end(), s1.begin(), ::toupper);
    transform(s2.begin(), s2.end(), s2.begin(), ::toupper);
    transform(s3.begin(), s3.end(), s3.begin(), ::toupper);
    transform(s4.begin(), s4.end(), s4.begin(), ::toupper);
    transform(s5.begin(), s5.end(), s5.begin(), ::toupper);
    CodeCracker c;
    c.shift(s5);
}