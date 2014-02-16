#define F(i, a, b) for(int i = a; i <= b; i++)
#define FB(i, a, b) for(int i = a; i >= b; i--)
#define MAX2(a, b) a>b?a:b
#define MIN2(a, b) a<b?a:b

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if( l1 == NULL ){
            return NULL;
        }

        int carry = 0;
        ListNode* head = l1;
        ListNode* sloPtr = NULL; 
        while( l1 != NULL || l2 != NULL ){
            if( l1 != NULL && l2 != NULL ){
                l1->val += (l2->val + carry);
                if( l1->val > 9 ){
                    carry = 1;
                    l1->val -= 10;
                }else{
                    carry = 0;
                }
                sloPtr = l1;
                l1 = l1->next;
                l2 = l2->next;
            }else if(l1 != NULL && l2 == NULL){
                l1->val += carry;
                if( l1->val > 9 ){
                    carry = 1;
                    l1->val -= 10;
                }else{
                    carry = 0;
                    break; 
                }
                sloPtr = l1;
                l1 = l1->next;
            }else if(l1 == NULL && l2 != NULL){
                l2->val += carry;
                if( l2->val > 9 ){
                    carry = 1;
                    l2->val -= 10;
                }else{
                    carry = 0;
                    sloPtr->next = l2;
                    sloPtr = l2;
                    break;
                }
                sloPtr->next = l2;
                sloPtr = l2;
                l2 = l2->next;
            }
        }

        if( carry > 0 ){
            sloPtr->next = new ListNode(carry);
        }

        return head;
    }
};
