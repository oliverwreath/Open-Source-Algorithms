



public class Solution {
	public ListNode removeNthFromEnd(ListNode head, int n) {
		if( head == null || n < 1 ){
			return head;
		}

		ListNode phead = new ListNode(0);
		phead.next = head; 
		if( n == 1 ){
			ListNode slo = phead; 
			ListNode fst = head; 
			while( fst.next != null ){
				slo = fst;
				fst = fst.next;
			}
			slo.next = null;

			return phead.next;
		}else{
			if( head.next == null ){
				return head;
			}
			ListNode pslo = phead; 
			ListNode slo = head; 
			ListNode fst = head.next;

			//move right for n-2 steps
			for( int i = 1; i <= n-2; i++ ){
				if( fst.next == null ){
					return head; 
				}else{ 
					fst = fst.next;
				}
			}

			while( fst.next != null ){
				pslo = slo;
				slo = slo.next;
				fst = fst.next; 
			}
			pslo.next = slo.next; 
		}

		return phead.next; 
	}
}



