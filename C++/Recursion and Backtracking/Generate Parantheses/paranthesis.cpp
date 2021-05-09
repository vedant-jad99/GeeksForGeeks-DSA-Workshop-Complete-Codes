/*
Given an integer N representing the number of pairs of parentheses, the task is to generate all combinations of 
well-formed(balanced) parentheses.
Example:
        Input - N = 3
        Output - ((())), (()()), (())(), ()(()), ()()()

        Input - N = 1
        Output- ()

Constriants:
        Time Complexity - O(2^N)
        Space Complexity - O(2*N*X)
        1 ≤ N ≤ 12
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void ParanthesisGen(string, int, int, vector<string> &);

vector<string> AllParenthesis(int n) 
{
    vector<string> list;
    string str = "";
    
    ParanthesisGen(str, n, n, list);
    return list;
}
void ParanthesisGen(string s, int n, int m, vector<string> &list) {
    if(n == 0 && m == 0)
        list.push_back(s);
    else {
        if(n > m)
            return;
        else if(n == 0)
            ParanthesisGen(s + ")", n, m - 1, list);
        else {
            ParanthesisGen(s + "(", n - 1, m, list);
            ParanthesisGen(s + ")", n, m - 1, list);
        }
    }
}

int main () {
    int n;
    cin>>n;

    vector<string> paranthesis = AllParenthesis(n);

    for(auto i : paranthesis)
        cout<<i<<"\n";
}
