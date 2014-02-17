#define F(i, a, b) for(int i = a; i <= b; i++)
#define FF(i, a, b) for( i = a; i <= b; i++)
#define F3(i, a, b) for(int i = a; i <= b; i+=3)
#define FB(i, a, b) for(int i = a; i >= b; i--)
#define MAX2(a, b) a>b?a:b
#define MAX3( a, b, c ) a>b?(a>c?a:c):(b>c?b:c)
#define MIN2(a, b) a<b?a:b

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <tuple>
#include <iterator>
#include <stack>
#include <algorithms>

class Solution {
public:
	//typedef 
	typedef ListNode* iterator; 

	//methods

    ListNode *swapPairs(ListNode *head) {
        if( head == NULL || head->next == NULL ){
        	return head; 
        }

        iterator phead = new ListNode(0);
        phead->next = head; 

        iterator pp = phead; 
        iterator slo = head; 
        iterator fst = head->next; 

        while(1){
        	slo->next = fst->next; 
        	pp->next = fst; 
        	fst->next = slo; 

        	if( slo->next == NULL ){
        		return phead->next; 
        	}else if( slo->next->next == NULL ){
        		return phead->next; 
        	}else{
        		pp = slo;
        		slo = slo->next; 
        		fst = slo->next; 
        	}
        }

        return phead->next; 
    }
};
