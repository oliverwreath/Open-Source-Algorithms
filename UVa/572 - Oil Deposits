#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <sstream>
#include <algorithm>
#include <unordered_set>
#include <cstdio>
#include <cstring>
#include <climits>
#include <cfloat>

using namespace std;

class Oil{
public:
	int** vis;

	void bfs( int i, int j, int& m, int& n, vector<string>& grid ){
		if( i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '*' || vis[i][j] == 1 ){
			return ;
		}
		vis[i][j] = 1;
		bfs( i-1, j-1, m, n, grid );
		bfs( i-1, j, m, n, grid );
		bfs( i-1, j+1, m, n, grid );
		bfs( i, j-1, m, n, grid );
		bfs( i, j+1, m, n, grid );
		bfs( i+1, j-1, m, n, grid );
		bfs( i+1, j, m, n, grid );
		bfs( i+1, j+1, m, n, grid );

		return ;
	}

	int deps(int m, int n, vector<string>& grid){
		vis = new int* [m];
		int cnt = 0;
		for( auto i = 0; i < m; i++ ){
			vis[i] = new int [n]();
		}

		for( auto i = 0; i < m; i++ ){
			for( auto j = 0; j < n; j++ ){
				if( grid[i][j] == '@' && vis[i][j] == 0 ){
					//bfs();
					cnt++;
					bfs( i, j, m, n, grid );
				}
			}
		}

		for( auto i = 0; i < m; i++ ){
			delete [] vis[i];
		}
		delete [] vis;

		return cnt;
	}
};

int main(){
	Oil t = Oil();
	int m, n;
	while( cin >> m >> n ){
		if(m == 0){
			return 0;
		}

		vector<string> gr;
		string st;
		for( auto i = 0; i < m; i++ ){
			cin >> st;
			gr.push_back(st);
		}

		cout << t.deps( m, n, gr ) << endl;
	}

	return 0;
}

