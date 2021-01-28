/*
Given an array of size n, find the smallest positive integer value that cannot be represented as sum of some elements from the array.
Ex.
	Input - Array = [1, 10, 3, 11, 6, 15]
	Output - 2
	Explanation - 2 is the smallest integer value that cannot be represented as sum of elements from the array.

	Input - Array = [1, 1, 1]
	Output - 4
	Explanation - 1 is present in the array, 2 can be created by combining two 1s, 3 can be created by combining three 1s, 4 is the smallest integer value that cannot be represented as sum of elements from the array.

Constraints - 
	Time complexity - O(nlog(n))
	Space complexity - O(1)
	
	1 ≤ n ≤ 10^6
	1 ≤ array[i] ≤ 10^9
*/

#include<iostream>
#include<vector>
#include<algorithm>

long long smallestPositive(std::vector<long long> array, int n) {
	long long count = 1;
	sort(array.begin(), array.end());
	for(int i = 0; i < n; i++) {
		if(count < array[i])
			return count;
		else
			count += array[i];
	}
	return count;
}

int main() {
	int n, tmp;
	std::cin>>n;
	std::vector<long long> array;
	for(int i = 0; i < n; i++) {
		std::cin>>tmp;
		array.push_back(tmp);
	}

	std::cout<<"The smallest positive integer: "<<smallestPositive(array, n)<<"\n";	
	return 0;
}
