

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack> 
#include <math.h>

#define F(i, a, b) for(int i = a; i <= b; i++)
#define MAX3(a, b, c) (a>b?a:b)>c?(a>b?a:b):c

using namespace std;

int n = 0;
string string_s;
char * s;
char * rs;
int ** dp;

int main() {
	//while( scanf("%d",&cash)!=EOF )
	while( scanf_s("%d",&n)!=EOF )
	{
	//read stuff
		s = new char[n+1];
		rs = new char[n+1];
		dp = new int * [n+1];
		F(i, 0, n)
		{
			dp[i] = new int [n+1]();
		}

		cin >> string_s;
		F(i, 1, n)
		{
			s[i] = string_s.at(i-1);
			rs[n + 1 - i] = s[i];
		}

		//F(i, 1, n)
		//{
		//	printf("%c", s[i]);
		//}

		//cout << endl;

		//F(i, 1, n)
		//{
		//	printf("%c", rs[i]);
		//}

		F(i, 1, n)
		{
			F(j, 1, n)
			{
				dp[i][j] = MAX3( dp[i-1][j], dp[i][j-1], ( (s[i] == rs[j]? 1:0) + dp[i-1][j-1] ) );
			}
		}

		printf("%d", n - dp[n][n]);

		delete s, rs, dp;
	}

	system("pause");
    return 0;
}
