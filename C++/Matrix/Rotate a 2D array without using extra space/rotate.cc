//Linkt to the problem - https://practice.geeksforgeeks.org/problems/rotate-a-2d-array-without-using-extra-space1004/1#

class Solution{
public:	
	
	void rotateMatrix(vector<vector<int>>& arr, int n) {
	    // code here
        
        //Approach 1 - Recursion [ O(n) extra space ]
        // rotateRecurse(0, n, n - 1, arr);
        
        //Approach 2 - Loop
        int size = n, end = n - 1, start = 0;
        while(size > 1) {
            for(int i = 0; i < size - 1; i++) {
                int temp = arr[start][start + i];
                arr[start][start + i] = arr[start + i][end];
                arr[start + i][end] = arr[end][end - i];
                arr[end][end - i] = arr[end - i][start];
                arr[end - i][start] = temp;
            }
            size -= 2; end -= 1; start += 1;
        }
	}
    
    //Recursion
	void rotateRecurse(int start, int size, int end, vector<vector<int>> &matrix) {
        if(size <= 1)
            return;
        
        for(int i = 0; i < size - 1; i++) {
            int temp = matrix[start][start + i];
            matrix[start][start + i] = matrix[start + i][end];
            matrix[start + i][end] = matrix[end][end - i];
            matrix[end][end - i] = matrix[end - i][start];
            matrix[end - i][start] = temp;
        }
        
        rotateRecurse(start + 1, size - 2, end - 1, matrix);
    }
};
