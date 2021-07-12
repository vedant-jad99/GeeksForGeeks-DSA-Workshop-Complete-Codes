/*
Given a string S, find the length of the longest substring without repeating characters.
Example:
        Input - S = "geeksforgeeks"
        Output - 7
        Explanation - Longest substring is "eksforg".

        Input - S = "abdefgabef"
        Output - 6
        Explanation - Longest substring are "abdefg" , "bdefga" and "defgab".

Constraints:
        Time complexity - O(|S|)
        Space complexity - O(k)
        1 ≤ |S| ≤ 105
*/

#include <iostream>
#include <unordered_map>
#include <string>
#include <iterator>

using namespace std;

class Solution{
    public:
    int longestUniqueSubsttr(string S){
        //code
        unordered_map<char, int> m;
        unordered_map<char, int>::iterator it;
        
        int start = 0, end = 0, length = 0;
        for(int i = 0; i < S.length(); i++) {
            it = m.find(S[i]);
            if(it == m.end()) {
                m.insert({S[i], i});
                end = i;
            }
            else {
                if(it->second < start) {
                    it->second = i;
                    end = i;
                }
                else {
                    start = it->second + 1, end = i;
                    it->second = i;
                }
            }
            length = max(length, end - start + 1);
            // cout<<start<<" "<<end<<" "<<length<<"\n";
        }
        
        return length;
    }
};
