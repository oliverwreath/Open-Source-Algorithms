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
    ListNode *partition(ListNode *head, int x) {
        //loop through
        if( head == NULL || head->next == NULL ){
            return head;
        }
        iterator fstH = NULL;
        iterator fstE = NULL;
        iterator sndH = NULL;
        iterator sndE = NULL;
        iterator fPtr;
        
        fPtr = head;
        //sPtr = NULL;

        while( fPtr != NULL ){
            //process
            if( fPtr->val < x ){
                if( fstH == NULL ){
                    fstH = fPtr;
                    fstE = fPtr;
                }
                else{
                    fstE->next = fPtr;
                    fstE = fPtr;
                }
                //sPtr = fPtr;
                fPtr = fPtr->next;
                continue;
            }else{
                if( sndH == NULL ){
                    sndH = fPtr;
                    sndE = fPtr;
                }
                else{
                    sndE->next = fPtr;
                    sndE = fPtr;
                }
                //sPtr = fPtr;
                fPtr = fPtr->next;
                continue;
            }
        }

        if( fstE != NULL){
            fstE->next = sndH;
        }
        if( sndE != NULL ){
            sndE->next = NULL;
        }

        if( fstH != NULL ){
            return fstH;
        }
        else{
            return sndH;
        }
        
        //merge
    }
};
