#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <limits>

using namespace std; 

bool comp( pair<int, string> p1, pair<int, string> p2 ){
    return (p1.first <= p2.first);
}

int main(){
    int t, min, max, val;
    
    int INT_MIN = std::numeric_limits<int>::min(); // minimum value
    int INT_MAX = std::numeric_limits<int>::max();
    
    while( cin >> t ){
        min = INT_MAX;
        max = INT_MIN;
        for( int i = 1; i <= t; i++ ){
            cin >> val;
            if( val < min ){
                min = val;
            }
            if( val > max ){
                max = val;
            }
        }
        
        cout << max << " " << min << endl;
    }
    
	return 0;	
}
