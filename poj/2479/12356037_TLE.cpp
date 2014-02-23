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

int MSS( int arr [], int nn ){
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
            cin >> arr[j];
        }
        cout << M2SS( arr, nn ) << endl;
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

//typedef ListNode* iterator;
int lcs( string& a, string& b ) {
    //loop through
    int m = a.size();
    int n = b.size();
    if( m == 0 || n == 0 ){
        return 0;
    }
    vector<vector <int>> dp;
    if( n < m ){
        //dp = vector<vector <int>(n+1, 0)>(m+1, 0);
        vector<int> tmp = vector<int>(n+1, 0);
        for( int i = 0; i <= 1; i++ ){
            dp.push_back(tmp);
        }
        for( int i = 1; i <= m; i++ ){
            for( int j = 1; j <= n; j++ ){
                if( a[i-1] == b[j-1] ){
                    dp[i%2][j] = dp[(i-1)%2][j-1] + 1;
                }
                else{
                    dp[i%2][j] = MAX2( dp[(i-1)%2][j], dp[i%2][j-1] );
                }
            }
        }
        return dp[m%2][n];
    }
    else{ // m < n
        //dp = vector<vector <int>(n+1, 0)>(m+1, 0);
        vector<int> tmp = vector<int>(2, 0);
        for( int i = 0; i <= n; i++ ){
            dp.push_back(tmp);
        }
        for( int j = 1; j <= n; j++ ){
            for( int i = 1; i <= m; i++ ){
                if( a[i-1] == b[j-1] ){
                    dp[i][j%2] = dp[i-1][(j-1)%2] + 1;
                }
                else{
                    dp[i][j%2] = MAX2( dp[i-1][j%2], dp[i][(j-1)%2] );
                }
            }
        }
        return dp[m][n%2];
    }
}

//typedef ListNode* iterator;
int lcsOld( string a, string b ) {
    //loop through
    int m = a.size();
    int n = b.size();
    if( m == 0 || n == 0 ){
        return 0;
    }
    vector<vector <int>> dp;
    if( true ){
        //dp = vector<vector <int>(n+1, 0)>(m+1, 0);
        vector<int> tmp = vector<int>(n+1, 0);
        for( int i = 0; i <= m; i++ ){
            dp.push_back(tmp);
        }
        for( int i = 1; i <= m; i++ ){
            for( int j = 1; j <= n; j++ ){
                if( a[i-1] == b[j-1] ){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else{
                    dp[i][j] = MAX2( dp[i-1][j], dp[i][j-1] );
                }
            }
        }

    }

    return dp[m][n];
}

//typedef ListNode* iterator;
int agtc( string& a, string& b ) {
    //loop through
    int m = a.size();
    int n = b.size();
    if( m == 0 ){
        return n;
    }
    if( n == 0 ){
        return m;
    }
    vector<vector <int>> dp;
    if( true ){
        //dp = vector<vector <int>(n+1, 0)>(m+1, 0);
        vector<int> tmp = vector<int>(n+1, 0);
        for( int i = 0; i <= m; i++ ){
            dp.push_back(tmp);
        }
        for( int i = 1; i <= m; i++ ){
            for( int j = 1; j <= n; j++ ){
                if( a[i-1] == b[j-1] ){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else{
                    dp[i][j] = MAX2( dp[i-1][j], dp[i][j-1] );
                }
            }
        }

    }

    if( m > n ){
        return m - dp[m][n];
    }
    else{
        return n - dp[m][n];
    }
}
