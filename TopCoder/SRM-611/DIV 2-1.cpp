#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <sstream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <cstdio>
#include <cstring>
#include <climits>
#include <cfloat>
#include <cmath>
#include <stack>

using namespace std;

class Digit{
public:
	Digit(){
		this->cnt = 1;
	}
	Digit( int cnt ){
		this->cnt = cnt;
	}
	int getGap(){
		return snd - fst - 1;
	}
	int cnt = 0;
	int fst = 0;
	int snd = 0;
};

class InterestingNumber{
private:
	const string YES = "Interesting";
	const string NO = "Not interesting";
public:
	string isInteresting(string x){
		unordered_map<int, Digit> ht;

		for( auto i = 0; i < x.size(); i++ ){
			int digit = x[i] - '0';
			if( ht.find(digit) == ht.end() ){
				ht[digit] = Digit();
				ht[digit].fst = i;
			}else{
				ht[digit].cnt++;
				ht[digit].snd = i;
			}
		}

		for( auto digit = 0 ; digit < 10; digit++ ){
			if( ht.find(digit) != ht.end() ){
//				printf( "%d %d %d %d gap:%d\n", digit, ht[digit].cnt, ht[digit].fst, ht[digit].snd, ht[digit].getGap() );
			}
		}

		for( auto digit = 0 ; digit < 10; digit++ ){
			if( ht.find(digit) != ht.end() ){
				if( ht[digit].cnt == 2 ){
					if( ht[digit].getGap() == digit ){
						continue;
					}else{
						return NO;
					}
				}else{
					return NO;
				}
			}
		}

		return YES;
	}
};

int main(){
	InterestingNumber t = InterestingNumber();
	t.isInteresting("2002");
	assert(t.isInteresting("2002") == "Interesting");
	assert(t.isInteresting("1001") == "Not interesting");
	assert(t.isInteresting("41312432") == "Interesting");
	assert(t.isInteresting("611") == "Not interesting");
	assert(t.isInteresting("64200246") == "Interesting");
	assert(t.isInteresting("631413164") == "Not interesting");
	int m, n;
	while( cin >> m >> n ){

	}

	return 0;
}

