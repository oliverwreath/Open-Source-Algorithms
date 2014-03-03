/**
 * Definition for singly-linked list.
 * class ListNode {
 *	 int val;
 *	 ListNode next;
 *	 ListNode(int x) {
 *		 val = x;
 *		 next = null;
 *	 }
 * }
 */
public class Solution {
	public boolean hasCycle(ListNode head) {
		boolean ret = false; 

		if( head == null ){
			return false; 
		}
		ListNode fst = head; 
		ListNode slo = new ListNode(0);
		slo.next = head; 

		while( fst.next != null && fst.next.next != null ){
			slo = slo.next;
			fst = fst.next.next;
			if( slo == fst ){
				return true; 
			}
		}

		return false; 
	}
}
