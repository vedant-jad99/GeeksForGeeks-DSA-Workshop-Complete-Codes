/*
Given an array arr[ ] of size N having distinct elements, the task is to find the next greater element for each 
element of the array in order of their appearance in the array.
Next greater element of an element in the array is the nearest element on the right which is greater than the 
current element. If there does not exist next greater of current element, then next greater element for current 
element is -1. For example, next greater of the last element is always -1.
Example: 
        Input - n = 4, arr[] = [1 3 2 4]
        Output - 3 4 4 -1
        Explanation - In the array, the next larger element to 1 is 3 , 3 is 4 , 2 is 4 and for 4 ? since it 
        doesn't exist, it is -1.

        Input - n = 5, arr[] [6 8 0 1 3]
        Output - 8 -1 1 3 -1
        Explanation - In the array, the next larger element to 6 is 8, for 8 there is no larger elements hence 
        it is -1, for 0 it is 1 , for 1 it is 3 and then for 3 there is no larger element on right and hence -1.

Constraints:
        Time Complexity - O(n)
        Space Complexity - O(n)
        1 ≤ n ≤ 10^6
        0 ≤ arr[i] ≤ 10^18
*/

//This is a deque implementation, which actually here, is functioning similarly as a linked list with head insertion and head deletion

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<long long> nextLargerElement(vector<long long> arr, int n){
    vector<long long> answer{-1};
    
    deque<long long> max(1, arr[n - 1]);
    
    for(int i = n - 2; i >= 0; i--) {
        if(arr[i] < max.front()) 
            answer.insert(answer.begin(), max.front());
        else {
            while(!max.empty() && arr[i] >= max.front())
                max.pop_front();
            if(max.empty())
                answer.insert(answer.begin(), -1);
            else
                answer.insert(answer.begin(), max.front());
        }
        max.push_front(arr[i]);
    }
    
    return answer;
}

int main() {
    int n;
    cin>>n;

    vector<long long> vec, answer;
    long long ele;

    for(int i = 0; i < n; i++) {
        cin>>ele;
        vec.push_back(ele);
    }

    answer = nextLargerElement(vec, n);
    for(int i = 0; i < n - 1; i++) 
        cout<<answer[i]<<" ";
    cout<<answer[n - 1]<<"\n";

    return 0;
}
