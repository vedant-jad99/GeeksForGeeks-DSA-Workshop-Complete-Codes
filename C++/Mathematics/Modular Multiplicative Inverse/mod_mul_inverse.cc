/*Program to find the smallest modular multiplicative inverse of ‘a’ under modulo ‘m’, given two 
integers 'a' and 'm'.
Ex. Input - 3 11
    Output - 4
    Explanation - (3 * 4)%11 = 1. So 4 is the multiplicative modulo(11) inverse of 3.

    Input - 10 17
    Output - 12
    Explanation - (10 * 12)%17 = 1. So 12 is the multiplicative modulo(17) inverse of 10.

Constraints -
    Time complexity - O(m)
    Space complexity - O(1)
*/

#include <iostream>

using namespace std;

int modInverse(int a, int m) {

    int inverse = -1, min = m + 1;
    for(int i = 1; i < m; i++) {
        if((a * i)%m == 1) {
            min = std::min(min, i);
            inverse = min;
        }
    }
    return inverse;
}

int main() {
    int a, m;
    cin>>a>>m;

    cout<<modInverse(a, m);
}
