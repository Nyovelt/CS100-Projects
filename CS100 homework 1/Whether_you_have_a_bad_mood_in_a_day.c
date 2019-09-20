#include <stdio.h>
long int times;
int hour1, hour2, minute1, minute2, hour, minute;
char a, b, c, d;
float mood = 100;
int flag = 1;
int main()
{
    hour = 8;
    minute = 0;
    printf("How many lectures today?\n");
    scanf("%ld", &times);
    //printf("times = %d\n", times);
    for (long int i = 0; i < times; i++)
    {
        //printf("%d\n", i);
        controller();
        scanf("%d:%d-%d:%d", &hour1, &minute1, &hour2, &minute2);
        //printf("%d:%d-%d:%d\n", hour1, minute1, hour2, minute2);
        int time;
        time = DeltaTime(hour, minute, hour1, minute1);
        //printf("time:%d\n", time);
        mood += time * 0.5;
        controller(); //睡觉
        //printf("mood:%.1f\n", mood);
        time = DeltaTime(hour1, minute1, hour2, minute2);
        //printf("time:%d\n", time);

        if (time > 60)
        {
            mood -= (60 * 0.4 + (time - 60) * 0.8);
        }
        else
        {
            mood -= 0.4 * time;
        }
        controller();
        //printf("mood:%.1f\n", mood);
        hour = hour2;
        minute = minute2;
    }
    int time;
    time = DeltaTime(hour, minute, 22, 00);
    //printf("time:%d\n", time);
    mood += time * 0.5;

    controller();
    if (flag > 0)
        printf("His mood level is %.1f at the end of the day.", mood);
}
void controller()
{
    if (mood > 100)
        mood = 100;
    if (mood <= 0 && flag > 0)
    {
        printf("Gezi Wang has been sent to hospital.\n");
        flag = 0;
    }
}
int DeltaTime(int a, int b, int c, int d)
{
    //printf("a:%d,b:%d,c:%d,d:%d\n", a, b, c, d);
    if ((d - b) < 0)
    {

        return (d + 60 - b + (c - a - 1) * 60);
    }
    else
    {
        return (d - b) + (c - a) * 60;
    }
}