/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ios::sync_with_stdio(0);
        if(head == nullptr || head -> next == nullptr)
           return false;
        if(head -> next == head)
           return true;
        
        ListNode * slow = head, *fast = head;
        while(fast != NULL && fast -> next != NULL)
        {
            slow = slow -> next;
            fast = fast -> next -> next;
            if(slow == fast)
              return true;
        }
        return false;
    }
};