

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
				to[j] = to[j] - 1;
			}
			if(max < to[j])
			{
				max = to[j];
			}
		}


		int * count = new int [max+1]();
		for( int k = 0; k < n; k++ )
		{
			for(int j = from[k]; j <= to[k]; j++)
			{
				count[j]++;
			}
		}
	
		int mx2 = count[1];
		for( int k = 1; k <= max; k++ )
		{
			if(mx2 < count[k])
			{
				mx2 = count[k];
			}
		}

		cout << mx2 * 10 << endl;


	}



	//system("pause");
    return 0;
}
