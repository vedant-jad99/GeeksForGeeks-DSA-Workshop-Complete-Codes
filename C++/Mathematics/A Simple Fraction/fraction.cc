/*
Given a fraction. Convert it into a decimal. 
If the fractional part is repeating, enclose the repeating part in parentheses.
Example:
        Input - numerator = 1, denominator = 3
        Output - "0.(3)"
        Explanation - 1/3 = 0.3333... So here 3 is recurring.

        Input: numerator = 5, denominator = 2
        Output: "2.5"
        
Constraints:
        Time complexity - O(k) [k is some constant]
        Space complexity - O(k)
        1 ≤ numerator, denominator ≤ 2000
        
Note: Here we make use of two tricks. In case of recurring, we can see that the remainder gets repeated at the start of pattern. So we store the remainder and the index of the 
string as key value pair in hash-table. Second, in case of non recurring, remainder will be zero.
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <iterator>

using namespace std;

class Solution{
	public:
	string fractionToDecimal(int num, int den) {
	    // Code here
	    unordered_map<int, int> rems;
	    unordered_map<int, int>::iterator it;
	    
	    int gcd_ele = gcd(num, den);
	    if(gcd_ele != 1) {
	        num = num/gcd_ele;
	        den = den/gcd_ele;
	    }
	    
	    int rem = num%den;
	    string whole = to_string(num/den);
	    if(!rem)
	        return whole;
	    
	    whole += ".";
	    string fractional = "";
	    int index = 0;
	    
	    while(rem) {
	        it = rems.find(rem);
	        if(it != rems.end())
	            break;
	        
	        rems.insert({rem%den, index});
	        rem = rem * 10;
	        fractional += to_string(rem/den);
	        rem = rem%den;
	        index++;
	    }
	    if(rem == 0)
	        return whole + fractional;
	    
	    for(int i = 0; i < it->second; i++)
	        whole += fractional[i];
	    
	    whole += "(";
	    for(int i = it->second; i < fractional.length(); i++)
	        whole += fractional[i];
	       
	    return whole + ")";
	}
	int gcd(int a, int b) {
	    if(b == 0)
	        return a;
	    return gcd(b, a%b);
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int numerator, denominator;
		cin >> numerator >> denominator;
		Solution ob;
		string ans = ob.fractionToDecimal(numerator, denominator);
		cout << ans <<"\n";
	}
	return 0;
