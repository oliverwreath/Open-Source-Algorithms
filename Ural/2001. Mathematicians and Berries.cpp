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
	int a1 = 0; 
	int b1 = 0; 
	int a3 = 0; 
	int b2 = 0; 
	int tmp = 0; 

	cin >> a1 >> b1 >> tmp >> b2 >> a3 >> tmp; 
	cout << a1 - a3 << " " << b1 - b2 << endl; 
	
	return 0;
}
