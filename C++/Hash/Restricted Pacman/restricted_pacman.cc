//Link to the problem - https://practice.geeksforgeeks.org/problems/2caf0501a39567d653197364a2b5c8a9f5943b7e/1

class Solution{
    public:
    int candies(int m, int n) 
    { 
    	// Your code goes here
    	unordered_set<int> s;
    	int counter = 0, sum = 0;
    	int lcm = (m * n);
    	
        for(int i = 0; i < lcm/n; i++) {
            for(int j = 0; j < lcm/m; j++) {
                int combination = i * n + j * m;
                if(combination < lcm && s.find(combination) == s.end()) {
                    s.insert(combination);
                    counter++;
                }
            }
        }
        return lcm - counter;
    } 
};
