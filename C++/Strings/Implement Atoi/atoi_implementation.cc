/*
Your task  is to implement the function atoi. The function takes a string(str) as argument and converts it to an integer and returns it.
Example:
        Input - str = 123
        Output - 123

        Input - str = 21a
        Output - -1
        Explanation - Output is -1 as all characters are not digit only.

Constraints:
        Time complexity - O(S)
        Space complexity - O(1)
        1<=length of S<=10
        
Additional tags: Design-pattern
*/

class Solution{
    //private members
    unordered_map<char, int> dict;
    unordered_map<char, int>::iterator it;
    
    public:
    //Constructor to initialize the dictionary only once for object.
    Solution() {
        char c = '0';
        for(int i = 0; i < 10; i++, c++)
            dict.insert({c, i});
    }
    //Function to complete
    int atoi(string str)
    {
        //Your code here
        bool negative = false;
        int start_index = 0;
        
        //Checking for negative values
        if(str[0] == '-') {
            negative = !negative;
            start_index++;
        }
            
        int res = 0;
        for(int i = start_index; i < str.length(); i++) 
            if(str[i] <= '9' && str[i] >= '0') 
                res = 10 * res + dict[str[i]];
            else
                return -1;
            
                
        if(negative)
            return -res;
        return res;
    }
};
