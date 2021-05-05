/*
Given an array of strings, return all groups of strings that are anagrams. The groups must be created in order 
of their appearance in the original array. Look at the sample case for clarification.
Example:
        Input - N = 5, words[] = {act,god,cat,dog,tac}
        Output - god dog, act cat tac
        Explanation - There are 2 groups of anagrams "god", "dog" make group 1. "act", "cat", "tac" make group 2.

        Input - N = 3, words[] = {no,on,is}
        Output - no on, is
        Explanation - There are 2 groups of anagrams "no", "on" make group 1. "is" makes group 2. 

Constraints:
        Time complexity - O(N*S*logS)
        Space Complexity - O(N)
        1<=N<=100
*/

#include <iostream>
#include <vector>
#include <map>
#include <iterator>
#include <algorithm>
#include <string>

using namespace std;

vector<vector<string>> Anagrams(vector<string>& string_list) {
    //Map to store the common anagramic strings
    map<string, int> m;
    map<string, int>::iterator it;
    vector<vector<string>> anagrams;
    int index = 0;
    
    /*For each string in the array, we will first sort it and check if it's present in map. It takes O(1) time
    If not present, then we will insert it with an index number. At the same time we will create a vector with
    the og string as the element and insert the vector in the anagram, at the given index.
    If present, it means it's an anagram of some other string, so we will insert the string in the sub-array having
    that anagram group.
    */
    for(int i = 0; i < string_list.size(); i++) {
        string temp = string_list[i];
        sort(temp.begin(), temp.end());
        
        it = m.find(temp);
        if(it == m.end()) {
            m.insert({temp, index++});
            vector<string> vec{string_list[i]};
            anagrams.push_back(vec);
        }
        else
            anagrams[it->second].push_back(string_list[i]);
    }
    return anagrams;
}
int main() {
    int n;
    cin>>n;
    
    vector<string> list;
    string temp;

    for(int i = 0; i < n; i++) {
        cin>>temp;
        list.push_back(temp);
    }
    
    vector<vector<string>> anagrams = Anagrams(list);
    for(int i = 0; i < anagrams.size(); i++) {
        for(int j = 0; j < anagrams[i].size(); j++)
            cout<<anagrams[i][j]<<" ";
        cout<<"\n";
    }
    
    return 0;
}