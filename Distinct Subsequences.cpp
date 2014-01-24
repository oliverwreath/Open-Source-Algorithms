#define F(i, a, b) for(int i = a; i <= b; i++)
#define MAX2(a, b) a>b?a:b
#include <iostream>
#include <vector>
#include <algorithms>

using namespace std; 

class Solution{

public: 
	//methods
	int lenS;
	int lenT; 
	int lcs( string& S, string& T ){
		vector<int> tmp = vector<int>(lenT+1, 0);
		vector<vector<int>> ret = vector<vector<int>>(lenS+1, tmp);
		F(i, 1, lenS){
			F(j, 1, lenT){
				if( S[i-1] == T[j-1] ){
					ret[i][j] = ret[i-1][j-1]+1;
				}else{
					ret[i][j] = MAX2(ret[i-1][j], ret[i][j-1]);
				}
			}
		}
		return ret[lenS][lenT];
	}

	int scs( string& S, string& T ){
		vector<int> tmp = vector<int>(lenT+1, 1);
		vector<vector<int>> ret = vector<vector<int>>(lenS+1, tmp);
		int starting = 1;
		F(j, 1, lenT){
			int count = 0;
			bool flag = false;
			F(i, starting, lenS){
				if( S[i-1] == T[j-1] ){
					if(!flag){
						starting = i+1;
						flag = true; 
					}
					count += ret[i-1][j-1];
				}
				ret[i][j] = count;
			}
		}
		return ret[lenS][lenT];
	}

	int numDistinct(string S, string T) {
		lenS = S.size();
		lenT = T.size();

		if( lenS < 1 || lenS < lenT ){
			return 0;
		}

		int lcslen = lcs(S, T);
		if( lcslen < lenT ){
			return 0; 
		}
		int scslen = scs(S, T);
		return scslen;
	}
};
