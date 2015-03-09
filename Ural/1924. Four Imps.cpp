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
	if( n%2==0 ){
		if(n/2%2 == 1){
			cout << "grimy" << endl;
		}else{
			cout << "black" << endl;
		}
	}else{
		if(n/2%2 == 0){
			cout << "grimy" << endl;
		}else{
			cout << "black" << endl;
		}
	}
	
	return 0;
}

