/*Given a string S consisting of uppercase and lowercase characters. The task is to sort uppercase and 
lowercase letters separately such that if the ith place in the original string had an Uppercase character 
then it should not have a lowercase character after being sorted and vice versa.

Example:  Input - N = 12, S = defRTSersUXI
          Output - deeIRSfrsTUX
          Explanation - Sorted form of given string with the same case of character as that in original string 
          is deeIRSfrsTUX

          Input - N = 6, S = srbDKi
          Output - birDKs

Constraints: 
    Time complexity - O(N*Log(N))
    Space complexity - O(N)
    1 ≤ N ≤ 10^3
*/

#include <bits/stdc++.h>

using namespace std;

string caseSort(string str, int n){
    string answer = "";
    vector<char> caps, no_caps;
    vector<int> pos;
    
    for(int i = 0; i < n; i++) 
        if(str[i] >= 97) {
            no_caps.push_back(str[i]);
            pos.push_back(0);
        }
        else {
            caps.push_back(str[i]);
            pos.push_back(1);
        }
        
    sort(caps.begin(), caps.end());
    sort(no_caps.begin(), no_caps.end());
    
    int marker1 = 0, marker2 = 0;
    for(int i = 0; i < n; i++)
        if(pos[i] == 0) {
            answer += no_caps[marker1];
            marker1++;
        }
        else {
            answer += caps[marker2];
            marker2++;
        }
        
    return answer;
}

int main() {
    int t; string input;
    cin>>t;
 
    for(int i = 0; i < t; i++) {
        cin>>input;
        cout<<"Case sort - "<<caseSort(input, input.length())<<"\n\n";
    }

    return 0;
}
