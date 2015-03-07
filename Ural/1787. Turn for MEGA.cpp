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
	int tmp = 0;
	int ret = 0;  
	for(int i = 1; i <= k; i++){
		cin >> tmp; 
		ret += tmp; 
		if(ret > n){
			ret -= n; 
		}else{
			ret = 0;
		}
	}
	cout << ret << endl; 
	
	return 0;
}
