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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ios::sync_with_stdio(0);
        vector<int> arr1, arr2;
        ListNode* temp1 = l1, *temp2 = l2;
        while(temp1 != nullptr)
        {
            arr1.push_back(temp1 -> val);
            temp1 = temp1 -> next;
        }
        while(temp2 != nullptr)
        {
            arr2.push_back(temp2 -> val);
            temp2 = temp2 -> next;
        }
        int i = 0, j = 0;
        vector<int> arr3;
        int carry = 0;
        while(i < arr1.size() && j < arr2.size())
        {
            int num = arr1[i] + arr2[j] + carry;
            if(num <= 9){
                arr3.push_back(num);
                carry = 0;
            }
            else{
                arr3.push_back(num%10);
                carry = 1;
            }
            i++; j++;
        }
        while( i < arr1.size())
        {
            int num = arr1[i] + carry;
            if(num <= 9){
                arr3.push_back(num);
                carry = 0;
            }
            else{
                arr3.push_back(num % 10);
                carry = 1;
            }
            i++;
        }
        while( j < arr2.size())
        {
            int num = arr2[j] + carry;
            if(num <= 9){
                arr3.push_back(num);
                carry = 0;
            }
            else{
                arr3.push_back(num % 10);
                carry = 1;
            }
            j++;
        }
        if(carry >0)  arr3.push_back(carry);
        // reverse(arr3.begin(), arr3.end());
        ListNode * dummy = new ListNode(0), *tail = dummy;
        for(int k = 0; k < arr3.size(); k++)
        {
            ListNode * temp = new ListNode(arr3[k]);
            tail -> next = temp;
            tail = temp;
        }


        return dummy -> next;
    }
};