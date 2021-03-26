/*Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai).
n vertical lines are drawn such that the two endpoints of the line i is at (i, ai) and (i, 0). 
Find two lines, which, together with the x-axis forms a container, such that the container contains the 
most water.
Example:
        Input - [1,8,6,2,5,4,8,3,7]
        Output - 49
        Explanation - The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. 
                      In this case, the max area of water (blue section) the container can contain is 49.

        Input - [1,2,1]
        Output - 2

Constraints - 
        Time Complexity - O(n)
        Space Complexity - O(1)
        2 <= n <= 105
        0 <= height[i] <= 104
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

inline string trim(string &str) {
    str.erase(0, str.find_first_not_of(' '));
    str.erase(str.find_last_not_of(' ') + 1);
    return str;
}

int maxArea(vector<int>& height) {
    int l = 0, r = height.size() - 1, max = -1, area;
    while(l <= r) {
        area = min(height[l], height[r]) * (r - l);
        if(area > max)
            max = area;
        if(height[l] < height[r])
            l++;
        else
            r--;
    }
    return max;
}

int main() {
    string input, number = "";
    getline(cin, input);
    vector <int> heights;

    for(int i = 1; i < input.length() - 1; i++) {
        if(input[i] == ',') {
            string final_number = trim(number);
            heights.push_back(stoi(final_number));
            number = "";
        }
        else {
            number += input[i];
        }
    }
    string final_number = trim(number);
    heights.push_back(stoi(final_number));

    cout<<"Max Area : "<<maxArea(heights)<<endl;
}
