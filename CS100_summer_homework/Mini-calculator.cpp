//#include "iostream"
#include "stdio.h"
//using namespace std;

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

void Program(){
        //cout << "Enter the arithmetic expression to be evaluated (e.g. 5 + 6):" << endl;
        printf("Enter the arithmetic expression to be evaluated (e.g. 5 + 6):\n");
        scanf("%f %c %f", &var1, &op, &var2);
        printf("%f\n", Calc());
        getchar();
        //cout << endl << "Did you want to enter another expression? (Enter 'y' or 'n'):";
        printf("Did you want to enter another expression? (Enter 'y' or 'n'): ");
        char a = getchar();
        if( a == 'y'){
                Program();
        }
        else if( a == 'n'){
        }
        
}

int main(){
        Program();
}