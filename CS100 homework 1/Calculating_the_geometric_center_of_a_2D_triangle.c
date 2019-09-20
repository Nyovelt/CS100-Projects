#include "stdio.h"
#include "math.h"
double X0, X1, X2, X3, Y0, Y1, Y2, Y3, D1, D2, D3;
double max();
double min();
int main()
{
    printf("Input vertex 1: ");
    scanf("%lf %lf", &X1, &Y1);
    printf("Input vertex 2: ");
    scanf("%lf %lf", &X2, &Y2);
    printf("Input vertex 3: ");
    scanf("%lf %lf", &X3, &Y3);
    //printf("%f %f %f", Y1, Y2, Y3);
    X0 = (X1 + X2 + X3) / 3;
    Y0 = (Y1 + Y2 + Y3) / 3;
    printf("The center of the triangle is: %.1f %.1f\n", X0, Y0);
    distance();
    printf("The maximum distance between center and vertices: %.2f\n", max(D1, D2, D3));
    printf("The minimum distance between center and vertices: %.2f", min(D1, D2, D3));
}

void distance()
{
    D1 = sqrt((X1 - X0) * (X1 - X0) + (Y1 - Y0) * (Y1 - Y0));
    D2 = sqrt((X2 - X0) * (X2 - X0) + (Y2 - Y0) * (Y2 - Y0));
    D3 = sqrt((X3 - X0) * (X3 - X0) + (Y3 - Y0) * (Y3 - Y0));
}

double max(double a, double b, double c)
{
    double max_;
    max_ = a;
    if (max_ < b)
        max_ = b;
    if (max_ < c)
        max_ = c;
    return max_;
}

double min(double a, double b, double c)
{
    double min_;
    min_ = a;
    if (min_ > b)
        min_ = b;
    if (min_ > c)
        min_ = c;
    return min_;
}
