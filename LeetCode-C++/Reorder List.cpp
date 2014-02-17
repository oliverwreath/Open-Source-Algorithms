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
    //typedef
    typedef ListNode* iterator;
    //methods
    iterator getEnd( iterator head, iterator& tmpEndButOne ){
        if( head == NULL ){
            tmpEndButOne = NULL;
            return NULL;
        }
        iterator tmpNext = head->next;
        if( tmpNext == NULL ){
            tmpEndButOne = NULL;
            return head;
        }
        else{
            tmpEndButOne = head;
            while( tmpNext->next != NULL ){
                tmpEndButOne = tmpNext;
                tmpNext = tmpNext->next;
            }
            return tmpNext;
        }
    }
    
    iterator reverseList( ListNode* head ){
        if( head == NULL || head->next == NULL){
            return head;
        }
        iterator slowPtr = NULL;
        iterator fastPtr = head;
        while( fastPtr != NULL ){
            iterator tn = fastPtr->next;
            fastPtr->next = slowPtr;
            slowPtr = fastPtr;
            fastPtr = tn;
        }
        return slowPtr;
    }
    
    int lengthOfList( ListNode* head ){
        if( head == NULL ){
            return 0;
        }
        //iterator slowPtr = NULL;
        int ret = 1;
        iterator fastPtr = head;
        while( fastPtr->next != NULL ){
            ret++;
            fastPtr = fastPtr->next;
        }
        return ret;
    }
    
    iterator getMid( ListNode* head, int mid ){
        for( int i = 1; i <= mid-1; i++ ){
            head = head->next;
        }
        return head;
    }
    
    void reorderListRec( ListNode *head ) {
        iterator headPtr = head;
        if( headPtr == NULL || (headPtr->next ==NULL) ){
            return ;
        }
        iterator tmpNext = headPtr->next;
        iterator tmpEndButOne;
        iterator tmpEnd = getEnd(headPtr, tmpEndButOne);
        while( tmpNext != tmpEnd ){
            headPtr->next = tmpEnd;
            tmpEnd->next = tmpNext;
            tmpEndButOne->next = NULL;
            if( tmpNext->next == NULL ){
                break;
            }
            headPtr = tmpNext;
            tmpNext = tmpNext->next;
            tmpEnd = getEnd(headPtr, tmpEndButOne);
        }
        return ;
    }
    
    void reorderList(ListNode *head) {
        //step 1: count 
        //iterator headPtr = head;
        int len = lengthOfList( head );
        if( len < 3 ){
            return;
        }
        
        //step 2: reverse
        int mid = (len+1)/2;
        iterator midPtr = getMid( head, mid );  
        iterator mn = midPtr->next;
        midPtr->next = NULL;
        midPtr = reverseList( mn );
        
        //step 3: merge
        iterator hn = head->next;
        mn = midPtr->next;
        while( mn != NULL ){
            head->next = midPtr;
            midPtr->next = hn;
            head = hn;
            midPtr = mn;
            hn = head->next;
            mn = midPtr->next;
        }
        head->next = midPtr;
        midPtr->next = hn;
            
        return ;
    }
};
