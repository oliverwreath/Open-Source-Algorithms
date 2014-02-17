/**
 * Definition for singly-linked list.
 * struct ListNode {
 *	 int val;
 *	 ListNode *next;
 *	 ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 //dummyhead

class Solution {
public:
	//typedef 
	typedef ListNode* iterator; 

	ListNode* insertionSortList(ListNode* head){ 
		// IMPORTANT: Please reset any member data you declared, as
		// the same Solution instance will be reused for each test case.
		if( head == NULL || head -> next == NULL ){
			return head;
		}
		iterator sp = head; 
		iterator fp = head->next;
		
		iterator phead = new ListNode(0);
		phead->next = head;
		
		while( fp != NULL ){
			iterator ft = phead->next;
			iterator st = phead;
			while( ft->val < fp->val ){
				st = ft;
				ft = ft->next;
			}

			if( ft == fp ){
				sp = fp;
				fp = fp->next;
			}else{
				sp->next = fp->next;
				fp->next = ft;
				st->next = fp;
				fp = sp->next;
			}
		}

		return phead->next; 
	}
};
