/*
Given an integer n. Return the nth row of the following look-and-say pattern.
1
11
21
1211
111221
Example:
        Input - n = 5
        Ouput - 111221
        Explanation - Fifth line of look and say pattern

        Input - n = 3
        Output - 21
        
Constraints:
        Time complexity - O(2^n)
        Space complexity - O(2^(n - 1))
        1 <= n <= 30
*/
#include <iostream>
#include <string>

using namespace std;

string lookandsay(int n) {
    if(n == 1)
        return "1";
    
    cout<<n<<"\n";
    string prev = lookandsay(n - 1);
    string ans = ""; 
    int count = 1, m = prev.length();
    for(int i = 0; i < m - 1; i++) {
        if(prev[i] == prev[i + 1])
            count++;
        else {
            ans = ans + to_string(count) + prev[i];
            count = 1;
        }
    }
    
    ans = ans + to_string(count) + prev[m - 1];
        
    return ans;
}

int main() {
    int n;
    cin>>n;

    cout<<lookandsay(n)<<"\n";
}