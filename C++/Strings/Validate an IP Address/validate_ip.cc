/*
Write a program to Validate an IPv4 Address. According to Wikipedia, IPv4 addresses are canonically represented in dot-decimal notation, which consists of four decimal numbers, 
each ranging from 0 to 255, separated by dots, e.g., 172.16.254.1 . The generalized form of an IPv4 address is (0-255).(0-255).(0-255).(0-255). Here we are considering numbers 
only from 0 to 255 and any additional leading zeroes will be considered invalid.
Your task is  to complete the function isValid which returns 1 if the ip address is valid else returns 0. The function takes a string s as its only argument .
Example:
        Input - ip = 5555..555
        Output - 0
        Explanation - 5555..555 is not a valid ip address, as the middle two portions are missing.
        
        Input - ip = 222.111.111.111
        Output - 1

Constraints:
        Time complexity - O(n)
        Space complexity - O(n)
        1<=length of string <=50
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
    public:
        int isValid(string s) {
            // code here
            if(s.length() > 15)
                return 0;
            
            vector<string> ips;
            string temp;
            int counter = 0;
            
            for(int i = 0; i < s.length(); i++) {
                if(s[i] == '.') {
                    counter++;
                    ips.push_back(temp);
                    temp = "";
                }
                else
                    temp += s[i];
            }
            
            ips.push_back(temp);
            if(++counter == 4) {
                for(int i = 0; i < 4; i++) {
                    if(ips[i].length() == 0)
                        return 0;
                    else if(ips[i].length() == 1 && (ips[i][0] <= '9' && '0' <= ips[i][0]))
                        continue;
                    else if(ips[i].length() > 1 && ips[i][0] == '0')
                        return 0;
                    else {
                        for(int j = 0; j < ips[i].length(); j++)
                            if(ips[i][j] <= '9' && ips[i][j] >= '0')
                                continue;
                            else
                                return 0;
                        
                        int ip = stoi(ips[i]);
                        if(ip >= 0 && ip <= 255)
                            continue;
                        else
                            return 0;
                    }
                }    
            }
            else
                return 0;
                
            return 1;
        }
};
