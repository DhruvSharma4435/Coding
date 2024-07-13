//{ Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  private:
    Node* findMid(Node *head) {
    if (head == NULL || head->next == NULL)
        return head;
    Node* slow = head;
    Node* fast = head->next;
    while (fast != NULL && fast->next != NULL) {
        fast = fast -> next -> next;
        if(fast != NULL) 
          slow = slow -> next;
    }
    return slow;
}
    
    Node* merge(Node* head1, Node* head2)
    {
        //This is not a recursive function
        Node* dummy = new Node(0),* tail = dummy;
        while(head1 != NULL  &&  head2 != NULL){
            if(head1 -> data < head2 -> data){
              Node * newNode = new Node(head1 -> data);;
              tail -> next = newNode;
              tail = newNode;
              head1 = head1 -> next;
            }
            else{
              Node * newNode = new Node(head2 -> data);;
              tail -> next = newNode;
              tail = newNode;  
              head2 = head2 -> next; 
            }
        }
        while(head1 != NULL){
            Node * newNode = new Node(head1 -> data);;
            tail -> next = newNode;
            tail = newNode;
            head1 = head1 -> next;
        }
        while(head2 != NULL){
            Node * newNode = new Node(head2 -> data);;
            tail -> next = newNode;
            tail = newNode; 
            head2 = head2 -> next;
        }
        return dummy -> next;
    }
  public:
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        // your code here
        if(head == NULL || head -> next == NULL)
           return head;
        
        Node*mid = findMid(head);
        Node*temp = mid -> next;
        mid -> next = NULL;
        
        Node *left = mergeSort(head);
        Node *right = mergeSort(temp);
        
        Node* ans = merge(left, right);
        return ans;
    }
};

























//{ Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}
// } Driver Code Ends