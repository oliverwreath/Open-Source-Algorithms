
#include <iostream>
#include <algorithm>
#include <vector>
#include "stdlib.h"
#include <time.h>
using namespace std;


int main()
{
    int i = 0;
    int j = 0;
    long long num_of_bools = 9999999 ;
    int * a = new int [500001];
    bool * b = new bool [num_of_bools];

    a[0] = 0;
    b[0] = true ;

    for( i = 1 ; i < num_of_bools ; i++ )
    {
        b[i] = false ;
    }

    for( i = 1 ; i <= 500000 ; i++ )
    {
        a[i] = a[i-1] - i;
        if( a[i] > 0 && b[a[i]] != true )
        {
            b[a[i]] = true ;
        }
        else
        {
            a[i] = a[i-1] + i;
            b[a[i]] = true ;
        }
    }

    //
    while( 1 )
    {
        cin >> i ;
        if(i == -1)
        {
            break ;
        }
        cout << a[i] << endl ;
    }

	return 0 ;
}