/**
 * Definition for singly-linked list.
 * struct ListNode {
 *	 int val;
 *	 ListNode *next;
 *	 ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 #include <vector>

class Solution {
public:
	//typedef 
	typedef ListNode* iterator; 

	ListNode* insertionSortList(ListNode* head) {
		// IMPORTANT: Please reset any member data you declared, as
		// the same Solution instance will be reused for each test case.
		if( head == NULL || head -> next == NULL ){
			return head;
		}
		iterator fp = head->next;
		iterator sp = head;
		
		vector<iterator> vt;

		vt.push_back( sp );
		vt.push_back( fp );
		while( fp != NULL ){
			iterator tmp = sp;
			int index = vt.size()-2;
			while( tmp->val > fp->val ){
				if( index == 0 ){
					break;
				}else{
					tmp = vt[--index];
				}
			}

			if( tmp->val > fp->val ){
				sp->next = fp->next;
				fp->next = head;
				head = fp;
			}else{
				if( tmp->next = fp ){

				}else{
					sp->next = fp->next;
					fp->next = tmp->next;
					tmp->next = fp;
				}
			}
			sp = fp;
			fp = fp->next;
		}

		return head; 
	}
};
