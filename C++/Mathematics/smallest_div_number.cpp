/*Program to find an integer denoting the smallest number evenly divisible by each number from 1 to n,
given an integer n.
Ex. Input - 3
    Output - 6
    Explanation - 6 is the smallest number divisible 1, 2, 3

    Input - 6
    Output - 60
    Explanation - 1, 2, 3, 4, 5, 6 divide 60

Constraints - 
    Time complexity - O(n)
    Space complexity - O(1)

    1 <= N <= 25
*/

#include <iostream>

using namespace std;

long long gcd(long long a, int b) {
    if(b == 0)
        return a;
    return gcd(b, a%b);
}
long long getSmallestDivNum(int n) {
    if(n < 2)
        return 1;
    else if(n < 3)
        return 2;
    else {
        long long answer = 2;
        for(int i = 3; i < n + 1; i++)
            answer = (answer * i)/gcd(answer, i);
        
        return answer;
    }
}

int main() {
    int n;
    cin>>n;

    cout<<getSmallestDivNum(n)<<"\n";
}