#define MAX2(a, b) a>b?a:b

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int lcs( string& a, string& b );

int agtc( string& a, string& b );

void reverseString( string& a );

//1

//10
//1 -1 2 2 3 -3 4 -4 5 -5

int MSS( int arr [], int& nn ){
    int sum = 0;
    int max = INT_MIN;
    for( int j = 0; j <= nn-1; j++ ){
        sum += arr[j];
        if( sum > max ){
            max = sum;
        }
        if( sum < 0 ){
            sum = 0;
        }
    }
    return max;
}

int M2SS( int arr [], int& nn ){
    int sum;
    int max;
    int max2;
    int retMax = INT_MIN; 
    for( int i = 0; i <= nn-2; i++ ){
        sum = 0;
        max = INT_MIN;
        for( int j = 0; j <= i; j++ ){
            sum += arr[j];
            if( sum > max ){
                max = sum;
            }
            if( sum < 0 ){
                sum = 0;
            }
        }
        sum = 0;
        max2 = INT_MIN;
        for( int j = i+1; j <= nn-1; j++ ){
            sum += arr[j];
            if( sum > max2 ){
                max2 = sum;
            }
            if( sum < 0 ){
                sum = 0;
            }
        }
        retMax = MAX2( retMax, (max + max2) );
    }
    return retMax ;
}

int* MemLtoR;
int* MemRtoL;

int MSSTDLtoR( int arr [], int& nn ){
    int sum = 0;
    int max = INT_MIN;
    MemLtoR = new int [nn];
    for( int j = 0; j <= nn-1; j++ ){
        sum += arr[j];
        if( sum > max ){
            max = sum;
        }
        MemLtoR[j] = max;
        if( sum < 0 ){
            sum = 0;
        }
    }
    return max;
}

int MSSTDRtoL( int arr [], int& nn ){
    int sum = 0;
    int max = INT_MIN;
    MemRtoL = new int [nn];
    for( int j = nn-1; j >= 0; j-- ){
        sum += arr[j];
        if( sum > max ){
            max = sum;
        }
        MemRtoL[j] = max;
        if( sum < 0 ){
            sum = 0;
        }
    }
    return max;
}

int M2SSTD( int arr [], int& nn ){
    MSSTDLtoR( arr, nn );
    MSSTDRtoL( arr, nn );

    int retMax = INT_MIN; 
    for( int i = 0; i <= nn-2; i++ ){
        retMax = MAX2( retMax, (MemLtoR[i] + MemRtoL[i+1]) );
    }
    return retMax ;
}

int main(){
    //input
    int tt;
    int nn;
    int* arr;
    cin >> tt;
    for( int i = 1; i <= tt; i++ ){
        //
        cin >> nn;
        arr = new int [nn];
        for( int j = 0; j <= nn-1; j++ ){
            scanf("%d", &arr[j]);
        }
        cout << M2SSTD( arr, nn ) << endl;
        delete [] arr;
    }

    //output
    system("pause");
    return 0;
}

void reverseString( string& a ){
    int len = a.size();
    int end = len/2-1;
    len--;
    for( int i = 0; i <= end; i++ ){
        int tmp = a[i];
        a[i] = a[len-i];
        a[len-i] = tmp;
    }
}
