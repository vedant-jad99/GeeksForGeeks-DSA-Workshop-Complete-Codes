/*
Given a string s and an integer k, the task is to reduce the string by applying the following operation:
Choose a group of k consecutive identical characters and remove them.
The operation can be performed any number of times until it is no longer possible.
Example:
        Input - k = 2, s = "geegsforgeegs"
        Output - sfors
        Explanation - Modified String after each step: "geeksforgeeks" -> "ggsforggs" -> "sfors"

        Input - k = 2, s = "abcdeedcbaa"
        Output - a

Constraints:
        Time complexity - O(s)
        Space complexity - O(k)
        1 ≤ |s| ≤ 105
        1 ≤ k ≤ |s|
*/

#include <iostream>
#include <string>
#include <pair>
#include <algorithm>

using namespace std;

//Code to reduce the string
string Reduced_String(int k,string s){
    if(k == 1)
        return "";
            
    stack<pair<char, int>> stk;
    int n = s.length() - 1;
        
    stk.push(make_pair(s[n], 1));
        
    for(int i = n - 1; i > -1; i--) {
        if(!stk.empty() && s[i] == stk.top().first) {
            stk.push(make_pair(s[i], stk.top().second + 1));
            if(stk.top().second == k) {
                int temp = k;
                while(temp > 0) {
                    stk.pop();
                    temp--;
                }
            }
        }
        else
            stk.push(make_pair(s[i], 1));
    }
        
    string ans = "";
    while(!stk.empty()) {
        ans += stk.top().first;
        stk.pop();
    }
        
    return ans;
}

int main()
{
    string str;
    int k;
    
    cin>>k>>str;
    
    cout<<Reduced_String(k, str)<<"\n";
    return 0;
}
