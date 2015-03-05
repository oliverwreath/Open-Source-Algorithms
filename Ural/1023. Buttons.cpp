

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
	int n = 0; 
	cin >> n; 
	for( int i = 3; i <= n; i++ ){
		if(n%i == 0){
			cout << i-1 << endl;
			break; 
		}
	}
	
	return 0;
}
