/**
 * Definition for singly-linked list.
 * struct ListNode {
 *	 int val;
 *	 ListNode *next;
 *	 ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#define F(i, a, b) for( int i = a; i <= b; i++ )
#define FB(i, a, b) for( int i = a; i >= b; i-- )

class Solution {
public:
	bool isNumber(const char* s) {
		if( s == NULL || '\0' ){
			return true;
		}

		char* t = (char* )s;
		bool numberYet = false;
		bool eYet = false;
		bool dotYet = false;
		bool neg = false;
		while( (*t) == ' ' ){
			t++;
		}

		if( (*t) == '-' || (*t) == '+' ){
			neg = true;
			t++;
		}

		while( (*t) != '\0' ){
			if( (*t) == '.' ){
				if( dotYet || eYet ){
					return false;
				}
				dotYet = true;
			}else if( (*t) == 'e' ){
				if( eYet ){
					return false;
				}
				if( !numberYet ){
					return false;
				}
				eYet = true;
				numberYet = false;
				t++;
				if( (*t) == '-' || (*t) == '+' ){
					neg = true;
				}else{
					t--;
				}
			}else if( (*t) - '0' < 10 && (*t) - '0' > -1 ){
				numberYet = true;
			}else if( (*t) == ' ' ){
				while( (*t) == ' ' ){
					t++;
				}
				if( (*t) != '\0' ){
					return false;
				}else{
					break;
				}
			}else if( (*t) == '-' ){
				return false;
			}else{
				return false;
			}
			t++;
		}

		if( numberYet ){
			return true;
		}else{
			return false;
		}
	}
};
