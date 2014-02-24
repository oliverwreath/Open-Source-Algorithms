#define MAX2(a, b) a>b?a:b

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int D1MSS( int arr [], int& nn ){
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

int* MemTo1;

int D2MSS( int** arr, int& nn ){
    int sum = 0;
    int max = INT_MIN;
    MemTo1 = new int [nn];
    for( int l = 0; l <= nn-1; l++ ){
        for( int i = l; i <= nn-1; i++ ){
            //init Mem
            if( i == l ){
                for( int j = 0; j <= nn-1; j++ ){
                    MemTo1[j] = arr[i][j];
                }
            }
            else{
                for( int j = 0; j <= nn-1; j++ ){
                    MemTo1[j] += arr[i][j];
                }
            }
            //process
            int tmpRet = D1MSS( MemTo1, nn );
            max = MAX2(max, tmpRet);
        }
    }
    delete [] MemTo1;
    return max;
}

int main(){
    int nn;
    int** arr;
    while( scanf("%d", &nn) != EOF ){
        //scan
        arr = new int* [nn];
        for( int i = 0; i <= nn-1; i++ ){
            arr[i] = new int [nn];
            for( int j = 0; j <= nn-1; j++ ){
                scanf("%d", &arr[i][j]);
            }
        }

        //process
        cout << D2MSS( arr, nn ) << endl;
        for( int i = 0; i <= nn-1; i++ ){
            delete [] arr[i];
        }
        delete [] arr;
    }

    //output
    system("pause");
    return 0;
}
