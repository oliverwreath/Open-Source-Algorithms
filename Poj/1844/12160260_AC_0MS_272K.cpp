

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack> 
#define F(i, a, b) for(int i = a; i <= b; i++)
#define MAX3(a, b, c) (a>b?a:b)>c?(a>b?a:b):c

using namespace std;

int s = 0;
int DP[100001];

int main() {
	//while( scanf("%d",&cash)!=EOF )

	//read stuff
	while(scanf("%d", &s) != EOF)
	{
		int sum = 0;
		F(i, 1, s)
		{
			sum += i;
			if( (sum == s) || (sum > s && ( (sum - s) % 2 == 0)) )
			{
				cout << i << endl;
				break;
			}
		}
	}
	

	system("pause");
    return 0;
}
