#define F(i, a, b) for(int i = a; i <= b; i++)
#define FF(i, a, b) for( i = a; i <= b; i++)
#define F3(i, a, b) for(int i = a; i <= b; i+=3)
#define FB(i, a, b) for(int i = a; i >= b; i--)
#define MAX2(a, b) a>b?a:b
#define MAX3( a, b, c ) a>b?(a>c?a:c):(b>c?b:c)
#define MIN2(a, b) a<b?a:b

#include <iostream>
#include <vector>
#include <unordered_set>
#include <tuple>
#include <iterator>
#include <stack>

class Solution {
public:
	//methods
	void swap( vector<int>& num, int& i, int& j ){
		int tmp = num[i];
		num[i] = num[j];
		num[j] = tmp;
		return ;
	}

	void nextPermutation(vector<int> &num) {
		int len = num.size();
		if( len < 2 ){
			return ;
		}

		FB( i, len-2, 0 ){
			if( num[i] < num[i+1] ){
				F( j, i+1, len-1 ){
					if( j == len-1 || num[j+1] <= num[i] ){
						swap(num, i, j);
						reverse( num.begin()+i+1, num.end() );
						return ;
					}
				}
			}
		}

		reverse( num.begin(), num.end() );
		return ;
	}
};
