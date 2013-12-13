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
    void swap( int* A, int& a, int& b){
        if( a == b ){
            return ;
        }else{
            int tmp = A[a];
            A[a] = A[b];
            A[b] = tmp;
        }
    }

    int removeDuplicates(int A[], int n) {
        if( n < 2 ){
            return n;
        }

        int tmp = A[0];
        int len = n;
        int index = 1;
        F(i, 1, n-1){
            if( A[i] == tmp ){
                len--;
                index--;
            }else{
                tmp = A[i];
                if( index < i ){
                    swap(A, i, index);
                }
            }
            index++;
        }

        return len--;
    }
};
