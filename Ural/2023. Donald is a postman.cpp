

#include <iostream>
#include <unordered_map>
#include <string>
#include <cmath>

using namespace std; 

int main(){
	int n = 0;
	int ret = 0; 
	unordered_map<char, int> map; 
	map['A'] = 1;
	map['P'] = 1;
	map['O'] = 1;
	map['R'] = 1;
	map['B'] = 2;
	map['M'] = 2;
	map['S'] = 2;
	map['D'] = 3;
	map['G'] = 3;
	map['J'] = 3;
	map['K'] = 3;
	map['T'] = 3;
	map['W'] = 3;
	cin >> n; 
	string str; 
	int currentPos = 1; 
	for(auto i = 1; i <= n; i++){
		cin >> str; 
		int pos = map[str[0]];
		ret += abs(currentPos - pos);
		currentPos = pos; 
	}
	cout << ret << endl;
	return 0; 
}
