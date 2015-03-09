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
	int m = 0;
	int n = 0;
	cin >> m >> n; 
	int ret = (m-1) + (n-1) + (m-1) * (n-1);

	if(ret%2 == 1){
		cout << "[:=[first]" << endl; 
	}else{
		cout << "[second]=:]" << endl; 
	}
	
	return 0;
}
