

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
	//filtering out the primes 
	int len = 163842; 
	vector<bool> array (len, true);
	int end = (int)sqrt(len);
	array[0] = false; 
	array[1] = false; 
	for(int i = 2; i <= end; i++){
		if(array[i]){
			int index = i+i; 
			int step = i; 
			while(index < len){
				array[index] = false; 
				index += step;
			}
		}
	}

	//populate primeArray
	int primeArray [15001] = {0}; 
	int idx = 1; 
	for(int i = 2; i <= len-1; i++){
		if(array[i]){
			primeArray[idx++] = i; 
		}
	}

	//retrieve results 
	int k = 0;
	cin >> k; 
	int n = 0;
	for(int i = 1; i <= k; i++){
		cin >> n;  
		cout << primeArray[n] << endl; 
	}
	
	return 0;
}
