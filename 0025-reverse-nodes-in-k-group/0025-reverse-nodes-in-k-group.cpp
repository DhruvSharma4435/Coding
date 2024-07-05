/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        //base case
        if(head == nullptr)
          return NULL;
        
        ListNode * temp = head;
        for(int j = 0; j < k; j++)
        {
            if(temp == nullptr)
              return head;
            temp = temp -> next;
        }
        ListNode * curr = head, *prev = NULL, *forward = NULL;
        int count = 0;
        while(curr != nullptr && count < k)
        {
            forward = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forward;
            count++;
        }
        if(forward != nullptr)
            head -> next = reverseKGroup(forward, k);
        return prev; 
    }
};