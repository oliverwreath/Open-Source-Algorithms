#define F(i, a, b) for(unsigned i = a; i <= b; i++)
#define MAX2(a, b) a>b?a:b
#include <iostream>
#include <stdio.h>

using namespace std;

unsigned* DP;
unsigned len = 3000101;

unsigned calc( unsigned n ){
    if( n >= len ){
        if( n % 2 == 1 ){
            return calc(n + n/2 + 1) + 2;
        }
        else{
            return calc(n / 2) + 1;
        }
    }
    if( DP[n] != 0 ){
        return DP[n];
    }
    if( n % 2 == 1 ){
        DP[n] = calc(3 * n + 1) + 1;
        return DP[n];
    }
    else{
        DP[n] = calc(n / 2) + 1;
        return DP[n];
    }
}

unsigned maxCL( unsigned& i, unsigned& j ){
    unsigned max = 0;
    F(k, i, j){
        unsigned tmp = calc( k );
        max = MAX2(max, tmp);
    }
    return max;
}

int main(){
    DP = new unsigned [len]();
    DP[1] = 1;

    unsigned i;
    unsigned j;
    while( scanf("%u %u", &i, &j) != EOF ){
        cout << i << " " << j << " ";
        if( i < j ){
            cout << maxCL(i, j);
        }
        else{
            cout << maxCL(j, i);
        }
        cout << endl;
    }

    return 0;
}
