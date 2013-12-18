#define F(i, a, b) for(int i = a; i <= b; i++)
//#define FB(i, a, b) for(int i = a; i >= b; i--)
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

        int max_profit = 0;

        F( i, 1, n-1 ){
            if( prices[i] > prices[i-1] ){
                max_profit += prices[i] - prices[i-1];
            }
        }

        return max_profit;
    }
};
