#include <stdio.h>
#include <stdlib.h>

int **array_partition(int arr[], int size, int s[]) {
    int sum = 0, first_index = -1, second_index = -1, one_third_sum = 0;
    for(int i = 0; i < size; i++) {
        sum += arr[i];
    }
    if(sum % 3) {
        return NULL;
    }
    
    one_third_sum = sum / 3, sum = 0;
    for(int i = 0; i < size; i++) {
        sum += arr[i];
        if(sum == one_third_sum) {
            sum = 0;
            if(first_index == -1) {
                first_index = i;
            }
            else {
                second_index = i;
                break;
            }
        }
    }
    
    if(first_index == -1 || second_index == -1) {
        return NULL;
    }
    
    int **array = malloc(sizeof(int *) * 3);
    s[0] = first_index + 1;
    s[1] = second_index - first_index;
    s[2] = size - second_index - 1;
    
    for(int i = 0; i < 3; i++) {
        array[i] = malloc(sizeof(int) * s[i]);
    }
    
    for(int i = 0; i < size; i++) {
        if(i <= first_index) {
            array[0][i] = arr[i]; 
        }
        else if(i <= second_index) {
            array[1][i - first_index - 1] = arr[i];
        }
        else {
            array[2][i - second_index - 1] = arr[i];
        }
    }
    
    return array;
}

int main()
{
    int arr[] = {2, 8, 1, 1, 1, 7, 2, 1, 0, 10};
    int size = sizeof(arr) / sizeof(int);
    int *s = malloc(sizeof(int) * 3);
    
    int **partitions = array_partition(arr, size, s);
    if(partitions == NULL) {
        printf("Can't be divided.\n");
        goto END;
    }
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < s[i]; j++) {
            printf("%d ", partitions[i][j]);
        }
        free(partitions[i]);
        printf("\b\n");
    }
    free(partitions);
    
    END:
    free(s);
    return 0;
}
