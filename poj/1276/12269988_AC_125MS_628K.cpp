

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack> 
#include <math.h>

#define F(i, a, b) for(int i = a; i <= b; i++)
#define FB(i, a, b) for(int i = a; i >= b; i--)
#define MAX3(a, b, c) (a>b?a:b)>c?(a>b?a:b):c
#define MAXDP 100001 

using namespace std;

int cash = 0;
int n = 0;

int main() {
	while( scanf_s("%d",&cash)!=EOF )
	{
		scanf_s("%d",&n);

		if(cash == 0 || (n == 0) ){
			if( n > 0 ){
				F(i, 1, n){
					int tt = 0;
					scanf_s("%d %d",&tt, &tt);
				}
			}
			printf("%d\n",0);
			continue;
		}

		vector<int> money;
		int dp [MAXDP] = {};

		int tmp = 0;
		int tmpValue = 0;
		int k = 0;
		F(i, 1, n){
			scanf_s("%d",&tmp);
			scanf_s("%d",&tmpValue);
			k = (int)(log((double)tmp+1)/log((double)2));
			
			F(i, 0, k-1){
				money.push_back( pow((double)2, i)*tmpValue );
			}
			money.push_back( (tmp-pow((double)2, k)+1)*tmpValue ); 
		}

		F(i, 0, money.size()-1 ){
			FB(j, cash, 1){
				if( j-money.at(i) >= 0 ){
					dp[j] = max( dp[j], dp[j-money.at(i)] + money.at(i) );
				}
			}
		}

		printf( "%d\n", dp[cash] );
	}

	system("pause");
    return 0;
}
