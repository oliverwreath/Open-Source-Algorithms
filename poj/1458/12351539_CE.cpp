/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#define MAX2(a, b) a>b?a:b

int lcs( string a, string b );

int main(){
    //input
    string a;
    string b;
    while( cin >> a >> b ){
        cout << lcs( a, b ) << endl;
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
            dp = vector<vector <int>(n+1, 0)>(m+1, 0);
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
