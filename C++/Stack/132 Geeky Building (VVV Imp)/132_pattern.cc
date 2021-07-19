/*
Link to the question - https://practice.geeksforgeeks.org/problems/355f731797ea1acbd5ab698b19eb1c3c469aa837/1#
*/

class Solution{
public:
	bool recreationalSpot(int arr[], int n){
		// Your code goes here 
		    int min_array[n] = { };
		    min_array[0] = arr[0];
		    for(int i = 1; i < n; i++) {
		        min_array[i] = min(arr[i], min_array[i - 1]);
		    }
		    
		    stack<int> s;
		    for(int i = n - 1; i > 0; i--) {
		        if(s.empty())
		            s.push(arr[i]);
		        else {
		            if(arr[i] <= min_array[i - 1])
		                continue;
		            while(!s.empty() && s.top() <= min_array[i])
		                s.pop();
		            
		            if(!s.empty() && s.top() < arr[i])
		                return true;
		                
		            s.push(arr[i]);
		        }
		    }
		    return false;
		}
};
