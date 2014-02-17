#define F(i, a, b) for(int i = a; i <= b; i++)
//#define FB(i, a, b) for(int i = a; i >= b; i--)
#define MAX2(a, b) a>b?a:b

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    typedef char* iterator;

    char *strStr(char *haystack, char *needle) {
        if( haystack == NULL || needle == NULL ){
            return NULL;
        }
        if( *needle == '\0' ){
            return haystack;
        }

        iterator ptr = haystack;
        int m = 0;
        while( ptr != NULL && *ptr != '\0' ){
            m++;
            ptr++;
        }

        int n = 0;
        ptr = needle;
        while( ptr != NULL && *ptr != '\0' ){
            n++;
            ptr++;
        }

        ptr = haystack;
        F(i, 1, m-n+1){
            bool found = true;
            F( j, 0, n-1 ){
                if( ptr[i-1 + j] != needle[j] ){
                    found = false;
                    break;
                }
            }
            if( found ){
                return &ptr[i-1];
            }
        }

        return NULL;
    }
};
