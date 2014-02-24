
#include <iostream>
#include <algorithm>
#include <vector>
#include "stdlib.h"
#include <time.h>
#include <String>
using namespace std;


int main()
{
    string a, b;
    long long ** results ;
    long long temp = 0 ;

    while(cin >> a >> b )
    {
        results = new long long * [a.size()];
        for( int i = 0 ; i < a.size() ; i++ )
        {
            results[i] = new long long [b.size()];
        }

        results[0][0] = a[0] == b[0] ? 1 : 0 ;
        for( int j = 0 ; j < b.size() ; j++ )
        {
            temp = 0 ;
            for( int i = 0 ; i <= j ; i++ )
            {
                if( b[i] == a[0] )
                {
                    temp = 1;
                    break ;
                }
            }
            results[0][j] = temp ;
        }
        for( int i = 0 ; i < a.size() ; i++ )
        {
            temp = 0 ;
            for( int j = 0 ; j <= i ; j++ )
            {
                if( a[i] == b[0] )
                {
                    temp = 1;
                    break ;
                }
            }
            results[i][0] = temp ;
        }

        //
        for( int i = 1 ; i < a.size() ; i++ )
        {
            for( int j = 1 ; j < b.size() ; j++ )
            {
                if( a[i] == b[j] )
                {
                    results[i][j] = results[i-1][j-1] + 1 ;
                }
                else
                {
                    results[i][j] = max( results[i-1][j], results[i][j-1] );
                }
            }
        }
        cout << results[a.size()-1][b.size()-1] << endl ;
    }


	return 0 ;
}