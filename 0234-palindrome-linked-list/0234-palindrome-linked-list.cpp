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
    ListNode* reverse(ListNode* head) {
        if(head == NULL || head -> next == NULL)
          return head;
        ListNode* curr = head, *prev = NULL, *forward = NULL;
        while(curr != nullptr)
        {
            forward = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head -> next == NULL)
          return true;
        ListNode * slow = head, * fast = head;
        while(fast != NULL && fast -> next != NULL)
        {
            fast = fast -> next -> next;
            if(fast != nullptr)
              slow = slow -> next;
        }
        //Now slow is pointing at the mid Node;
        slow -> next = reverse(slow -> next);
        ListNode *temp1 = head, *temp2 = slow-> next;
        if(temp1 ->val != temp2 -> val) return false;
        while(temp2 != nullptr)
        {
            if(temp2 -> val != temp1 -> val) return false;
            temp1 = temp1 -> next;
            temp2 = temp2 -> next;
        }
        return true;
    }
};