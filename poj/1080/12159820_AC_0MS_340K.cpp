

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack> 
#define F(i, a, b) for(int i = a; i <= b; i++)
#define MAX3(a, b, c) (a>b?a:b)>c?(a>b?a:b):c

using namespace std;

int t = 0;
int len1 = 0;
int len2 = 0;
char gene1[110];
char gene2[110];
int DP[110][110];

const int table[5][5] = {
    {5,-1,-2,-1,-3},
    {-1,5,-3,-2,-4},
    {-2,-3,5,-2,-2},
    {-1,-2,-2,5,-1},
    {-3,-4,-2,-1,0},
};

int scoring(char a, char b)
{
	string s = "ACGT-";
	int indx1 = s.find(a);
	int indx2 = s.find(b);
	return table[indx1][indx2];
}

int main() {
	//while( scanf("%d",&cash)!=EOF )

	//read stuff
	cin >> t;
	F(k, 1, t)
	{
		cin >> len1;
		F(l, 1, len1)
		{
			cin >> gene1[l];
		}

		cin >> len2;
		F(l, 1, len2)
		{
			cin >> gene2[l];
		}



		//calc
		DP[0][0] = 0;
		F(i, 1, len1)
		{
			DP[i][0] = scoring( gene1[i], '-')+DP[i-1][0];
		}

		F(j, 1, len2)
		{
			DP[0][j] = scoring( gene2[j], '-')+DP[0][j-1];
		}

		F(i, 1, len1)
		{
			F(j, 1, len2)
			{
				DP[i][j] = MAX3( DP[i-1][j]+scoring(gene1[i], '-'),  DP[i][j-1]+scoring(gene2[j], '-'), DP[i-1][j-1]+scoring(gene1[i], gene2[j]) );
			}
		}



		//output
		cout << DP[len1][len2] << endl;
	}

	system("pause");
    return 0;
}
