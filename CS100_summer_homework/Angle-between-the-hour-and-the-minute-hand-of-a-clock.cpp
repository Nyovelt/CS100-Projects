#include "stdio.h"
#include "iostream"
#include "math.h"
using namespace std;
char op;
float hour, minute;
float minuteHand, hourHand;

int main()
{
    cout << "What time is it?";
    scanf("%f %c %f", &hour, &op, &minute);

    /*if (op == ':')
    {
        cout << hour << ":" << minute << endl;
    }*/

    if( hour > 12){
        hour -= 12;
    }

    minuteHand = (minute / 60) * 360;
    hourHand = ((hour / 12)* 360+(minute / 60)*30);
    //cout << hourHand << ":" << minuteHand << endl;
    float degrees = fabs(minuteHand - hourHand);
    //cout << degrees << endl;

    if(degrees > 180){
        degrees = 360 - degrees;
    }
    //cout << degrees << endl;

    printf("The angle between the hands is %.1f degrees\n", degrees);
    getchar();
}