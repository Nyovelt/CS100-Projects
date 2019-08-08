#include "iostream"
#include "stdio.h"
using namespace std;

float var1, var2;
char op;

double Calc(){
        if( op == '+'){
                return var1 + var2;
        }
        else if( op == '-'){
                return var1 - var2;
        }
        else if( op == '*'){
                return var1 * var2;
        }
        else if( op == '/'){
                return var1 / var2;
        }
}

int main(){
        
        cout << "Enter the arithmetic expression to be evaluated (e.g. 5 + 6):" << endl;
        scanf("%f %c %f", &var1, &op, &var2);
        printf("%f", Calc());
        cout << endl << "Did you want to enter another expression? (Enter 'y' or 'n'):";
        /* while (getchar() != 'n'){
            
        }*/
}