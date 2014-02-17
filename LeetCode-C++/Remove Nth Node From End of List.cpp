/**
 * Definition for singly-linked list.
 * struct ListNode {
 *	 int val;
 *	 ListNode *next;
 *	 ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#define F(i, a, b) for( int i = a; i <= b; i++ )

class Solution {
public:
	//typedef
	typedef ListNode* iterator;

	//methods
	ListNode *removeNthFromEnd(ListNode *head, int n) {
		if( head == NULL || n < 1 ){
			return head;
		}

		iterator phead = new ListNode(0);
		phead->next = head;

		if( n == 1 ){
			iterator sl = phead;
			iterator fst = sl->next;
			while( fst->next != NULL ){
				sl = fst;
				fst = fst->next;
			}
			sl->next = NULL;

			return phead->next;
		}else{
			iterator sl = phead;
			iterator fst = sl->next;
			F( i, 1, n-1 ){
				fst = fst->next;
			}
			while( fst->next != NULL ){
				sl = sl->next;
				fst = fst->next;
			}
			fst = sl->next;
			sl->next = fst->next; 

			return phead->next;
		}
	}
};
