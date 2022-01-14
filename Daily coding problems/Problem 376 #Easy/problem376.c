#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

int manhattanDist(int x, int y, int pos_x, int pos_y) {
    return abs(x - pos_x) + abs(y - pos_y);
}
int *closestDist(int *arr, int n, int x, int y) {
    if(n == 0)
        return NULL;
    
    int minDist = INT_MAX;
    int *pair = malloc(sizeof(int) * 2);
    
    for(int i = 0; i < n; i++) { 
        int dist = manhattanDist(arr[2 * i], arr[2 * i + 1], x, y);
        if(dist < minDist) {
            minDist = dist;
            pair[0] = arr[2 * i];
            pair[1] = arr[2 * i + 1];
        }
    }
    
    return pair;
}
int main()
{
    int n, x, y;
    scanf("%d", &n);
    
    int *arr = malloc(sizeof(int) * 2 * n);
    for(int i = 0; i < n; i++) {
        scanf("%d %d", arr + 2 * i, arr + (2 * i + 1));
    }
    scanf("%d %d", &x, &y);
    
    int *pair = closestDist(arr, n, x, y);
    if(pair)
        printf("\n\n%d %d\n", pair[0], pair[1]);
    
    free(arr);
    free(pair);
    return 0;
}
