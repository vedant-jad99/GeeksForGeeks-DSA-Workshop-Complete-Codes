/*
Link to the question - https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1#
*/

class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
        sort(arr, arr + n);
        sort(dep, dep + n);
        
        //Approach 1 - Max interval overlaps
        int total = 0, marker = 0, max = 0, max_time = 0, i = 0;
        while(i < n && marker < n) {
            total++;
            if(dep[marker] < arr[i]) { 
                total--;
                marker++;
            }
        
            if(max < total) {
                max = total;
            }
        
            i++;
        }
        return max;
        
        //Approach 2 - Merge sorted and check arrival and departure
        /*
        int i = 0, j = 0;
        int platforms = 0, max_plat = 0;
        while(i < n && j < n) {
            if(arr[i] <= dep[j]) {
                platforms += 1;
                max_plat = max(max_plat, platforms);
                i++;
            }
            else {
                platforms--;
                j++;
            }
        }
        
        return max_plat;
        */
    }
};
