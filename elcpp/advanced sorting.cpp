#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std; 

bool comp( pair<int, string> p1, pair<int, string> p2 ){
    return (p1.first <= p2.first);
}

int main(){
    int key = 0;
	string val = "";
    vector<pair<int, string>> vt;
	
	while( cin >> key ){
		cin >> val;
		vt.push_back( make_pair(key, val) );
	}
	
	sort( vt.begin( ), vt.end( ), comp );
	
	for(auto it = vt.begin(); it != vt.end(); ++it){
		cout << (*it).second << " ";
	}
	
	return 0;	
}
