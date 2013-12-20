#define F(i, a, b) for(int i = a; i <= b; i++)
#define FB(i, a, b) for(int i = a; i >= b; i--)
#define MAX2(a, b) a>b?a:b
#define MIN2(a, b) a<b?a:b

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int singleNumber(int A[], int n) {
        if( n == 0 ){
            return -1;
        }

        unordered_map<int, bool> ht;

        F(i, 0, n-1){
            if( ht.find(A[i]) != ht.end() ){
                ht[A[i]] = false;
            }else{
                ht[A[i]] = true;
            }
        }

        F(i, 0, n-1){
            if(ht[A[i]]){
                return A[i];
            }
        }

        return -1;
    }
};
