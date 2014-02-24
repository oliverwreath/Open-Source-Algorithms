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

int main(){
    //input
    int ii;
    int jj;
    string a;
    string b;
    while( cin >> ii >> jj >> a >> b ){
        cout << agtc( a, b ) << endl;
    }

    //output
    return 0;
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
