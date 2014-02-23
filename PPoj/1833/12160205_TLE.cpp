

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
	cin >> t;
	F(m, 1, t)
	{
		cin >> n >> k;
		aArray = new int [n];
		F(l, 0, n-1)
		{
			cin >> aArray[l];
		}


		//calc
		F(l, 1, k)
		{
			next_permutation( aArray, aArray+n );
		}



		//output
		F(l, 0, n-1)
		{
			cout << aArray[l] << ' ';
		}
		cout << endl;
	}

	system("pause");
    return 0;
}
