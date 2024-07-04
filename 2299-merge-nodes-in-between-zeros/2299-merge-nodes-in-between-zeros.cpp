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
    ListNode* mergeNodes(ListNode* head) {
        ios::sync_with_stdio(0);
        ListNode * temp = head;
        ListNode * conc = head;
        int sum = 0;
        while(temp -> next != NULL)
        {
            if(temp -> val == 0)
            {
                temp = temp -> next; continue;
            }
            while(temp -> next != NULL)
            {
                sum += temp -> val;
                if(temp -> next -> val != 0)
                {
                    temp = temp ->next;
                }
                else 
                {
                    temp = temp -> next;
                    conc -> next = temp;
                    conc = conc -> next;
                    conc -> val = sum;
                    sum = 0 - sum;
                    break;
                }
                
            }
        }

        return head -> next;
    }
};