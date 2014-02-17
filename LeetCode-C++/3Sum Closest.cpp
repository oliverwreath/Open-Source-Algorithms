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

class Solution{
public:
	int threeSumClosest(vector<int> &num, int target){
		int len = num.size();
		if( len < 3 ){
			return 0; 
		}

		if( len < 4 ){
			return num[0] + num[1] + num[2]; 
		}

		sort(num.begin(), num.end()); 

		int sum = 0;
		int min = INT_MAX;
		int best = num[0]+num[1]+num[2];
		F( i, 0, len-3 ){
			if( i > 0 && num[i] == num[i-1] ){
				continue; 
			}
			sum += num[i];
			F( j, i+1, len-2 ){
				if( j > i+1 && num[j] == num[j-1] ){
					continue; 
				}
				sum += num[j];
				F( k, j+1, len-1 ){
					if( k > j+1 && num[k] == num[k-1] ){
						continue; 
					}
					sum += num[k];
					if( sum-target > min ){
						sum -= num[k];
						break; 
					}
					if( abs(sum-target) < min ){
						min = abs(sum-target);
						if( min == 0 ){
							return sum; 
						}
						best = sum;
					}
					sum -= num[k];
				}
				sum -= num[j];
			}
			sum -= num[i];
		}

		return best; 
	}
};
