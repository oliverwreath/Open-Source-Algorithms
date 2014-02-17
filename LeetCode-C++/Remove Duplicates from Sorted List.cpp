#define F(i, a, b) for(int i = a; i <= b; i++)
#include <vector>
#include <unordered_set>

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

    ListNode* deleteDuplicates(ListNode* head) {
        if( head == NULL || head->next == NULL ){
            return head;
        }

        unordered_set<int> set;
        iterator fp = head;
        iterator sp = NULL;
        while( fp != NULL ){
            if( set.find(fp->val) != set.end() ){
                if( sp == NULL ){
                    head = fp->next;
                    delete fp;
                    fp = head;
                }
                else{
                    sp->next = fp->next;
                    delete fp;
                    fp = sp->next;
                }
            }else{
                set.insert( fp->val );
                sp = fp;
                fp = fp->next;
            }
        }

        return head;
    }
};
