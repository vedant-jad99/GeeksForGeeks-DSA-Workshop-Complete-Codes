#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int returnLongestSequence(vector<int> v) {
    unordered_set<int> s;
    for(int i : v)
        s.insert(i);
        
    int seq = 1;
    for(int i = 0; i < v.size(); i++) {
        if(s.find(v[i] - 1) == s.end()) {
            int count = 0, el = v[i];
            while(s.find(el) != s.end()) {
                el++;
                s.erase(el - 1);
                count++;
            }
            seq = max(count, seq);
        }
    }
    
    return seq;
}
int main()
{
    int size;
    cin>>size;
    vector<int> v(size, 0);
    
    for(int i = 0; i < size; i++) 
        cin>>v[i];
    
    cout<<"\n\n"<<returnLongestSequence(v)<<"\n";
    return 0;
}
