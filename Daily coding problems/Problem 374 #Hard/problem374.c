#include <stdio.h>
#include <stdlib.h>

void *index(void *arr, int n) {
    int l = 0, r = n - 1, mid;
    while(l < r) {
        mid = (l + r) / 2;
        if(*((int *)arr + mid) < mid) 
            l = mid + 1;
        else
            r = mid;
    }
    mid = r;
    if(*((int*)arr + mid) == mid)
        return (char*)arr + sizeof(int) * mid;
    return NULL;
}
int main()
{
    int n;
    scanf("%d", &n);
    int *a = malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++) 
        scanf("%d", a + i);
        
    int *p = index(a, n);
    if(p)
        printf("%d\n", *p);
    else
        printf("null\n");
        
    free(a);
    return 0;
}
