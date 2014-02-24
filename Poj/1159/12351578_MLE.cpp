/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#define MAX2(a, b) a>b?a:b

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int lcs( string a, string b );

int agtc( string a, string b );

string reverseString( string a );

int main(){
    //input
    int ii;
    string a;
    while( cin >> ii >> a ){
        cout << ii - lcs( a, reverseString(a) ) << endl;
    }

    //output
    system("pause");
    return 0;
}

string reverseString( string a ){
    int len = a.size();
    int end = len/2-1;
    len--;
    for( int i = 0; i <= end; i++ ){
        int tmp = a[i];
        a[i] = a[len-i];
        a[len-i] = tmp;
    }
    return a;
}

//typedef ListNode* iterator;
int lcs( string a, string b ) {
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
int agtc( string a, string b ) {
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
