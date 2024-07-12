//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    private:
    Node* reverse(Node * head)
    {
        if(head == NULL || head -> next == NULL)  return head;
        
        Node * curr = head, *prev = NULL, * forward = NULL;
        while(curr != NULL)
        {
            forward = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* num1, struct Node* num2)
    {
        // code here
        Node*dummy = new Node(0), *tail = dummy;
        int carry = 0;
        num1 = reverse(num1);
        num2 = reverse(num2);
        
        while(num1 != NULL && num2 != NULL){
            int number = num1 -> data + num2 -> data + carry;
            if(number <= 9){
                Node* temp = new Node(number);
                tail -> next = temp;
                tail = temp;
                carry = 0;
            }
            else{
                Node*temp = new Node(number % 10);
                carry = 1;
                tail -> next = temp;
                tail = temp;
            }
            num1 = num1 -> next;
            num2 = num2 -> next;
        }
        while(num1 != nullptr){
            int number = num1 -> data + carry;
             if(number <= 9){
                Node* temp = new Node(number);
                tail -> next = temp;
                tail = temp;
                carry = 0;
            }
            else{
                Node*temp = new Node(number % 10);
                carry = 1;
                tail -> next = temp;
                tail = temp;
            }
            num1 = num1 -> next;
        }
        while(num2 != nullptr){
            int number = num2 -> data + carry;
             if(number <= 9){
                Node* temp = new Node(number);
                tail -> next = temp;
                tail = temp;
                carry = 0;
            }
            else{
                Node*temp = new Node(number % 10);
                carry = 1;
                tail -> next = temp;
                tail = temp;
            }
            num2 = num2 -> next;
        }
        if(carry != 0){
            Node * temp = new Node(1);
            tail -> next = temp;
            tail = temp;
        }
        Node * ans = reverse(dummy -> next);
        bool flag = false;
        
        if(ans -> data == 0) flag = true;
        
        while(ans != NULL && ans-> next != NULL && flag){
            ans = ans-> next;
            if(ans -> data != 0) flag = false;
        }
        return ans;
    }
};











































//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* num1 = buildList(n);
        
        cin>>m;
        Node* num2 = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(num1,num2);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends