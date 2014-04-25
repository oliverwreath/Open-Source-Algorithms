#include <iostream>
#include <string>

using namespace std; 

string mapping( char ch ){
	switch(ch){
		case ' ': return "%20";
		case '!': return "%21";
		case '$': return "%24";
		case '%': return "%25";
		case '(': return "%28";
		case ')': return "%29";
		case '*': return "%2a";
		default: return string(1, ch); 
	}
}

int main(){
	string str;
	while( getline(cin, str) ){
		int len = str.length();
		for( auto i = 0; i < len; i++ ){
			if( str[i] == '#' ){
				return 0;
			}
			cout << mapping( str[i] );
		}
		cout << endl;
	}

	return 0;
}
