#include <iostream>

using namespace std;

int maxSubarraySum(int arr[], int n){
    int max_sum = arr[0];
    int look_ahead = 0;
    for(int i = 0; i < n; i++) {
        look_ahead += arr[i];
        if(look_ahead > max_sum)
            max_sum = look_ahead;
        if(look_ahead < 0)
            look_ahead = 0;
    }
    return max_sum;
}

int main() {
    int n;
    cin>>n;

    int a[n];
    for(int i = 0; i < n; i++) {
        cin>>a[i];
    }

    cout<<"\n"<<maxSubarraySum(a, n)<<endl;
    return 0;
}