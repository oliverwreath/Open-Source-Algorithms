
#include <iostream>
#include <algorithm>
#include <vector>
#include "stdlib.h"
#include <time.h>
#include <String>
using namespace std;

int main()
{
    string * a ;
    string * b ;
    long ** results ;
    bool * resultMarking ;

    a = new string [105];
    b = new string [105];

    int length_of_a = 0 ;
    int length_of_b = 0 ;
    string tempString ;

    while( cin >> tempString )
    {
        //input init
        a[0] = tempString ;
        int i = 1 ;
        while( cin >> a[i] )
        {
            if( a[i] == "#" )
                break ;
            i++;
        }
        length_of_a = i ;
        i = 0 ;
        while( cin >> b[i] )
        {
            if( b[i] == "#" )
                break ;
            i++;
        }
        length_of_b = i ;

        ////test
        //for( int i = 0 ; i < length_of_a ; i++ )
        //{
        //    cout << a[i] << " " ;
        //}
        //cout << endl ;
        //for( int i = 0 ; i < length_of_b ; i++ )
        //{
        //    cout << b[i] << " " ;
        //}
        //cout << endl ;

        //algorithm comes
        results = new long * [length_of_a];
        for( int k = 0 ; k < length_of_a ; k++ )
        {
            results[k] = new long [length_of_b] ;
            memset(results[k], 0, sizeof(results[k]));
        }

        results[0][0] = a[0] == b[0] ? 1 : 0;
        for( int j = 1 ; j < length_of_b ; j++ )
        {
            long temp = 0 ;
            for( int j2 = 0 ; j2 <= j ; j2++ )
            {
                if( b[j2] == a[0] )
                {
                    temp = 1 ;
                    break ;
                }
            }
            results[0][j] = temp;
        }
        for( int i1 = 1 ; i1 < length_of_a ; i1++ )
        {
            long temp = 0 ;
            for( int i2 = 0 ; i2 <= i1 ; i2++ )
            {
                if( a[i2] == b[0] )
                {
                    temp = 1 ;
                    break ;
                }
            }
            results[i1][0] = temp;
        }
        //init 1,1-> length_of_a - 1, length_of_b - 1
        for( int i = 1 ; i < length_of_a ; i++ )
        {
            for( int j = 1 ; j < length_of_b ; j++ )
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

        //test
        //for( int i = 1 ; i < length_of_a ; i++ )
        //{
        //    for( int j = 1 ; j < length_of_b ; j++ )
        //    {
        //        cout << results[i][j] << " ";
        //    }
        //    cout << endl ;
        //}

        //algorithms read results 
        resultMarking = new bool [length_of_a];
        for( int r = 0 ; r < length_of_a ; r++ )
        {
            resultMarking[r] = false ;
        }
        ////test
        //for( int r = 0 ; r < length_of_a ; r++ )
        //{
        //    if( resultMarking[r] )
        //    {
        //        cout << "  - " << r << " -  " << endl ;

        //    }
        //}
              
        int i_of_a = length_of_a - 1 ;
        int j_of_b = length_of_b - 1 ;

        while(1)
        {
            
            if( i_of_a == 0 )
            {
                resultMarking[i_of_a] = true ;
                //cout << "i_of_a : " << i_of_a << " " << "j_of_b : " << j_of_b << endl ;
                break ;
            }
            else if( j_of_b == 0 )
            {
                for( int i = 0 ; i <= i_of_a ; i++ )
                {
                    if( a[i] == b[j_of_b] )
                    {
                        resultMarking[i] = true ;
                        //cout << "i_of_a : " << i_of_a << " " << "j_of_b : " << j_of_b << endl ;
                        break ;
                    }
                }
                break ;
            }
            else if( a[i_of_a] == b[j_of_b] )
            {
                resultMarking[i_of_a] = true ;
                //cout << "i_of_a : " << i_of_a << " " << "j_of_b : " << j_of_b << endl ;
                i_of_a -= 1;
                j_of_b -= 1;
            }
            else if( results[i_of_a][j_of_b] == results[i_of_a-1][j_of_b] )
            {
                i_of_a = i_of_a-1;
            }
            else 
            {
                j_of_b = j_of_b-1;
            }
        }
        //print
        bool first = true ;
        for( int r = 0 ; r < length_of_a ; r++ )
        {
            if( resultMarking[r] )
            {
                //cout << "  - " << r << " -  " << endl ;
                if( first )
                {
                    cout << a[r] ;
                    first = false ;
                }
                else
                {
                    cout << " " << a[r] ;
                }
            }
        }
        cout << endl ;

        //deletes
        delete [] resultMarking ;
        for( int k = 0 ; k < length_of_a ; k++ )
        {
            delete [] results[k] ;
        }
        delete [] results ;
    }

        //deletes
        delete [] a ;
        delete [] b ;

	return 0 ;
}