/*
Link to the question - https://practice.geeksforgeeks.org/problems/total-decoding-messages1235/1#
*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
	public:
		int CountWays(string str){
		    // Code here
		    int n = str.length();
		    int dp[n] = { };
		    if(str[n - 1] != '0')
    		    dp[n - 1] = 1;
		    
		    for(int i = n - 2; i >= 0; i--) {
		        string temp = "";
		        temp += str[i];
		        temp += str[i + 1];
		        if(str[i] == '0')
		            continue;
		        if(stoi(temp) < 27) {
		            if(i == n - 2)
		                dp[i] = dp[i + 1] + 1;
		            else
		                dp[i] = (dp[i + 1] + dp[i + 2])%1000000007;
		        }
		        else
		            dp[i] = dp[i + 1];
		    }
		    
		    return dp[0];
		}

};

