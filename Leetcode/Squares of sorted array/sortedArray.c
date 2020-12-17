#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int* sortedSquares(int* nums, int numsSize, int* returnSize){
    int l = 0, r = numsSize - 1;
    returnSize = (int*)malloc(sizeof(int) * numsSize);
       
    if(nums[l] >= 0) {
        for(int i = 0; i < numsSize; i++)
            returnSize[i] = pow(nums[i], 2);
    }
    else if(nums[r] <= 0) {
        for(int i = numsSize - 1; i >= 0; i--)
            returnSize[numsSize - 1 - i] = pow(nums[i], 2);
    }
    else {
        int i, j, l, count;
        for(l = 1; l < numsSize; l++)
            if(nums[l - 1] < 0 && nums[l] >= 0)
                break;
        
        i = l - 1, j = l, count = 0;
        while(i >= 0 && j < numsSize) {
            int pow1 = pow(nums[i], 2), pow2 = pow(nums[j], 2);
            if(pow1 <= pow2) {
                returnSize[count] = pow1;
                i--;
            }
            else {
                returnSize[count] = pow2;
                j++;
            }
            count++;
        }
        if(i < 0)
            while(j < numsSize)
                returnSize[count++] = pow(nums[j++], 2);
        
        else
            while(i >= 0)
                returnSize[count++] = pow(nums[i--], 2);
    }
    return returnSize;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", arr + i);

    int *new_arr = sortedSquares(arr, n, new_arr);
    for(int i = 0; i < n; i++) {
        printf("%d\n", new_arr[i]);
    }
    return 0;
}