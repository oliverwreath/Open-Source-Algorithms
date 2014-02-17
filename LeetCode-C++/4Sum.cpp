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
	vector<vector<int> > fourSum(vector<int> &num, int target){
		int len = num.size();
		if( len < 4 ){
			return vector<vector<int> >();
		}

		if( len < 5 ){
			if( num[0] + num[1] + num[2] + num[3] == target ){
				sort(num.begin(), num.end());
				return vector<vector<int> >(1, num);
			}
		}

		sort(num.begin(), num.end());

		vector<vector<int> > ret; 
		int sum = 0;
		F( i, 0, len-4 ){
			if( i > 0 && num[i] == num[i-1] ){
				continue; 
			}
			sum += num[i];

			F( j, i+1, len-3 ){
				if( j > i+1 && num[j] == num[j-1] ){
					continue; 
				}
				sum += num[j];

				int left = j+1;
				int right = len-1;
				
				while( left < right ){
					if( left > j+1 && num[left] == num[left-1] ){
						left++;
						continue; 
					}
					if( right < len-1 && num[right] == num[right+1] ){
						right--;
						continue; 
					}

					int tmpSum = sum + num[left] + num[right];
					if( tmpSum == target ){
						vector<int> tmp = {num[i], num[j], num[left], num[right]};
						ret.push_back(tmp);
						left++;
						right--;
					}else if( tmpSum < target ){
						left++;
					}else{
						right--;
					}
				}

				sum -= num[j];
			}
			sum -= num[i];
		}

		return ret; 
	}
};
