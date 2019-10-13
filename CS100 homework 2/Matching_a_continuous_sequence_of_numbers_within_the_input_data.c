#include "stdio.h"
#include "math.h"
#include "stdlib.h"

int main()
{
    int MAXN = 5; //creat dynamic arrays
    int *A = malloc(sizeof(int) * MAXN);
    memset(A, 0, sizeof(int) * MAXN);
    int *B = malloc(sizeof(int) * MAXN);
    memset(B, 0, sizeof(int) * MAXN);

    int i = 0;
    printf("Please input the set A:\n"); //get input array A
    while (1)
    {
        int temp = 0;
        scanf("%d", &temp);
        getchar();

        if (temp < 0)
        {
            break;
        }
        if (i+1 == MAXN)
        {
            MAXN *= 2;
            A = realloc(A, MAXN * sizeof(int));
            printf("(resize) from %d to %d\n", i+1, MAXN);
        }
        A[i] = temp;
        i++;
    }
    //free(A);
    int lengthA = 0;
    lengthA = i;

    // for (int i = 0; i < lengthA; i++)
    // {
    //     printf("A[%d]=%d\n", i, A[i]);
    // }
    i = 0;
    MAXN = 5;
    printf("Please input the set B:\n"); //get input Array B
    while (1)
    {
        int temp = 0;
        scanf("%d", &temp);
        getchar();

        if (temp < 0)
        {
            break;
        }

        if (i+1 == MAXN)
        {
            MAXN *= 2;
            B = realloc(B, MAXN * sizeof(int));
            printf("(resize) from %d to %d\n", i+1, MAXN);
        }
        B[i] = temp;
        //printf("i=%d\n",i);
        i++;
    }
    //free(B);
    int lengthB = 0;
    lengthB = i;
    // for (int i = 0; i < lengthB; i++)
    // {
    //     printf("B[%d]=%d\n", i, B[i]);
    // }

    // for (int i = 0; i < lengthA; i++)
    // {
    //     printf("A[%d]:%d\n", i, A[i]);
    // }

    // for (int i = 0; i < lengthB; i++)
    // {
    //     printf("B[%d]:%d\n", i, B[i]);
    // }

    printf("---Result---\n");

    int min_subscript = 0;
    int minANS = 2147483647;
    int ANS;
    //printf("%d %d\n", lengthA, lengthB);
    for (int i = 0; i <= (lengthA - lengthB); i++) //choose the minist difference
    {
        //printf("i=%d\n", i);
        ANS = 0;
        //printf("ANS = %d (supposed 0)\n", ANS);
        for (int j = 0; j < lengthB; j++)
        {
            int sum = fabs(A[i + j] - B[j]);
            //printf("%d\n", sum);
            ANS += sum;
            //printf("%d\n", ANS);
        }
        //printf("%d\n", ANS);
        if (ANS < minANS)
        {
            minANS = ANS;

            min_subscript = i;
        }
    }

    for (int i = 0; i < lengthB; i++) //output
    {
        printf("%d ", A[min_subscript + i]);
    }

    free(A);
    free(B);
}