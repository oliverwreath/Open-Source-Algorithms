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
	int maxArea(vector<int> &height) {
		int len = height.size();
		int low = 0;
		int high = len-1;

		int ret = INT_MIN; 
		while(high > low){
			int tmp = ( high - low) * min(height[high], height[low]);
			ret = tmp>ret?tmp:ret;
			if( height[high] > height[low] ){
				low++;
			}else{
				high--;
			}
		}

		return ret; 
	} 
};
