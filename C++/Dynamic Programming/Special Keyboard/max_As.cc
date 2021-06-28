/*
Imagine you have a special keyboard with the following keys: 

Key 1:  Prints 'A' on screen
Key 2: (Ctrl-A): Select screen
Key 3: (Ctrl-C): Copy selection to buffer
Key 4: (Ctrl-V): Print buffer on screen appending it after what has already been printed.

Find maximum numbers of A's that can be produced by pressing keys on the special keyboard N times. 
Example:
        Input - N = 7
        Output - 9
        Explaination - The best key sequence is key 1, key 1, key 1, key 2, key 3, key4, key 4.
        
        Input - N = 3
        Output - 3

Constraints:
        Time complexity - O(N^2)
        Space complexity - O(N)
        1 < N < 75
*/

/*
Approach 1 (in python) - 
    def optimalKeys(self, N):
        # code here
        def helper(N, count, temp):
            if N == 0:
                return count
            
            a = helper(N - 1, count + 1, temp)
            b = helper(N - 1, count + temp, temp)
            c = 0
            if N - 3 >= 0:
                temp = count
                c = helper(N - 3, count + temp, temp)
            
            # print(a, b, c)
            return max(max(a, b), c)
        
        return helper(N, 0, 0)

Time complexity - O(3^N)
*/

//Approach 2 (Efficient, using DP)
//Hint - We can observe that after some point, we will only using Ctrl + A, Ctrl + C and Ctrl + V to generate maximum number of As. This is called the break-point.
//Link to solution - https://www.geeksforgeeks.org/how-to-print-maximum-number-of-a-using-given-four-keys/

class Solution{
public:
    long long int optimalKeys(int N){
        // code here
        if(N <= 6)
            return N;
            
        long long int A[N + 1];
        for(int i = 0; i < 7; i++) {
            A[i] = i;
        } 
        for(int i = 7; i <= N; i++) {
            A[i] = 0; 
            for(int j = i - 3; j > 0; j--)
                A[i] = max(A[i], A[j]*(i - j - 1));
        }
        
        return A[N];
    }
};
