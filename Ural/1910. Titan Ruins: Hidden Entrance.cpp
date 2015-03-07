
#include <iostream>
#include <unordered_map>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>

#define STOP system("pause")  
#define file_r(x) freopen(x, "r", stdin)  
#define file_w(x) freopen(x, "w", stdout)  

using namespace std; 

int main(){
	int n = 0; 
	cin >> n;
	vector<int> vt = vector<int>(n, 0); 
	int tmp = 0;
	for(int i = 0; i <= n; i++){
		cin >> tmp;  
		vt[i] = tmp;
	}

	int sum = vt[0] + vt[1] + vt[2]; 
	int max = sum; 
	int idx = 2; 
	for(int i = 3; i < n; i++){
		sum += vt[i];
		sum -= vt[i-3];
		if(sum > max){
			max = sum; 
			idx = i; 
		}
	}

	cout << max << " " << idx << endl; 
	
	return 0;
}

