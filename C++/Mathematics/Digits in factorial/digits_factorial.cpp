/*Program to find the number of digits that appear in the factorial of n, given n. 
Ex. Input - 5
    Output - 3
    Explanation - Factorial of 5 is 120. Number of digits in 120 = 3

    Input - 120
    Output - 199
    Explanation - Number of digits in factorial of 120 is 199

Constraints - 
    Time complexity - O(n)
    Space complexity - O(1)

    1 <= N <= 10^4
*/

#include <iostream>
#include <cmath>

using namespace std;

int digitsInFactorial(int N)
{
    
    if(N < 1)
        return 1;
        
    double product = 0;
    for(int i = 2; i < N + 1; i++) {
        product += log10(i);
    }
    
    return floor(product) + 1;
}

int main() {
    int n;
    cin>>n;

    cout<<digitsInFactorial(n)<<"\n";
}
