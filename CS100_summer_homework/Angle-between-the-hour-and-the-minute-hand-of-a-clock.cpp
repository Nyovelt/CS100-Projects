#include "stdio.h"
#include "iostream"
using namespace std;
char op;
int hour,minute;

int main(){
	cout << "What time is it?";
    scanf("%d %s %d",&hour, &op, &minute);
    if( op == ':'){
        cout << fab((*float)hour/24 - 0.5)
    }

}