#define F(i, a, b) for(int i = a; i <= b; i++)
#define FB(i, a, b) for(int i = a; i >= b; i--)
#define MAX2(a, b) a>b?a:b
#define MIN2(a, b) a<b?a:b

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        if( numRows == 0 ){
            vector<int> tmp = vector<int>(0,0);
            vector<vector<int> > pas = vector<vector<int> >(0, tmp);
            return pas;
        }

        if( numRows == 1 ){
            vector<int> tmp = vector<int>(1,1);
            vector<vector<int> > pas = vector<vector<int> >(1, tmp);
            return pas;
        }

        vector<vector<int> > pas = vector<vector<int> >(numRows);
        F(i, 0, 1){
            vector<int>* tmp = new vector<int>(i+1,1);
            pas[i] = (*tmp);
        }

        F(i, 2, numRows-1){
            vector<int>* tmp = new vector<int>(i+1,1);
            F(j, 1, i-1){
                (*tmp)[j] = pas[i-1][j-1] + pas[i-1][j];
            }
            pas[i] = (*tmp);
        }

        return pas;
    }
};
