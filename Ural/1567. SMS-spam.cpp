

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
	string str = "";
	getline(cin, str);
	unordered_map<char, int> ht;
	ht.reserve(30);
	ht['a'] = 1;
	ht['b'] = 2;
	ht['c'] = 3;
	ht['d'] = 1;
	ht['e'] = 2;
	ht['f'] = 3;
	ht['g'] = 1;
	ht['h'] = 2;
	ht['i'] = 3;
	ht['j'] = 1;
	ht['k'] = 2;
	ht['l'] = 3;
	ht['m'] = 1;
	ht['n'] = 2;
	ht['o'] = 3;
	ht['p'] = 1;
	ht['q'] = 2;
	ht['r'] = 3;
	ht['s'] = 1;
	ht['t'] = 2;
	ht['u'] = 3;
	ht['v'] = 1;
	ht['w'] = 2;
	ht['x'] = 3;
	ht['y'] = 1;
	ht['z'] = 2;
	ht['.'] = 1;
	ht[','] = 2;
	ht['!'] = 3;
	ht[' '] = 1;

	int ret = 0;
	for(int i = 0; i < str.length(); i++){
		ret += ht[str[i]];
	}

	cout << ret << endl;

	return 0;
}
