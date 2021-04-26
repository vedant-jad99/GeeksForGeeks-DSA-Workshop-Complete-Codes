/*
Given an array a of integers of length n, find the nearest smaller number for every element such that the smaller element is on left side.
If no small element present on the left print -1.
Example: 
        Input - n = 3, arr[] = [1 6 2]
        Output - -1 1 1
        Explanation - There is no number at the left of 1. Smaller number than 6 and 2 is 1.
        Input - n = 6, arr[] = [1 5 0 3 4 5]
        Output - -1 1 -1 0 3 4
        Explanation - Upto 3 it is easy to see the smaller numbers. But for 4 the smaller numbers are 1, 0 and 3. But among them 3 
	is closest. Similary for 5 it is 4.
Constraints:
        Time Complexity - O(n)
        Space Complexity - O(n)
        1 ≤ n ≤ 100
        0 ≤ arr[i] ≤ 10^4
*/

//This is a deque implementation, which actually here, is functioning similarly as a linked list with head insertion and head deletion.

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<int> leftSmaller(int n, int arr[]){
    deque<int> q(1, arr[0]);
        
    vector<int> answer(n, -1);
        
    for(int i = 1; i < n; i++) {
        if(arr[i] > q.front()) 
            answer[i] = q.front();
        else {
            while(!q.empty() && arr[i] <= q.front())
                q.pop_front();
            if(!q.empty())
                answer[i] = q.front();
        }
        q.push_front(arr[i]);
    }
    
    return answer;
}

int main() {
    int n;
    cin>>n;

    vector<int> vec, answer;
    int ele;

    for(int i = 0; i < n; i++) {
        cin>>ele;
        vec.push_back(ele);
    }

    answer = leftSmaller(vec, n);
    for(int i = 0; i < n - 1; i++) 
        cout<<answer[i]<<" ";
    cout<<answer[n - 1]<<"\n";

    return 0;
}