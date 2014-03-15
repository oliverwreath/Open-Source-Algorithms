#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <unordered_map>

using namespace std;

typedef struct pair{
	string number; 
	int value;
	
	pair( string a, int b ){
		number = a; 
		value = b;
	}
}pa;

bool isLarger( pa a, pa b ){
	if( a.value > b.value ){
		return true; 
	}else{
		return false; 
	}
}

int main(){
	string s;
	vector<pa> vt;
	unordered_map<string, int> ht = unordered_map<string, int>();
	while( cin >> s ){
		stringstream st; 
		string a;
		int b;
		a = s.substr(0, 4);
		st << s.substr(5);
		st >> b;
		if( ht.find(a) == ht.end() ){
			ht[a] = b;
			vt.push_back( pa(a, b) );
		}else{
			ht[a] = ht[a] < b? b: ht[a];
		}
	}
	
	for( int i = 0; i < vt.size(); i++ ){
		vt[i].value = ht[vt[i].number];
	}
	
	sort( vt.begin(), vt.end(), isLarger );
	
	for( int i = 0; i < vt.size(); i++ ){
		cout << vt[i].number << " " << vt[i].value << endl ;
	}
	
	
	return 0;	
}
