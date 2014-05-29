#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <sstream>
#include <algorithm>
//#include <stdlib.h>

using namespace std;

class Ticket{
public:
	Ticket(string name, long long value){
		this->name = name;
		this->value = value;
	};

	string name;
	long long value;
};

bool operator< ( const Ticket& tk1, const Ticket& tk2 ){
	if( tk1.value != tk2.value ){
		return tk1.value < tk2.value;
	}else{
		return tk1.name < tk2.name;
	}
}

class Lottery{
public:
	//"INDIGO: 93 8 T F",

	vector<string> sortByOdds(vector<string> rules){
		int len = rules.size();
		vector<Ticket> tickets;
		int choices, blanks;
		bool isSorted, isUnique;
		for( auto i = 0; i < len; i++ ){
			string rule = rules[i];
			int pos = rule.find_first_of(':');
			string name = rule.substr(0, pos);

			istringstream iss(rule.substr(pos+2, rule.size()));
			char ch1, ch2;
			iss >> choices >> blanks >> ch1 >> ch2;
			isSorted = (ch1=='T'?true:false);
			isUnique = (ch2=='T'?true:false);
			long long value = getPossibilities( choices, blanks, isSorted, isUnique );

			tickets.push_back( Ticket(name, value) );
			sort( tickets.begin(), tickets.end() );
		}

		vector<string> ret;
		for( auto it = tickets.begin(); it != tickets.end(); it++ ){
			ret.push_back(it->name);
			//test
			cout << it->name << ": " << it->value << endl;
		}

		return ret;
	}

	long long getPossibilities( int choices, int blanks, bool isSorted, bool isUnique ){
		if( !isSorted && !isUnique ){
			return power(choices, blanks);
		}else if( !isSorted && isUnique ){
			return unique(choices, blanks);
		}else if( isSorted && isUnique ){
			return sortedUnique(choices, blanks);
		}else{
			return sortedUnique(choices+blanks-1, blanks);
		}
	}

	long long factorial( int n ){
		long long ret = 1;
		for( auto i = 2; i <= n; i++ ){
			ret *= i;
		}
		return ret;
	}

	long long sortedUnique( int m, int n ){
		long long ret = unique(m, n)/ (factorial(n));
		return ret;
	}

	long long unique( int m, int n ){
		long long ret = 1;
		for( auto i = 0; i < n; i++ ){
			ret *= m;
			m--;
		}
		return ret;
	}

	long long power( int m, int n ){
		long long ret = 1;
		for( auto i = 0; i < n; i++ ){
			ret *= m;
		}
		return ret;
	}
};
