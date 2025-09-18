/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        if(head == null) return head;
        if(head.next == null && n == 1) return null;
        int count = 0; 
        ListNode temp = head;
        while(temp != null){
            count++; 
            temp = temp.next;
        }
        if (count == n) return head.next;
        int k = count - n + 1;
        ListNode prev = null;
        ListNode toDel = head;
        ListNode forward = null;
        for(int i = 0; i<k-2; i++){
            toDel = toDel.next;
        }
        prev = toDel;
        if(toDel.next == null){
            prev.next = null;
            return head;
        }
        toDel = toDel.next;
        forward = toDel.next;
        prev.next = forward;
        return head;
    }
}