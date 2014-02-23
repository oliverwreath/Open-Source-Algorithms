
#include <iostream>
#include <algorithm>
#include <vector>
#include "stdlib.h"
#include <time.h>
#include <String>
using namespace std;

char ** graph ;
int x = 0 ;
int y = 0 ;
int x_of_man = 0 ;
int y_of_man = 0 ;

void mark_accesible_tile(char ** graph, int x, int y, int x_of_now, int y_of_now )
{
    //cout << x_of_now << "  " << y_of_now << endl ;
    if( x_of_now >= 0 && x_of_now < x && y_of_now >= 0 && y_of_now < y )
    {
        //cout << "IN IF : " << x_of_now << "  " << y_of_now << endl ;
        if( (graph[x_of_now][y_of_now] == '@') || (graph[x_of_now][y_of_now] == '#') )
        {
            //cout << "IN '@' '#' : " << x_of_now << "  " << y_of_now << endl ;
            //cout << "graph value" << graph[x_of_now][y_of_now] << endl ;
            return ;
        }
        else if( graph[x_of_now][y_of_now] == '.' )
        {
            //cout << "IN '.' : " << x_of_now << "  " << y_of_now << endl ;
            graph[x_of_now][y_of_now] = '@';
            mark_accesible_tile( graph, x, y, x_of_now + 1, y_of_now );
            mark_accesible_tile( graph, x, y, x_of_now - 1, y_of_now );
            mark_accesible_tile( graph, x, y, x_of_now, y_of_now + 1 );
            mark_accesible_tile( graph, x, y, x_of_now, y_of_now - 1 );
            return ;
        }
    }
    else 
    {
        return ;
    }
}

int main()
{


    while( cin >> y >> x )
    {
        x_of_man = 0 ;
        y_of_man = 0 ;

        if( x == 0 && y == 0 )
        {
            break ;
        }
        
        graph = new char * [x];
        for( int i = 0 ; i < x ; i++ )
        {
            graph[i] = new char [y];
        }

        //input

        for( int i = 0 ; i < x ; i++ )
        {
            for( int j = 0 ; j < y ; j++ )
            {
                cin >> graph[i][j] ;
                if( graph[i][j] == '@' )
                {
                    x_of_man = i ;
                    y_of_man = j ;
                }
            }
        }

        //mark
        mark_accesible_tile( graph, x, y, x_of_man + 1, y_of_man );
        mark_accesible_tile( graph, x, y, x_of_man - 1, y_of_man );
        mark_accesible_tile( graph, x, y, x_of_man, y_of_man + 1 );
        mark_accesible_tile( graph, x, y, x_of_man, y_of_man - 1 );

        //test data
        //for( int i = 0 ; i < x ; i++ )
        //{
        //    for( int j = 0 ; j < y ; j++ )
        //    {
        //        cout << graph[i][j] ;
        //    }
        //    cout << endl ;
        //}

        long long ret = 0 ;
        for( int i = 0 ; i < x ; i++ )
        {
            for( int j = 0 ; j < y ; j++ )
            {
                if( graph[i][j] == '@' )
                    ret = ret + 1 ;
            }
        }

        cout << ret << endl ;

        for( int i = 0 ; i < x ; i++ )
        {
            delete [] graph[i];
        }
        delete [] graph;
    }


	return 0 ;
}