/*Program to find the number of integers from 1 to n, having exactly 3 divisors.
Ex. Input - 5
    Ouput - 1
    Explanation - Only 1 number (4) has exactly 3 divisors

    Input - 11
    Output - 2
    Explanation - Only 2 numbers (9, 4) have exactly 3 divisors

Constrainsts - 
    Time complexity - O((n^0.5)*(n^0.25)) [root n * fourth root of n]
    Space complexity - O(1)
*/

#include <iostream>
#include <cmath>

using namespace std;

int exactly3Divisors(int n) {
    int count = 0;
    bool flag;

    if(n < 4)
        return 0;
    else if(n < 9)
        return 1;
    else if(n < 25)
        return 2;
    else {
        for(int i = 5; i < floor(sqrt(n)) + 1; i+= 2) {
            flag = false;
            for(int j = 2; j < floor(sqrt(i)) + 1; j++)
                if(i%j == 0) {
                    flag = true;
                    break;
                }
            
            if(!flag)
                count++;
        }

        return count + 2;
    }
}

int main() { 
    int n;
    cin>>n;

    cout<<exactly3Divisors(n);
}
