#include <iostream>

using namespace std;

int sort(int list[]){
    int operations = 0;
    for (int i = 1; i < 10; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if(list[j] < list[j + 1]){
                int temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
                operations += 4;
            } else {
                operations++;
            }
        }
        
    }
    return operations;
}

int main(){
    int list1[10] = {1,3,7,5,2,4,6,8,9,10};
    int list2[10] = {10,9,8,7,6,5,4,3,2,1};
    int list3[10] = {1,10,2,9,3,8,4,7,5,6};

    int operations = 0;
    operations = sort(list1);
    cout << "Sorted List: ( ";
    for (int i = 0; i < 10; i++){
        cout << list1[i] << " "; 
    }
    cout << ") " << operations << " Actions Performed.\n\n";

    operations = sort(list2);
    cout << "Sorted List: ( ";
    for (int i = 0; i < 10; i++){
        cout << list2[i] << " "; 
    }
    cout << ") " << operations << " Actions Performed.\n\n";

    operations = sort(list3);
    cout << "Sorted List: ( ";
    for (int i = 0; i < 10; i++){
        cout << list3[i] << " "; 
    }
    cout << ") " << operations << " Actions Performed.\n\n";

    system("PAUSE");
}



