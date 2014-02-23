

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack> 
#define F(i, a, b) for(int i = a; i <= b; i++)
#define MAX3(a, b, c) (a>b?a:b)>c?(a>b?a:b):c

using namespace std;

int t = 0;
int n = 0;
int k = 0;
int * aArray;


int main() {
	//while( scanf("%d",&cash)!=EOF )

	//read stuff
	scanf("%d", &t);
	F(m, 1, t)
	{
		scanf("%d %d", &n, &k);
		aArray = new int [n];
		F(l, 0, n-1)
		{
			scanf("%d", &aArray[l]);
		}

		//calc
		F(l, 1, k)
		{
			next_permutation( aArray, aArray+n );
		}

		//output
		F(l, 0, n-1)
		{
			printf("%d ", aArray[l]);
		}
		printf("\n");
	}

	system("pause");
    return 0;
}
