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
    // bool isMinima(ListNode * curr, ListNode * prev, ListNode * forward)
    // {
    //     if(prev == NULL || forward == NULL)
    //        return false;
    //     if(curr -> val < prev -> val  &&  curr-> val < forward -> val)
    //        return true;
    //     else return false;
    // }

    // bool isMaxima(ListNode * curr, ListNode * prev, ListNode * forward)
    // {
    //     if(prev == NULL || forward == NULL)
    //        return false;
    //     if(curr -> val > prev -> val  &&  curr-> val > forward -> val)
    //        return true;
    //     else return false;
    // }
    bool isCritical(ListNode * curr, ListNode * prev, ListNode * forward)
    {
         if(prev == NULL || forward == NULL)
              return false;
         if(curr -> val < prev -> val  &&  curr-> val < forward -> val)
              return true;
         if(curr -> val > prev -> val  &&  curr-> val > forward -> val)
              return true;
         return false;
    }
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ios::sync_with_stdio(0);
        
        if(head == NULL || head -> next == NULL || head -> next -> next == NULL)
           return {-1, -1};
        ListNode * prev = NULL, *curr = head, *forward = NULL;
        vector<int> ans(2);
        int index = 1;
        vector<int> indices;
        ListNode * temp = head;
        while(temp != nullptr)
        {
            forward = temp -> next;
            if(isCritical(temp, prev, forward))
            {
                indices.push_back(index);
            }
            index++;
            temp = temp -> next;
            prev = curr; curr = temp;
        }
        for(auto i : indices)
          cout<<i <<" ";
        if(indices.empty())
           return {-1, -1};
        if(indices.size() == 1)
           return {-1,-1};
        ans[1] = indices[indices.size() - 1] - indices[0];
        int mini = INT_MAX;
        for(int i = 1; i < indices.size(); i++)
        {
            mini = min(mini, indices[i] - indices[i - 1]);
        }
        ans[0] = mini;
        return ans;
    }
};














