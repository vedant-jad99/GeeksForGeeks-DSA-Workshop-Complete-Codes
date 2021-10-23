//Link to the question - https://www.techiedelight.com/print-all-combination-numbers-from-1-to-n/

#include <iostream>
#include <vector>

using namespace std;

void printSum(vector<string> &v, int n, int prev, string s) {
    if(n == 1)
        return;
    for(int i = 1; i <= n/2; i++) {
        if(i < prev)
            continue;
        string temp = s + to_string(i) + " ";
        v.push_back(temp + to_string(n - i));
        printSum(v, n - i, i, temp);
    }
}

int main() {
    int n;
    vector<string> v;
    
    cin>>n;
    printSum(v, n, 0, "");
    v.push_back(to_string(n));
    
    for(auto s: v)
        cout<<s<<"\n";
    return 0;
}
