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

class DivisorDigits{
public:
    int howMany(int num){
        int tmp = num;
        int cnt = 0;
        while( tmp > 0 ){
            int digit = tmp % 10;
            if( digit != 0 && num % digit == 0 ){
                cnt++;
            }
            tmp /= 10;
        }
        return cnt;
    }
};
