#include "sum.h"

int sum(int a[], int n)
{
    // (base case) if n=0 then
    if (n == 0)
    {
        return 0;
    }
    //else return the sum of array (the recursive step)
    else{
     return a[n-1]+ sum(a, n-1);   
    }
    return 0;
}