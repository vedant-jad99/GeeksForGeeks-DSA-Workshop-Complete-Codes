#include <iostream>

using namespace std;

class Solution {
  public:
    int makeProductOne(int arr[], int N) {
        // code here
        int moves = 0;
        bool isZero = false;
        int negative_count = 0;
        for(int i = 0; i < N; i++) {
            if(arr[i] <= -1) {
                negative_count++;
                moves += (-1 - arr[i]);
            }
            else if(arr[i] == 0) {
                isZero = true;
                if(negative_count%2 == 1)
                    negative_count++;
                moves++;
            }
            else {
                moves += (arr[i] - 1);
            }
        }
        
        if(negative_count%2 == 1 && !isZero)
            return moves + 2;
        return moves;
    }
};
