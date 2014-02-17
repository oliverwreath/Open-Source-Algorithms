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

    bool notEmpty( vector<ListNode *>& lists, int& k ){
        F( i, 0, k-1 ){
            if(lists[i] != NULL){
                return true;
            }
        }
        return false;
    }

    ListNode* mergeKLists(vector<ListNode *>& lists) {
        int k = lists.size();
        iterator head = NULL;

        if( k == 0 ){
            return head;
        }
        if( k == 1 ){
            return lists[0];
        }

        iterator fst = NULL;
        while( notEmpty( lists, k ) ){
            int target;
            int min = INT_MAX;
            F( i, 0, k-1 ){
                if( lists[i] != NULL ){
                    if( min > lists[i]->val ){
                        min = lists[i]->val;
                        target = i;
                    }
                }
            }

            if( fst == NULL ){
                head = lists[target];
                fst = lists[target];
                lists[target] = lists[target]->next;
                fst->next = NULL;
            }else{
                fst->next = lists[target];
                lists[target] = lists[target]->next;
                fst = fst->next;
                fst->next = NULL;
            }

        }

        return head;
    }
};
