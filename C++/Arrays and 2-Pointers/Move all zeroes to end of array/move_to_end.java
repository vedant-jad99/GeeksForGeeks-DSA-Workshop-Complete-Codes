//Link to problem - https://practice.geeksforgeeks.org/problems/move-all-zeroes-to-end-of-array0751/1

class Solution {
    void pushZerosToEnd(int[] arr, int n) {
        // code here
        int ptr1 = 0, ptr2 = 0;
        while(ptr2 < n) {
            if(arr[ptr2] > 0) {
                arr[ptr1] = arr[ptr2];
                ptr1++; ptr2++;
            }
            else {
                ptr2++;
            }
        }
        while(ptr1 < n) {
            arr[ptr1++] = 0;
        }
    }
}
