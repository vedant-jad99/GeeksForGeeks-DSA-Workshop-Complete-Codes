/*
Given three coordinate points A, B and C, find the missing point D such that ABCD can be a parallelogram. 
If there are multiple such points, find the lexicographically smallest coordinate.
Example:
        Input - A = (3, 2), B = (3, 4), C = (2, 2)
        Output - 2.000000 0.000000
        Explanation: There are two options for point D : (2, 4) and (2, 0) such that ABCD forms a parallelogram.
        Since (2, 0) is lexicographically smaller than (2, 4). Hence, (2, 0) is the answer.

Constraints:
        Time Complexity - O(1)
        Space Complexity - O(1)
        1 ≤ x, y ≤ 1000 , where x and y denote coordinates of points A, B and C.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<double> findPoint(int A[], int B[], int C[])
{
    vector<vector<double>> calc, ans;
    vector<double> temp1, temp2, temp3;
    for(int i = 0; i < 2; i++) {
        temp1.push_back((double)(A[i] + B[i])/2);
        temp2.push_back((double)(C[i] + B[i])/2);
        temp3.push_back((double)(C[i] + A[i])/2);
    }
    calc.push_back(temp1); calc.push_back(temp2); calc.push_back(temp3);
    temp1.clear(); temp2.clear(); temp3.clear();
    
    for(int i = 0; i < 2; i++) {
        temp1.push_back(calc[0][i] * 2 - C[i]);
        temp2.push_back(calc[1][i] * 2 - A[i]);
        temp3.push_back(calc[2][i] * 2 - B[i]);
    }
    ans.push_back(temp1); ans.push_back(temp2); ans.push_back(temp3);
    
    sort(ans.begin(), ans.end());
    return ans[0];
}

int main() {
    int A[2], B[2], C[2];

    for(int i = 0; i < 6; i++) 
        if(i < 2)
            cin>>A[i];
        else if(i < 4)
            cin>>B[i - 2];
        else
            cin>>C[i - 4];

    vector<double> res = findPoint(A, B, C);

    cout<<res[0]<<" "<<res[1]<<"\n";
    return 0;
}