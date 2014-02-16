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
#include <unordered_map>
#include <tuple>
#include <iterator>
#include <stack>
#include <algorithms>

class Solution {
public:
	bool jumping(int A[], int& n, int max){		
		F( i, 0, max ){
			if(A[i] + i > max){
				max = A[i]+i;
				if( max >= n-1 ){
					return true;
				}
			}
		}

		return false;
	}

	bool canJump(int A[], int n) {
		if( n == 1 ){
			return true;
		}

		bool ret = jumping(A, n, 0);

		return ret;
	}
};
