/**
 * Definition for singly-linked list.
 * struct ListNode {
 *	 int val;
 *	 ListNode *next;
 *	 ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <unordered_set>

class Solution {
public:
	//typedef 
	typedef ListNode* iterator;

	//methods
	ListNode* detectCycle(ListNode *head) {
		if( head == NULL ){
			return NULL;
		}

		unordered_set<iterator> set;
		while( head != NULL ){
			if( set.find( head ) != set.end() ){
				return head;
			}else{
				set.insert( head );
				head = head->next;
			}
		}

		return NULL;
	}
};
