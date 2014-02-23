
#include <iostream>
#include <algorithm>
#include <vector>
#include "stdlib.h"
#include <time.h>
using namespace std;


int main()
{
    long long num_of_scenarios = 0 ;
    long long * array_of_results ;

    cin >> num_of_scenarios ;

    array_of_results = new long long [50];

    array_of_results[0] = 1;
    array_of_results[1] = 2;

    for( int i = 2 ; i < 50 ; i++ )
    {
        array_of_results[i] = array_of_results[i-1] + array_of_results[i-2] ;
    }

    for( int i = 0 ; i < num_of_scenarios ; i++ )
    {
        long long tempI = 0;
        cin >> tempI;
        cout << "Scenario #" << i+1 << ":" << endl;
        cout << array_of_results[tempI] << endl ;
    }
    cout << endl ;

	return 0 ;
}