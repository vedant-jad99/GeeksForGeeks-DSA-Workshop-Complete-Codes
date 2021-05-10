'''
Count the number of prime numbers less than a non-negative number, n.
Example:
        Input - n = 10
        Output - 4
        Explanation - There are 4 prime numbers less than 10, they are 2, 3, 5, 7.

        Input - n = 5
        Output - 2

Constraints:
        Time complexity - O(n(log(logn)))
        Space complexity - O(n)
        0 <= n <= 5 * 10^6
'''

from math import sqrt

def countPrimes(n):
    prime = [True for i in range(n)]
    count = 0
    
    for p in range(2, int(sqrt(n)) + 1):
        if prime[p]:
            for i in range(p ** 2, n, p):
                prime[i] = False
        
    
    for i in range(2, n):
        if prime[i]:
            count += 1
            
    return count

if __name__ == '__main__':
    n = int(input())
    print(countPrimes(n))