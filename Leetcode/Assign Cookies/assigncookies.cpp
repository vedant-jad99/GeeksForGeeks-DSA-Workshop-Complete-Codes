/*
 *  Link to the problem: https://leetcode.com/problems/assign-cookies/description/?envType=daily-question&envId=2024-01-01
 *
 * Approach: Sorting(greedy) + 2 pointer
 */

//Only including the solution code, without the driver code to run the problem. Please bear with me 😅

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if (s.size() == 0) {
            return 0;
        }

        int count = 0;
        sort(s.begin(), s.end());
        sort(g.begin(), g.end());
 
        for (int i = 0, j = 0; (i < g.size()) && (j < s.size()); j++) {
            if (s[j] >= g[i]) {
                count++;
                i++;
            }
        }

        return count;
    }
};
