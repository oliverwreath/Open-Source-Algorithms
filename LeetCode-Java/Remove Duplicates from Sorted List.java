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
	public ListNode deleteDuplicates(ListNode head) {
		if( head == null || head.next == null ){
			return head;
		}

		ListNode sloPtr = head;
		ListNode fstPtr = head.next;

		while( fstPtr != null ){
			if( fstPtr.val == sloPtr.val ){
				fstPtr = fstPtr.next;
				sloPtr.next = fstPtr;
			}else{
				sloPtr = fstPtr;
				fstPtr = fstPtr.next;
			}
		}

		return head;
	}
}
