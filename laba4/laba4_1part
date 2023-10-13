#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    char stroka[300];
    cout << "Write down the string :" << endl;
    cin.getline(stroka, 300);
    cout << stroka << endl;
    int i,j,a;
    for ( i = 0; stroka[i] != '\0'; i++) {
        char* word = stroka+i;


        bool isVerificationPassed = true;
        for (; stroka[i+1] != ' '; i++) {
            isVerificationPassed = isVerificationPassed && stroka[i] < stroka[i + 1];
        }
         if(isVerificationPassed){
             cout << isVerificationPassed <<endl;
             stroka[i+1]='\0';
             cout << word <<endl;

             break;
         }

         ++i;
    }



    return 0;
}
