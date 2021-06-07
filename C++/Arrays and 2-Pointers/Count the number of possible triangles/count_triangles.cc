/*
Given an unsorted array arr[] of n positive integers. Find the number of triangles that can be formed with three different array elements as lengths of three sides of triangles. 
Example:
        Input - n = 3, arr[] = {3, 5, 4}
        Output - 1
        Explanation - A triangle is possible with all the elements 5, 3 and 4.
        
        Input - n = 5, arr[] = {6, 4, 9, 7, 8}
        Output - 10
        
Constraints:
        Time complexity - O(n^2)
        Space complexity - O(1)
        3 <= n <= 10^3
        1 <= arr[i] <= 10^3
        
Note: A very good problem. Shows the usefulness of 2 pointer method. Do review once.

PS: Too tired to write the driver code, just posting the solution
*/
class Solution {
    public:
        int findNumberOfTriangles(int arr[], int n)
        {
            //First sorting the array to make counting easier
            sort(arr, arr + n);
            
            /*The idea here is, we fix two sides of the triangle and check for the third side. 
            Let's take an example - [2, 3, 4, 5, 9, 10]. Here traverse from last index to second(i.e i = n - 1 to 1).
            We define l = 0, and r = i - 1, and fix three sides as arr[i] and arr[l], and check for arr[r] from i - 1 to l + 1. We know that arr[i] > arr[r] > arr[l] so we check
            that arr[r] + arr[l] > arr[i].
            Now, if the eqn holds, we can say it will hold for all j = l + 1 to r, so we increment count by r - l. If not, we check for the next element of arr[l], i.e, 
            increment l.
            */
            int l, r, count = 0;
            for(int i = n - 1; i > 1; i--) {
                l = 0, r = i - 1;
                while(r > l) {
                    if(arr[i] < arr[r] + arr[l])
                        count += (r-- - l);
                    else
                        l++;
                }
            }
            return count;
        }
};
