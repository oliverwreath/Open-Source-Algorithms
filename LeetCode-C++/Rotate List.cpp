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
	ListNode *rotateRight(ListNode *head, int k) {
		if( head == NULL || head->next == NULL ){
			return head;
		}

		iterator end;
		iterator phead = new ListNode(0);
		phead->next = head;
		int len = 0;
		while( head->next != NULL ){
			len++;
			head = head->next;
		}
		len++;
		end = head;

		k %= len;
		//case 1
		if( k == 0 ){
			return phead->next;
		}

		//case 2
		iterator sl = phead->next;
		iterator fst = sl->next;
		F( i, 1, len-k-1 ){
			sl = fst;
			fst = fst->next;
		}

		end->next = phead->next;
		phead->next = fst;
		sl->next = NULL;

		return phead->next;
	}
};
