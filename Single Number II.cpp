#define F(i, a, b) for(int i = a; i <= b; i++)
#define FB(i, a, b) for(int i = a; i >= b; i--)
#define MAX2(a, b) a>b?a:b
#define MIN2(a, b) a<b?a:b

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int singleNumber(int A[], int n) {
        int fst = 0;
        int snd = 0;

        F( i, 0, n-1 ){
            int cry = A[i] & fst;
            fst = A[i] ^ fst;
            //int cry2 = cry & snd;
            snd = cry ^ snd;
            int nsame = ~(fst & snd);

            fst &= nsame;
            snd &= nsame;
        }

        return (fst & (~snd) );
    }
};
