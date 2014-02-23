

#include <iostream>
using namespace std;

int main() {
    int t = 0;
	int n = 0;
	int * from;
	int * to;
	int max = 0;

	cin >> t ; 

	for( int i = 0; i < t; i++ )
	{
		cin >> n;
		from = new int [n]();
		to = new int [n]();
		for( int j = 0; j < n; j++ )
		{
			cin >> from[j];
			cin >> to[j];
			if(from[j] % 2 == 0)
			{
				from[j] = from[j] - 1;
			}
			if(to[j] % 2 == 0)
			{
				to[j] = to[j] - 1;
			}
			if( from[j] > to[j] )
			{
				int temp = from[j];
				from[j] = to[j];
				to[j] = temp;
			}
			if(max < to[j])
			{
				max = to[j];
			}
		}


		int * count = new int [max+1]();
		for( int j = 0; j < n; j++ )
		{
			for(int k = from[j]; k <= to[j]; k++)
			{
				count[k]++;
			}
		}
	
		int mx2 = count[1];
		for( int j = 1; j <= max; j++ )
		{
			if(mx2 < count[j])
			{
				mx2 = count[j];
			}
		}

		cout << mx2 * 10 << endl;


	}



	system("pause");
    return 0;
}
