/**
 * Definition for singly-linked list.
 * struct ListNode {
 *	 int val;
 *	 ListNode *next;
 *	 ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
	//typedef
	typedef ListNode* iterator;

	//methods
	void swap( int& m, int& n ){
		int tmp = m;
		m = n;
		n = tmp;
		return ;
	}

	void find( iterator phead, iterator& pre, iterator& mPtr, iterator& nPtr, int& m, int& n ){
		n -= m;
		while( m-- > 1 ){
			phead = phead->next;
		}
		pre = phead;
		phead = phead->next;
		mPtr = phead;

		while( n-- > 0 ){
			phead = phead->next;
		}
		nPtr = phead;
		return ;
	}

	void find( iterator phead, iterator& pre, iterator& mPtr, iterator& npre, iterator& nPtr, int& m, int& n ){
		n -= m;
		while( m-- > 1 ){
			phead = phead->next;
		}
		pre = phead;
		phead = phead->next;
		mPtr = phead;

		while( n-- > 1 ){
			phead = phead->next;
		}
		npre = phead;
		phead = phead->next;
		nPtr = phead;
		return ;
	}
	
	ListNode *reverseBetween(ListNode *head, int m, int n){
		if( head == NULL || m == n ){
			return head; 
		}

		iterator phead = new ListNode(0);
		phead->next = head; 

		if( m > n ){
			swap( m, n );
		}
		if( m + 1 < n ){ 
			//case 1
			iterator pre;
			iterator npre;
			iterator mPtr;
			iterator nPtr;
			find( phead, pre, mPtr, npre, nPtr, m, n ); 

			pre->next = nPtr;
			npre->next = mPtr;
			iterator tmp = mPtr->next;
			mPtr->next = nPtr->next;
			nPtr->next = tmp;
		}else{
			//case 2
			iterator pre;
			iterator mPtr;
			iterator nPtr;
			find( phead, pre, mPtr, nPtr, m, n ); 

			pre->next = nPtr;
			mPtr->next = nPtr->next;
			nPtr->next = mPtr;
		}

		return phead->next;
	}
};
