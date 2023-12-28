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
    public:
    //Function to add two numbers represented by linked list.
    public:
    //Function to add two numbers represented by linked list.
    Node* reverseLL(Node* head)
    {
        if(head==NULL || head->next==NULL){
            return head;
        }
        Node* curr=head, *prev=NULL;
        while(curr!=NULL){
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        Node* first_head = reverseLL(first);
        Node* second_head = reverseLL(second);
        
        int carry = 0;
        Node* newHead = new Node(-1);
        Node* tail = newHead;
        int val;
        
        while(first_head!=NULL || second_head!=NULL)
        {
            
            if(first_head==NULL)
            {
                val = second_head->data + carry;
                second_head = second_head->next;
            }
            else if(second_head==NULL)
            {
                val = first_head->data + carry;
                first_head = first_head->next;
            }
            else
            {
                val = first_head->data + second_head->data + carry;
                first_head = first_head->next;
                second_head = second_head->next;
            }
            
            if(val>9)
            {
                val = val%10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            
            Node* temp = new Node(val);
            tail->next = temp;
            tail = tail->next;
            
        }
        
        if(carry==0)
        {
            return reverseLL(newHead->next);    
        }
        else
        {
            tail->next = new Node(1);
            tail = tail->next;
            return reverseLL(newHead->next);
        }
        
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
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends