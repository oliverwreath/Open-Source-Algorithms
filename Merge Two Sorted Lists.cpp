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
    typedef ListNode* iterator;
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        iterator fstP1 = l1;
        iterator fstP2 = l2;
        iterator head = NULL;
        iterator fst = NULL;
        
        while( fstP1 != NULL || ( fstP2 != NULL ) ){
            if( fstP1 == NULL ){
                while( fstP2 != NULL ){
                    if( fst == NULL ){
                        head = fstP2;
                        fst = fstP2;                    
                        fstP2 = fstP2->next;
                        fst->next = NULL;
                    }else{
                        fst->next = fstP2;
                        fstP2 = fstP2->next;
                        fst = fst->next;
                        fst->next = NULL;
                    }
                }
            }
            else if( fstP2 == NULL ){
                while( fstP1 != NULL ){
                    if( fst == NULL ){
                        head = fstP1;
                        fst = fstP1;                    
                        fstP1 = fstP1->next;
                        fst->next = NULL;
                    }else{
                        fst->next = fstP1;
                        fstP1 = fstP1->next;
                        fst = fst->next;
                        fst->next = NULL;
                    }
                }
            }
            else if( fstP1->val < fstP2->val ){
                if( fst == NULL ){
                    head = fstP1;
                    fst = fstP1;                    
                    fstP1 = fstP1->next;
                    fst->next = NULL;
                }else{
                    fst->next = fstP1;
                    fstP1 = fstP1->next;
                    fst = fst->next;
                    fst->next = NULL;
                }
            }else{
                if( fst == NULL ){
                    head = fstP2;
                    fst = fstP2;                    
                    fstP2 = fstP2->next;
                    fst->next = NULL;
                }else{
                    fst->next = fstP2;
                    fstP2 = fstP2->next;
                    fst = fst->next;
                    fst->next = NULL;
                }
            }
        }

        return head;
    }
};
