/**
 * Definition for singly-linked list.
 * public class ListNode {
 *	 int val;
 *	 ListNode next;
 *	 ListNode(int x) {
 *		 val = x;
 *		 next = null;
 *	 }
 * }
 */
public class Solution {
	public static ListNode mergeTwoLists(ListNode l1, ListNode l2) {
		ListNode phead = new ListNode(0);
		ListNode tail = phead;
		while( true ){
			if( l1 == null ){
				if( l2 == null ){
					break; 
				}else{
					while( l2 != null ){
						tail.next = l2;
						tail = l2;
						l2 = l2.next; 
					}
				}
			}else{
				if( l2 == null ){
					while( l1 != null ){
						tail.next = l1;
						tail = l1;
						l1 = l1.next; 
					}
				}else{
					if( l1.val < l2.val ){
						tail.next = l1;
						tail = l1;
						l1 = l1.next; 
					}else{
						tail.next = l2;
						tail = l2;
						l2 = l2.next; 
					}
				}
			}
		}

		return phead.next;
	}
}
