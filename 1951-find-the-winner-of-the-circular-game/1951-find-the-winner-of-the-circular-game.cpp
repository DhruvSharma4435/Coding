#include<list>
class Solution {
public:
    int findTheWinner(int n, int k) {
        ios::sync_with_stdio(0);
        if(n == 1)
           return 1;
        ListNode * head = new ListNode(1);
        ListNode * tail = head, *prev1 = head;
        for(int i = 2; i <= n +1; i++)
        {
            prev1 = tail;
            ListNode * temp = new ListNode(i);
            tail -> next = temp;
            tail = tail -> next;
        }
        prev1 -> next = head;
        delete tail;
       
        while(prev1 -> next != prev1)
        {
            for(int i = 1; i< k; i++)
            {
                prev1 = prev1 -> next;
            }
            ListNode *del = prev1 -> next;
            prev1 -> next = del -> next;
            delete del;
           
        }
        return prev1 -> val;
    }
};