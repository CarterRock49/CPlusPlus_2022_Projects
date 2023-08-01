#include <iostream>
#include <vector>
using namespace std;

bool IMPLIES(bool x, bool y){
    if (x == true && y == false){
        return false;
    } else {
        return true;
    }
}

int main(){
    bool prop1;
    bool prop2;
    bool prop3;
    bool con;
    vector<vector<bool>> propgates;
    vector<bool> row;
    for (int i = 0; i < 2; i++)//populates the array with all combinations of a b and c
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                for (int l = 0; l < 2; l++)
                {
                    row.push_back(i);
                    row.push_back(j);
                    row.push_back(k);
                    row.push_back(l);
                    propgates.push_back(row);
                    row.clear();
                }
            }   
        }
    }
    
    cout << "This is the table with all possible combinations.\nA B C D\n";
    for (int i = 0; i < propgates.size(); i++)
    {
        for (int j = 0; j < propgates[i].size(); j++)
        {
            cout << propgates[i][j] << " ";
        }
        cout << "\n";
    }
    
    cout << "Rocket\tAstro\tH_Trained\tEducated\tProp1\tProp2\tProp3\tConclusion\tAnswer\n";
    cout << "R\tA\tT\tE\t1\t2\t3\tC\tAnswer\n";
    for (int i = 0; i < propgates.size(); i++)
    {
        for (int j = 0; j < propgates[i].size(); j++)
        {
            cout << propgates[i][j] << "\t";
        }
        prop1 = IMPLIES(propgates[i][0], propgates[i][1]);
        prop2 = IMPLIES(propgates[i][1], propgates[i][2]);
        prop3 = IMPLIES(propgates[i][2], propgates[i][3]);
        con = IMPLIES(propgates[i][3], propgates[i][0]);
        cout << prop1 << "\t";//if someone has a rocket, that impiles they're an astronaut
        cout << prop2 << "\t";//if someone is an astronaut, that impiles they're highly trained
        cout << prop3 << "\t";//if someone is highly trained, that impiles they're educated
        cout << con << "\t";//A person is educated, that impiles they have a rocket
        if(prop1 && prop2 && prop3 && !con){
            cout << 0 << " INVAILD";
        } else {
            cout << 1;
        }
        cout << "\n";
    }
    return 0;
    
}