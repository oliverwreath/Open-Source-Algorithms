#define F(i, a, b) for(int i = a; i <= b; i++)
#include <vector>
#include <unordered_map>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if( n < 3 ){
            return n;
        }

        unordered_map<int, int> ht;

        int len = n;
        for( int i = 0, index = 0; i <= n-1; i++, index++ ){
            if( ht.find(A[i]) != ht.end() ){
                if( ht[A[i]] == 1 ){
                    ht[A[i]] = 2;
                    if( index < i ){
                        A[index] = A[i];
                    }
                }else{
                    //delete
                    index--;
                    len--;
                }
            }else{
                ht[A[i]] = 1;
                if( index < i ){
                    A[index] = A[i];
                }
            }
        }

        return len;
    }
};
