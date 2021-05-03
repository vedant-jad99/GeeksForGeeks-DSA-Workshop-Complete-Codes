/*
Consider a big party where N guests came to it and a log register for guest’s entry and exit times was maintained. Find the minimum time at which there were maximum guests at the party. Note that entries in the register are not in any order.
Example:
        Input - N = 5, Entry= {1, 2,10, 5, 5}, Exit = {4, 5, 12, 9, 12}
        Output - 3 5
        Explanation - At time 5 there was guest number 2, 4 and 5 present.
     
        Input: N = 7, Entry= {13, 28, 29, 14, 40, 17, 3}, Exit = {107, 95, 111, 105, 70, 127, 74}
        Output: 7 40
        Explanation: At time 40 there were all 7 guests present at the party.

Constraints:
        Time Complexity - O(N*Log(N))
        Space Complexity - O(1)
        1 <= N <= 10^5
        1 <= Entry[i],Exit[i] <= 10^5
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> findMaxGuests(int Entry[], int Exit[], int N)
{
   // Your code goes here
   vector<int> entry_vec(Entry, Entry + N);
   vector<int> exit_vec(Exit, Exit + N);
   
   sort(entry_vec.begin(), entry_vec.end());
   sort(exit_vec.begin(), exit_vec.end());
   
   int total = 0, marker = 0, max = 0, max_time = 0, i = 0;
   while(i < N && marker < N) {
       total++;
       if(exit_vec[marker] < entry_vec[i]) { 
           total--;
           marker++;
       }
        
        if(max < total) {
            max = total;
            max_time = entry_vec[i];
        }
        
        i++;
   }
   
   return vector<int> {max, max_time};
}

int main() {
    int n;
    cin>>n;

    int Entry[n], Exit[n];
    for(int i = 0; i < n; i++) {
        cin>>Entry[i]>>Exit[i];
    }

    vector<int> res = findMaxGuests(Entry, Exit, n);
    cout<<res[0]<<" "<<res[1]<<"\n";
    
    return 0;
}
