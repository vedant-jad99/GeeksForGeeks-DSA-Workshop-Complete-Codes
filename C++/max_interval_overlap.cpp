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