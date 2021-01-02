#include <iostream>
#include <map>
#include <vector>
#include <iterator>

using namespace std;

bool findPair(vector<int> arr, int target) {
	map<int, int> content;
	map<int, int>::iterator it;

	for(unsigned int i = 0; i < arr.size(); i++) {
		it = content.find(target - arr[i]);
		if(it != content.end())
			return true;
		else
			content.insert({arr[i], 0});
	}

	return false;
}

int main() {
	int n, dummy, k;
	vector<int> arr;
	cin>>n;

	for(int i = 0; i < n; i++) {
		cin>>dummy;
		arr.push_back(dummy);
	}
	cin>>k;
	cout<<"\n\n"<<findPair(arr, k)<<"\n";
}
