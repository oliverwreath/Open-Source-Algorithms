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
    typedef ListNode* iteration; 
    //methods
    ListNode* deleteDuplicates(ListNode* head) {
        if( head == NULL || head->next == NULL ){
            return head;
        }
        //2 or more nodes
        iteration fp;
        iteration sp = NULL;
        iteration bp;
        iteration ep;
        iteration lp;
        fp = head;
        while( fp != NULL && ( fp->next != NULL ) ){
            if( fp->val != fp->next->val ){
                sp = fp;
                fp = fp->next;
            }
            else{
                bp = fp;
                int tmpVal = fp->val;
                while( fp->next != NULL && ( fp->next->val == tmpVal ) ){
                    fp = fp->next;
                }
                //
                ep = fp;
                fp = fp->next;
                if( sp == NULL ){
                    head = fp;
                }else{
                    sp->next = fp;
                }
                //delRange( bp, ep );
                lp = bp->next;
                while( bp != ep ){
                    delete bp;
                    bp = lp;
                    lp = bp->next;
                }
                delete bp;
            }
        }
        return head;
    }
};










