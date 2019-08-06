using namespace std;
#include "iostream"

int main(){
    long long number=1 ,firstNumber = 0 ,lastNumber = 1;
    cout<<"The next number is 0" << endl;

    for ( int i=0; i<90; i++){
        cout<<"The next number is " << number << endl;
        number = firstNumber + lastNumber;
        firstNumber = lastNumber;
        lastNumber = number;
    }
}