#define F(i, a, b) for(int i = a; i <= b; i++)
#define FB(i, a, b) for(int i = a; i >= b; i--)
#define MAX2(a, b) a>b?a:b
#define MIN2(a, b) a<b?a:b

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if( n < 2 ){
            return 0;
        }

        vector<int> left(n, 0);
        vector<int> right(n, 0);

        int min = prices[0];
        int max_profit = 0;
        F( i, 1, n-1 ){
            max_profit = MAX2( max_profit, prices[i] - min );
            left[i] = max_profit;
            min = MIN2( min, prices[i] );
        }

        int max = prices[n-1];
        max_profit = 0;
        FB( i, n-2, 2 ){
            max_profit = MAX2( max_profit, max - prices[i] );
            right[i] = max_profit;
            max = MAX2( max, prices[i] );
        }

        max_profit = 0;
        F( i, 1, n-3 ){
            max_profit = MAX2( max_profit, left[i] + right[i+1] );
        }
        F( i, n-2, n-1 ){
            max_profit = MAX2( max_profit, left[i] );
        }

        return max_profit;
    }
};
