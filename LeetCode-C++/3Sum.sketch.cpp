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
	vector<vector<int> > threeSum(vector<int> &num){
		int len = num.size();
		if( len < 3 ){
			return vector<vector<int> >();
		}

		if( len < 4 ){
			if( num[0] + num[1] + num[2] == 0 ){
				sort(num.begin(), num.end());
				return vector<vector<int> >(1, num);
			}
		}

		sort(num.begin(), num.end());

		vector<vector<int> > ret; 
		int sum = 0;
		F( i, 0, len-3 ){
			if( i > 0 && num[i] == num[i-1] ){
				continue; 
			}
			sum += num[i];
			if( sum > 0 ){
				sum -= num[i];
				break;
			}
			F( j, i+1, len-2 ){
				if( j > i+1 && num[j] == num[j-1] ){
					continue; 
				}
				sum += num[j];
				if( sum > 0 ){
					sum -= num[j];
					break;
				}
				F( k, j+1, len-1 ){
					if( k > j+1 && num[k] == num[k-1] ){
						continue; 
					}
					sum += num[k];
					if( sum > 0 ){
						sum -= num[k];
						break;
					}
					if( sum == 0 ){
						vector<int> tmp = {num[i], num[j], num[k]};
						ret.push_back(tmp);
					}
					sum -= num[k];
				}
				sum -= num[j];
			}
			sum -= num[i];
		}

		return ret; 
	}
};
