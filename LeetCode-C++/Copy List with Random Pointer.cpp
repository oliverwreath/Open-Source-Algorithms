/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *	 int label;
 *	 RandomListNode *next, *random;
 *	 RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */

#include <unordered_map>

class Solution {
public:
	//typedef
	typedef RandomListNode* iterator;

	//methods
	RandomListNode *copyRandomList(RandomListNode *head) {
		if( head == NULL ){
			return NULL;
		}

		//at least one
		iterator phead = new RandomListNode(0);
		iterator phead2 = new RandomListNode(0);

		phead->next = head;

		unordered_map<iterator, iterator> ht;
		ht[NULL] = NULL;
		iterator sp = phead2;
		iterator fp = new RandomListNode(head->label);
		ht[head] = fp;
		sp->next = fp;
		head = head->next;

		while( head != NULL ){ 
			sp = fp;
			fp = new RandomListNode( head->label );	
			ht[head] = fp;	
			sp->next = fp;
			head = head->next;
		}
		fp->next = NULL;

		head = phead->next;
		fp = phead2->next;
		while( head != NULL ){
			fp->random = ht[head->random];
			head = head->next;
			fp = fp->next; 
		}

		return phead2->next;
	}
};
