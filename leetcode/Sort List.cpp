/**
 * Definition for singly-linked list.
 * struct ListNode {
 *	 int val;
 *	 ListNode *next;
 *	 ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <queue>

class Solution {
public:
	//typedef 
	typedef ListNode* iterator; 

	iterator merge( iterator pre, iterator pa, iterator pb, iterator suc ){
		iterator tmp = pb;
		bool flag = true;
		while( flag ){
			if( pa->val < pb->val ){
				//adding pa 
				pre->next = pa;
				pre = pa;
				pa = pa->next;
				if( pa == tmp ){
					//add pb list if any
					while( pb != suc ){
						pre->next = pb;
						pre = pb;
						pb = pb->next;
					}
					flag = false;
				}
			}else{
				//adding pb 
				pre->next = pb;
				pre = pb;
				pb = pb->next;
				if( pb == suc ){
					//add pb list if any
					while( pa != tmp ){
						pre->next = pa;
						pre = pa;
						pa = pa->next;
					}
					flag = false;
				}
			}
		}
		pre->next = suc;

		//return idx2 end
		return pre;
	}

	ListNode* sortList(ListNode* head){ 
		if( head == NULL || head->next == NULL ){
			return head;
		}

		queue<iterator> que;
		int len = 0;

		iterator phead = new ListNode(0);
		phead->next = head;
		while( head != NULL ){ 
			que.push( head );
			head = head->next; 
			len++;
		}

		while( len > 1 ){
			int tmpLen = len;
			iterator pre = phead;

			while( tmpLen > 1 ){
				iterator idx1 = que.front();
				que.pop();
				iterator idx2 = que.front();
				que.pop();
				
				tmpLen -= 2;
				if( tmpLen == 0 ){
					iterator tmpPre = pre;
					pre = merge( pre, idx1, idx2, NULL );
					que.push(tmpPre->next);
				}else{
					iterator tmpPre = pre;
					pre = merge( pre, idx1, idx2, que.front() );
					que.push(tmpPre->next);
				}
			}
			if( tmpLen == 1 ){
				que.push( que.front() );
				que.pop();
			}

			len = (len+1)/2;
		}

		return phead->next;
	}
};
