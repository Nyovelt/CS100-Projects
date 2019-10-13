#include "stdio.h"
#include "stdlib.h"
int i = 0;
float average(float *a);

int main()
{
    float *array = NULL;
    int maxn = 5;
    array = (float *)malloc(5 * sizeof(float));
    memset(array, 0, 5 * sizeof(float));
    printf("Please type scores to be calculated:\n");
    while (1)
    {
        float score;

        if (i == maxn)
        {
            //printf("point1\n");

            if (i >= 5)
            {
                float *temp;
                array = (float *)realloc(array, (2 * i) * sizeof(float));
                printf("(resize) from %d to %d\n", i, 2 * i);
                maxn = 2 * i;
            }
        }
        scanf("%f", &score);
        //printf("%f\n",score);
        if (score < 0)
        {
            //printf("break\n");
            break;
        }
        array[i] = score;
        //printf("a[%d]=%f\n",i,array[i]);
        i += 1;
    }

    printf("Average score: %.2f\n", average(array));

    //float n = average(array);
    //printf("%f",n);
    free(array);
}

float average(float *a)
{
    for (int j = 0; j < i; j++)
    {
        //printf("a[%d]=%f", j, a[j]);
    }
    float averageOfArray = 0;
    int numOfArray = 0;
    int n;
    n = i;
    //printf("array has %d elements \n", n);
    for (int i = 0; i < n; i++)
    {
        averageOfArray += a[i];
    }
    //printf("averageofarray is %f,numofarray is %d", averageOfArray, numOfArray);
    averageOfArray /= n;
    //printf("%f", averageOfArray);
    if (n == 0)
    {
        return 0;
    }
    else
    {
        return averageOfArray;
    }
}