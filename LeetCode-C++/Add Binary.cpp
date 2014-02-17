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
	string addBinary(string a, string b) {
		int m = a.size();
		int n = b.size();
		if( m == 0 ){
			return b;
		}
		if( n == 0 ){
			return a;
		}

		if( m > n ){ 
			//m larger 
			int len = m; 
			int carry = 0; 
			int diff = m - n;
			FB( i, len-1, 0 ){ 
				int sum = carry;
				sum += a[i]-'0';
				if( i-diff > -1 ){ sum += b[i-diff]-'0'; }

				if( sum > 1 ){
					carry = 1;
					sum -= 2;
				}else{
					carry = 0;
				}

				if( sum == 0 ){
					a[i] = '0';
				}else{
					a[i] = '1';
				}
			}
			if( carry == 1 ){
				a.insert( a.begin(), '1' ); 
			}
			return a;
		}else{ 
			//n larger 
			int len = n;
			int carry = 0;
			int diff = n - m;
			FB( i, len-1, 0 ){
				int sum = carry;
				if( i-diff > -1 ){ sum += a[i-diff]-'0'; }
				sum += b[i]-'0';

				if( sum > 1 ){
					carry = 1;
					sum -= 2;
				}else{
					carry = 0;
				}

				if( sum == 0 ){
					b[i] = '0';
				}else{
					b[i] = '1';
				}
			}
			if( carry == 1 ){
				b.insert( b.begin(), '1' );
			}
			return b;
		}
	}
};
