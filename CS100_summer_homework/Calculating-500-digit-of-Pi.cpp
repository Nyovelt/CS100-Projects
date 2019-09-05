#include "stdio.h"

long int a[17000] = {};
int nines = 0, predigit = 0, q, x;
int flag = 0;

void wash()
{
    for (int i = 0; i < 16999; i++)
    {
        a[i] = 2;
    }
    //printf("wash done\n");
}

void Program(int m)
{
    q = 0;
    for (int i = 16999; i >= 0; i--)
    {
        x = 10 * a[i] + q * (i + 1);
        a[i] = x % (2 * i + 1);
        q = x / (2 * i + 1);
    }
    a[0] = q % 10;
    q = q / 10;
    //printf("nines = %d", nines);
    //printf("q=%d\n", q);

    if (q == 9)
    {
        nines++;
    }
    else if (q == 10)
    {
        printf("%d", predigit + 1);
        for (int j = 1; j <= nines; j++)
        {
            printf("0");

        }
            predigit = 0;
            nines = 0;
    }
    else
    {
        //printf("1");
        if (m >= 1)
        {
            printf("%d", predigit);
        }
        predigit = q;
        if (nines != 0)
        {
            for (int k = 1; k <= nines; k++)
            {
                printf("9");
            }
            nines = 0;
        }
    }
}

int main()
{
    wash();
    for (int i = 0; i <= 5000; i++)
    {
        //printf("the %d time", i);
        Program(i);
        if (i == 1)
            printf(".");
    }
    //printf("%d\n", predigit);
}