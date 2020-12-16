/*Given two numbers a and b, find the sum of a and b. Since the sum can be very large, find the sum 
modulo 10^9+7.
Ex. Input - a = 9223372036854775807
            b = 9223372036854775807
    Output: 582344006
    Explanation: 9223372036854775807 + 9223372036854775807 = 18446744073709551614, 
                 (18446744073709551614)mod(10^9+7) = 582344006

    Input - a = 1000000007
            b = 1000000007
    Output: 0
    Explanation: 1000000007 + 1000000007 = (2000000014â€¬)mod(109+7) = 0

Constraints - 
    Time complexity - O(1)
    Space complexity - O(1)

1 <= a,b <= 2^63-1
*/

#include <iostream>
#include <cmath>

using namespace std;

long long sumUnderModulo(long long a, long long b) {

    long long modulo = pow(10, 9) + 7;
    a = a % modulo;
    b = b % modulo;
    return a + b;
}

int main() {
    long long a, b;
    cin>>a>>b;

    cout<<sumUnderModulo(a, b)<<"\n";
    return 0;
}