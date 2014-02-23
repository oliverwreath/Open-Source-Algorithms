
#include <iostream>
#include <algorithm>
#include <vector>
#include "stdlib.h"
#include <time.h>
using namespace std;

typedef struct triple
{
    long long a;
    long long b;
    long long c;
}tri;

int main()
{
    long long a = 0;
    long long b = 0;
    long long c = 0;
    long long table [21][21][21] = {0} ;
    //tri triTable [99999] ;

    for( a = 0 ; a < 21 ; a++ )
    {
        for( b = 0 ; b < 21 ; b++ )
        {
            table[a][b][0] = 1 ;
        }
    }

    for( b = 0 ; b < 21 ; b++ )
    {
        for( c = 0 ; c < 21 ; c++ )
        {
            table[0][b][c] = 1 ;
        }
    }

    for( c = 0 ; c < 21 ; c++ )
    {
        for( a = 0 ; a < 21 ; a++ )
        {
            table[a][0][c] = 1 ;
        }
    }

    //
    for( a = 1 ; a < 21 ; a++ )
    {
        for( b = 1 ; b < 21 ; b++ )
        {
            for( c = 1 ; c < 21 ; c++ )
            {
                if (a < b && b < c)
                {
                    table[a][b][c] = table[a][b][c-1] + table[a][b-1][c-1] - table[a][b-1][c];
                }
                else
                {
                    table[a][b][c] = table[a-1][b][c] + table[a-1][b-1][c] + table[a-1][b][c-1] - table[a-1][b-1][c-1];
                }
            }
        }
    }

    while( 1 )
    {
        cin >> a >> b >> c ;
        if( a == -1 && b == -1 && c == -1 )
        {
            break ;
        }
        if( a <= 0 || b <= 0 || c <= 0)
        {
            cout << "w(" << a << ", " << b << ", " << c << ") = " << 1 << endl ;
        }
        else if( a > 20 || b > 20 || c > 20)
        {
            cout << "w(" << a << ", " << b << ", " << c << ") = " << table[20][20][20] << endl ;
        }else 
        {
            cout << "w(" << a << ", " << b << ", " << c << ") = " << table[a][b][c] << endl ;
        }   
    }

	return 0 ;
}