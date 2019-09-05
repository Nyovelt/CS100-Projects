//using namespace std;
//#include "iostream"
#include "stdio.h"

int main()
{
    long long int number = 1, firstNumber = 0, lastNumber = 1;
    //cout<<"The next number is 0" << endl;
    printf("The next number is 0 \n");

    for ( int i=1; i<89; i++){
        printf("The next number is %lld\n", number);
        //cout<<"The next number is " << number << endl;
        number = firstNumber + lastNumber;
        firstNumber = lastNumber;
        lastNumber = number;
    }

    printf("The next number is %lld", number);
}

