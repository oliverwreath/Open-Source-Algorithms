

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack> 
#define F(i, a, b) for(int i = a; i <= b; i++)

using namespace std;

int C = 0; 
int G = 0; 
int hooks[21];
int weights[21];
int DP[21][15001];

int main() {
	//read stuff
	cin >> C >> G;

	F(i, 1, C)
	{
		cin >> hooks[i];
	}

	F(i, 1, G)
	{
		cin >> weights[i];
	}

	//calc
	DP[0][7500] = 1;
	F(i, 1, G)
	{
		F(j, 1, 15000)
		{
			if( DP[i-1][j] != 0 )
			{
				F(k, 1, C)
				{
					if(j+weights[i]* hooks[k] <= 15000)
					{
						DP[i][j+weights[i]* hooks[k] ] += DP[i-1][j];
					}
				}
			}
		}
	}


	//output
	cout << DP[G][7500] << endl ;

	system("pause");
    return 0;
}
