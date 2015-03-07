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
	int n3 = 0; 

	// int index1 = 0; 
	cin >> n1; 
	vector<int> v1(n1, 0); 
	for(int i = 0; i < n1; i++){
		cin >> v1[i];
	}
	cin >> n2; 
	vector<int> v2(n2, 0); 
	for(int i = 0; i < n2; i++){
		cin >> v2[i];
	}
	cin >> n3; 
	vector<int> v3(n3, 0); 
	for(int i = 0; i < n3; i++){
		cin >> v3[i];
	}

	int j = 0; 
	int k = 0; 
	int ctr = 0; 
	for(int i = 0; i < n1; i++){
		while(j < n2 && v2[j] < v1[i]){
			j++;
		}
		while(k < n3 && v3[k] < v1[i]){
			k++;
		}
		if(v1[i] == v2[j] && (v2[j]==v3[k]) ){
			ctr++; 
		}
	}
	cout << ctr << endl; 
	
	return 0;
}
