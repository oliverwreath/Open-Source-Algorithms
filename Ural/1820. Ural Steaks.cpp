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
	int k = 0; 
	cin >> n;
	cin >> k;  
	if(k >= n){
		cout << 2 << endl; 
	}else{
		cout << ceil(2.0*n/k) << endl; 
	}
	
	return 0;
}
