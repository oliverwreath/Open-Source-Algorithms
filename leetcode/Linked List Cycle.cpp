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
	bool hasCycle(ListNode *head) {
		if( head == NULL ){
			return false;
		}

		unordered_set< iterator > set;
		while( head != NULL ){
			if( set.find(head) != set.end() ){
				return true;
			}else{
				set.insert(head);
				head = head->next;
			}
		}

		return false;
	}
};
