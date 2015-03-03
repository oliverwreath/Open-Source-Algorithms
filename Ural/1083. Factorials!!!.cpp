

#include <iostream>
#include <unordered_map>
#include <string>
#include <cmath>

using namespace std; 

int main(){
	int n = 0; 
	cin >> n; 
	string str = "";
	cin >> str; 
	int k = str.length(); 

	int begin = n; 
	int end = n % k; 
	if(end == 0) end = k; 
	int ret = 1; 
	for(int i = begin; i >= end; i=i-k){ 
		ret *= i; 
	}

	cout << ret << endl;
	return 0; 
}
