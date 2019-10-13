#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int newArray1(int n) //initialize the array(int)
{
    int *ID = malloc(sizeof(int) * n);
    memset(ID, 0, sizeof(int) * n);
    return ID;
}

int newArray2(int n) //initialize the array(float)
{
    float *score = malloc(sizeof(float) * n);
    memset(score, 0, sizeof(float) * n);
    return score;
}

int main()
{
    printf("Please type scores to be calculated:\n");
    int MAXN = 5;
    int *ID = newArray1(MAXN);
    float *score = newArray2(MAXN);
    //printf("%f", *score);
    int i = 0;
    while (1)
    {
        //printf("i=%d\n", i);
        int temp_ID;
        float temp_score;
        scanf("%d %f", &temp_ID, &temp_score);
        if ((temp_ID == (-1))&&(temp_score == (-1)))
        {
            break;
        }

        getchar();

        //printf("repeat:%d %f\n", ID[i], score[i]);
        if ((i+1) == MAXN)
        {
            MAXN *= 2;
            ID = realloc(ID, MAXN * sizeof(int));
            score = realloc(score, MAXN * sizeof(float));
            printf("(resize) from %d to %d\n", i+1, MAXN);
            printf("(resize) from %d to %d\n", i+1, MAXN);
        }

        ID[i] = temp_ID;
        score[i] = temp_score;
        i++;
    }
    //printf("i=%d\n", i);
    // free(ID);
    // free(score);
    int n = i;
    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d %.1f\n", ID[i], score[i]);
    // }

    if (i > 0)
    {

        int n = i;
        //printf("checkpoint\n");
        for (int i = 0; i < n; i++) //First Bubble
        {
            for (int j = 1; j < n; j++)
            {
                if (ID[j - 1] > ID[j])
                {
                    int temp0;
                    temp0 = ID[j];
                    ID[j] = ID[j - 1];
                    ID[j - 1] = temp0;
                    float temp1;
                    temp1 = score[j];
                    score[j] = score[j - 1];
                    score[j - 1] = temp1;
                }
            }
        }

        for (int i = 0; i < n; i++) //Second bubble
        {
            for (int j = 1; j < n; j++)
            {
                if (score[j - 1] > score[j])
                {
                    float temp0;
                    temp0 = score[j];
                    score[j] = score[j - 1];
                    score[j - 1] = temp0;
                    int temp1;
                    temp1 = ID[j];
                    ID[j] = ID[j - 1];
                    ID[j - 1] = temp1;
                }
            }
        }

        printf("---Result---\n");

        for (int i = 0; i < n; i++)
        {
            printf("%d %.1f\n", ID[i], score[i]);
        }
    }

    free(ID);
    free(score);

    return 0;
}