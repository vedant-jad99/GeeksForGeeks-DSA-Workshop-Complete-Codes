/*
You are given an array of distinct integers arr and an array of integer arrays pieces, where the integers 
in pieces are distinct. Your goal is to form arr by concatenating the arrays in pieces in any order. 
However, you are not allowed to reorder the integers in each array pieces[i].

Return true if it is possible to form the array arr from pieces. Otherwise, return false.
Ex. Input - arr : [91,4,64,78], pieces : [[78],[4,64],[91]]
    Output - true
    Explanation - Concatenate [91] then [4,64] then [78]

    Input - arr : [49,18,16], pieces : [[16,18,49]]
    Output - false
    Explanation - Even though the numbers match, we cannot reorder pieces[0].

Constraints - 
    1 <= pieces.length <= arr.length <= 100
    sum(pieces[i].length) == arr.length
    1 <= pieces[i].length <= arr.length
    1 <= arr[i], pieces[i][j] <= 100

Solution Complexity - 
    Time : O(m + n); m = pieces.length, n = arr.length
    Space : O(m)
*/

#include <iostream>
#include <vector>
#include <map>
#include <iterator>
#define uint8_t uint

using namespace std;

bool canFormArray(vector<uint>& arr, vector<vector<uint>>& pieces) {
    map<uint, vector<uint>> pointer;
    map<uint, vector<uint>>::iterator it;

    for(uint i = 0; i < pieces.size(); i++) 
        pointer.insert({pieces[i][0], pieces[i]});

    for(uint i = 0; i < arr.size(); ) {
        it = pointer.find(arr[i]);
        if(it == pointer.end())
            return false;
        else {
            for(uint j = 0; j < it->second.size(); j++) {
                if(arr[i] == it->second[j])
                    i++;
                else
                    return false;
            }
        }
    }
    return true;
}

int main() {
    vector<uint> arr;
    vector<vector<uint>> pieces;

    uint n, m, tmp_size, dummy;
    cin>>n>>m;

    for(uint i = 0; i < n; i++) {
        cin>>dummy;
        arr.push_back(dummy);
    }
    for(uint i = 0; i < m; i++) {
        cin>>tmp_size;
        vector<uint> tmp;
        for(uint j = 0; j < tmp_size; j++) {
            cin>>dummy;
            tmp.push_back(dummy);
        }
        pieces.push_back(tmp);
    }

    if(canFormArray(arr, pieces))
        cout<<"true"<<"\n";
    else
        cout<<"false"<<"\n";

    return 0;
}
