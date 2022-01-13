#include <stdio.h>

int numDigits(long int n) {
    if(n == 0)
        return 0;
    return 1 + numDigits(n / 10);
}

int main()
{
    long int n;
    scanf("%ld", &n);
    printf("%d\n", numDigits(n));
    return 0;
}
