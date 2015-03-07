

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
	if( n < 5 ){
		cout << "few" << endl;
	}else if( n < 10 ){
		cout << "several" << endl;
	}else if( n < 20 ){
		cout << "pack" << endl;
	}else if( n < 50 ){
		cout << "lots" << endl;
	}else if( n < 100 ){
		cout << "horde" << endl;
	}else if( n < 250 ){
		cout << "throng" << endl;
	}else if( n < 500 ){
		cout << "swarm" << endl;
	}else if( n < 1000 ){
		cout << "zounds" << endl;
	}else{
		cout << "legion" << endl;
	}
	
	return 0;
}
