#define F(i, a, b) for(int i = a; i <= b; i++)
#define FB(i, a, b) for(int i = a; i >= b; i--)
#define MAX2(a, b) a>b?a:b
#define MIN2(a, b) a<b?a:b

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
	int singleNumber(int A[], int n) {
		int len = n; 
		unordered_set<int> st = unordered_set<int>();
		long long sum = 0; 
		for( auto iter = A; iter != A+n; iter++ ){
			sum += *iter;
			st.insert(*iter);
		}

		long long setSum = 0;
		for( const int &i : st ){
			setSum += i;
		}

		long long ret = setSum - sum + setSum * 2;
		return (int)(ret/2);
	}
};
