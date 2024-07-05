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
private:
    ListNode* solve(ListNode *head, int k)
    {
        if(head == nullptr)
          return head;
        ListNode * temp = head;
        int cnt = k;
        int i = 0;
        for(; i< cnt && temp != nullptr; i++)
        {
            temp = temp -> next;
            
            // if(temp == nullptr)
            //   return head;
        }
        ListNode * small = solve(temp, k);
        if(i == k)
        {
        ListNode * prev = nullptr, *curr = head, *forward = nullptr;
        for(int i = 0; i< k && curr != nullptr; i++)
        {
            forward = curr-> next;
            curr -> next = prev;
            prev = curr;
            curr = forward;
        }
        head -> next = small;
        return prev;
        }
        else 
         return head;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        return solve(head, k);
    }
};