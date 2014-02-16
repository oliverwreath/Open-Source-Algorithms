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
	int firstMissingPositive(int A[], int n) {
		if( n < 1 ){
			return 1;
		}
		if( n < 2 ){
			if( A[0] != 1 ){
				return 1;
			}else{
				return 2;
			}
		}

		int* marker = new int [n+1]();
		for( int i = 0; i < n; i++ ){
			if( A[i] > 0 && A[i] <= n ){
				marker[A[i]] = 1;
			}
		}

		for( int j = 1; j <= n; j++ ){
			if( marker[j] == 0 ){
				return j;
			}
		}

		return n+1;
	}
};
