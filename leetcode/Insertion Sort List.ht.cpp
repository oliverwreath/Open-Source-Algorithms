/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 #include <unordered_map>

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
        
		unordered_map<iterator, iterator> ht; 

		ht[head->next] = head;
		while( fp != NULL ){
			iterator tmp = sp;
			while( tmp->val > fp->val ){
				if( ht.find(tmp) == ht.end() ){
					break;
				}else{
					tmp = ht[tmp];
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
