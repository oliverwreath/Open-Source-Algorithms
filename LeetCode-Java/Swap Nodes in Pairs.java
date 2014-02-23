public class Solution {
	public static ListNode swapPairs(ListNode head) {
		if( head == null || head.next == null ){
			return head; 
		}

		ListNode phead = new ListNode(0);
		phead.next = head; 

		ListNode ssl = phead;
		ListNode sl = head; 
		ListNode fst = head.next; 
		while(fst != null){
			ssl.next = fst;
			sl.next = fst.next; 
			fst.next = sl;
			if( sl.next == null || sl.next.next == null ){
				fst = null;
			}else{
				ssl = sl;
				sl = ssl.next;
				fst = sl.next;
			}
		}

		return phead.next; 
	}
}
