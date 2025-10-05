#include <stdio.h>
#include <windows.h>

template <typename T>
T Min(T a, T b)
{
    return (a < b) ? a : b;
}

int main()
{
    // int
    int a = 1, b = 2;
    int minInt = Min(a, b);

    // float
    float x = 2.1f, y = 2.0f;
    float minFloat = Min(x, y);

    // double
    double p = 3.1, q = 3.0;
    double minDouble = Min(p, q);

    printf("MinInt: %d\n", minInt);
    printf("MinFloat: %.2f\n", minFloat);
    printf("MinDouble: %.2lf\n", minDouble);

    return 0;
}
