#include <stdio.h>
float max, min;
int main()
{
    printf("Please type number of inputs: ");
    int n;
    scanf("%d", &n);
    //printf("%d", n);

    getchar();

    scanf("%f", &max);
    min = max;
    for (int i = 0; i < n - 1; i++)
    {
        float num;
        scanf("%f", &num);

        if (num > max)
            max = num;
        if (num < min)
            min = num;
    }
    printf("Max value: %.1f\n", max);
    printf("Min value: %.1f\n", min);
}