#include<iostream>

using namespace std;

//Recursive call function. O(2^n)
/*int step_count(int N) {
	if(N == 1)
		return 1;
	if(N == 2)
		return 2;
	else
		return step_count(N - 1) + step_count(N - 2);
}*/

//Faster dynamic programming function. O(n) 
int step_count(int N) {
	if(N < 3)
		return N;
	
	int a[N + 1];
	a[0] = 0; a[1] = 1; a[2] = 2;

	for(int i = 3; i <= N; i++) 
		a[i] = a[i - 1] + a[i - 2];
	
	return a[N];
}

int main() {
	int n;
	cin>>n;
	
	cout<<step_count(n)<<endl;
	return 0;
}
