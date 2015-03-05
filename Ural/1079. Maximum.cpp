

#include <iostream>
#include <unordered_map>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>

using namespace std; 

int main(){
	int len = 100000; 
	int a [len] = {0};
	a[0] = 0;
	a[1] = 1; 
	int s [len] = {0};
	s[0] = 0;
	s[1] = 1;
	int maximum = 0; 
	for(int i = 1; i <= 49999; i++){
		a[2*i] = a[i];
		maximum = max(maximum, a[2*i]); 
		s[2*i] = maximum; 
		a[2*i+1] = a[i] + a[i+1];
		maximum = max(maximum, a[2*i+1]); 
		s[2*i+1] = maximum; 
	}

	int n = 0; 
	while(cin >> n){
		if(n == 0){
			return 0;
		}
		cout << s[n] << endl; 
	}
	
	return 0;
}
