

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <windows.h>
#include "stdlib.h"
#include <time.h>
using namespace std;

typedef struct item
{
    long long value ; 
    long long weight ; 
}strItem;

    long long ** results ;
    strItem * items;
    clock_t start, finish, total;

    fstream fin;
    fstream fout;
    fstream fret;


bool cmpRatioDec(strItem x, strItem y)
{
    if( x.value * y.weight > y.value * x.weight  )
        return true ;
    else 
        return false ;
}

bool cmpWeightInc(strItem x, strItem y)
{
    if( x.weight < y.weight  )
        return true ;
    else 
        return false ;
}

long long function( long long i, long long v )
{
    if( results[i][v] != 0 )
    {
        cout << "result( " << i << ", " << v << " )" << endl ;
        return results[i][v];
    }
    else if( v - items[i].weight < 0 )
    {
        results[i][v] = function(i-1, v);
        return results[i][v];
    }
    else
    {
        results[i][v] = max( function(i-1, v), function(i-1, v-items[i].weight) + items[i].value );
        return results[i][v];
    }
}

int main()
{
    long n = 0 ; 
    long ** value ;
    long ** d ;

    cin >> n ; 
    value = new long * [n];
    d = new long * [n];
    for( int i = 0 ; i < n ; i++ )
    {
        value[i] = new long [i+1];
        d[i] = new long [i+1];
        for( int j = 0 ; j <= i ; j++ )
        {
            cin >> value[i][j] ;
            d[i][j] = 0 ;
        }
    }

    for( int i = n-1 ; i >=0 ; i-- )
    {
        if( i == n-1 )
        {
            for( int j = 0 ; j <= i ; j++ )
            {
                d[i][j] = value[i][j];
            }
        }
        else
        {
            for( int j = 0 ; j <= i ; j++ )
            {
                d[i][j] = max(d[i+1][j],d[i+1][j+1])+value[i][j];
            }
        }
    }

    cout << d[0][0] << endl ;
    
    //system("pause");

	return 0 ;
}