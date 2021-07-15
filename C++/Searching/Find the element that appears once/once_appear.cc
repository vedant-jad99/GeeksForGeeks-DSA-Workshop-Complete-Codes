/*
Link to the question - https://practice.geeksforgeeks.org/problems/element-appearing-once2552/1
*/

#include <iostream>

using namespace std;

class Solution{
public:	
	int search(int A[], int N){
	    //code
	    int l = 0, r = N - 1, mid;
	    while(l <= r) {
	        mid = (l + r)/2;
	        if(mid == 0 && A[mid] != A[mid + 1])
	            return A[mid];
	        else if(mid == N - 1 && A[mid] != A[mid - 1])
	            return A[mid];
	        
	        if(A[mid] != A[mid + 1] && A[mid] != A[mid - 1])
	            break;   
	        else if(mid%2)
	            if(A[mid] != A[mid - 1])
	                r = mid - 1;
	            else
	                l = mid + 1;
	        else 
	            if(A[mid] != A[mid + 1])
	                r = mid - 1;
	            else
	                l = mid + 1;
	    }
	    return A[mid];
	}
};
