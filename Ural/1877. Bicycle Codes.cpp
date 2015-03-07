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
	int n1 = 0; 
	int n2 = 0; 
	cin >> n1;
	cin >> n2;  
	if(n1%2 == 0 || (n2%2 == 1)){
		cout << "yes" << endl; 
	}else{
		cout << "no" << endl; 
	}
	
	return 0;
}
