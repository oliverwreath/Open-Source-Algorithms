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
#include <cmath>
#include <stack>
#include <set>

using namespace std;

class Team{
public:
	Team(int id, int score){
		this->id = id;
		this->score = score;
	}
	int id;
	int score;
};

bool cmp( const Team& t1, const Team& t2 ){
	return t1.score > t2.score;
}

int main(){
	int n;
	cin >> n;
	vector<Team> data;
	for( int i = 0; i < n; i++ ){
		int id, score;
		cin >> id >> score;
		data.push_back(Team(id, score));
	}

	stable_sort(data.begin(), data.end(), cmp);

	for( int i = 0; i < n; i++ ){
		cout << data[i].id << " " << data[i].score << endl;
	}

	return 0;
}


