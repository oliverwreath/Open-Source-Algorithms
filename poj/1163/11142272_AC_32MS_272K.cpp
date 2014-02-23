
#include <iostream>
#include <algorithm>
#include <vector>
#include "stdlib.h"
#include <time.h>
using namespace std;

int main()
{
    int n = 0 ; 
    int ** value ;
    int ** d ;

    cin >> n ; 
    //value = new int * [n];
    d = new int * [n];
    for( int i = 0 ; i < n ; i++ )
    {
        //value[i] = new int [i+1];
        d[i] = new int [i+1];
        for( int j = 0 ; j <= i ; j++ )
        {
            //cin >> value[i][j] ;
            cin >> d[i][j];
        }
    }

    for( int i = n-2 ; i >=0 ; i-- )
    {
        for( int j = 0 ; j <= i ; j++ )
        {
            d[i][j] += max(d[i+1][j],d[i+1][j+1]);
        }
    }

    cout << d[0][0] << endl ;

	return 0 ;
}