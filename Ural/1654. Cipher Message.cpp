#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <sstream>
#include <algorithm>
#include <unordered_set>
#include <cstdio>
#include <cstring>
#include <climits>
#include <cfloat>
#include <cmath>
#include <stack>
#include <set>
#include <list>

using namespace std;

int main(){
	string str;
	while( cin >> str ){
		stack<char> st;
		for( auto ch : str ){
			if( st.empty() ){
				st.push(ch);
			}else{
				if( st.top() == ch ){
					st.pop();
				}else{
					st.push(ch);
				}
			}
		}

		int len = st.size();
		char *chAry = new char [len]();
		int idx = len - 1;
		while( !st.empty() ){
			chAry[idx--] = st.top();
			st.pop();
		}

		for( int i = 0; i < len; i++ ){
			cout << chAry[i];
		}
		cout << endl;
	}

	return 0;
}


