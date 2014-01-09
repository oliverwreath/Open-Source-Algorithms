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

	void find( iterator phead, iterator& pre, iterator& mPtr, int m ){
		while( m-- > 1 ){
			phead = phead->next;
		}
		pre = phead;
		phead = phead->next;
		mPtr = phead;

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
			iterator mPtr;
			find( phead, pre, mPtr, m ); 

			iterator sl = mPtr; 
			iterator fst = sl->next;
			iterator tmp = fst->next;
			iterator begin = sl;

			//between
			F( i, 1, n-m-1 ){
				fst->next = sl;
				sl = fst;
				fst = tmp;
				tmp = tmp->next;
			}
			//last
			iterator end = fst;
			iterator suc = fst->next;
			fst->next = sl;
			//final process
			pre->next = end;
			begin->next = suc;
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
