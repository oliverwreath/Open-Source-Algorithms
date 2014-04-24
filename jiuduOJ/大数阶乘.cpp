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
    int n;
    
    int INT_MIN = std::numeric_limits<int>::min(); // minimum value
    int INT_MAX = std::numeric_limits<int>::max();
    
    while( cin >> n )
    {
        int * ret = new int [10010]();
        ret[0] = 1;
        ret[1] = 1;
        
        int end = 1;
        for( int k = 2; k <= n; k++ ){
            for( int i = 1; i <= end; i++ ){
                ret[i] *= k;
            }
            
            for( int i = 1; i <= end; i++ ){
                if( ret[i] >= 10 ){
                    ret[i+1] += ret[i] / 10;
                    ret[i] %= 10;
                    if( i == end ){
                        end++;
                    }
                }
            }
        }
        
        for( int i = end; i >= 1; i-- ){
            cout << ret[i];
        }
        cout << endl;
        
        delete [] ret;
    }
    
	return 0;	
}
