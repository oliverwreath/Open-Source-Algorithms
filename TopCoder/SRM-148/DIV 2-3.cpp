#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <sstream>
#include <algorithm>
#include <unordered_set>
#include <cstdio>
#include <cstring>

using namespace std;

class MNS{
public:
    bool validMNS( vector<int> nums ){
        int sum = nums[0] + nums[1] + nums[2];
        if( sum != nums[3] + nums[4] + nums[5] || sum != nums[6] + nums[7] + nums[8] ){
            return false;
        }

        sum = nums[0] + nums[3] + nums[6];
        if( sum != nums[1] + nums[4] + nums[7] || sum != nums[2] + nums[5] + nums[8] ){
            return false;
        }
        return true;
    }


    int combos(vector<int> numbers){
        int cnt = 0;

        sort( numbers.begin(), numbers.end() );
        do{
            if(validMNS(numbers)){
                cnt++;
            }
        }while( next_permutation( numbers.begin(), numbers.end() ) );

        return cnt;

    }
};
