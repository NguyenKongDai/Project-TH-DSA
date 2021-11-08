#include "InterpolationSort.h"

int interpolationSort(int *a, int n, int x)
{
    int L = 0, R = n - 1;
    while (L <= R)
    {
        int pivot = ((x - a[L]) / (a[R] - a[L])) * (R - L) + L;
        if (a[pivot] == x)
            return pivot;
        if (a[pivot] > x)
            R = pivot - 1;
        if (a[pivot] < x)
            L = pivot + 1;
    }
    return -1;
}

int stringToInt(char *s)
{
    int d = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        d = d * 10 + ((int)s[i] - 48);
    }
    return d;
}
