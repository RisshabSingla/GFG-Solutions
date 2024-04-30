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
    struct Node* reverseList(struct Node* head){
        struct Node* ptr = head;
        struct Node* prev = NULL;
        struct Node* next = NULL;
        while(ptr){
            next = ptr->next;
            ptr->next = prev;
            prev = ptr;
            ptr = next;
        }
        return prev;
    }
    
    void printList(struct Node* head){
        struct Node* ptr = head;
        cout<<"List is: ";
        while(ptr){
            cout<<ptr->data<<" ";
            ptr = ptr->next;
        }
        cout<<"\n";
        
    }
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* num1, struct Node* num2)
    {
        if(num1 == NULL){
            return num2;
        }
        if(num2 == NULL){
            return num1;
        }
        
        struct Node* ptr1 = reverseList(num1);
        struct Node* ptr2 = reverseList(num2);
        
        // printList(ptr1);
        // printList(ptr2);
        
        struct Node* head = new Node(-1);
        struct Node* temp = head;
        
        int carry = 0;
        
        while(ptr1 && ptr2){
            int val = ptr1->data + ptr2->data + carry;
            carry = val / 10;
            temp->next = new Node(val % 10);
            temp = temp->next;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        
        while(ptr1){
            int val = ptr1->data + carry;
            carry = val / 10;
            temp->next = new Node(val % 10);
            temp = temp->next;
            ptr1 = ptr1->next;
        }
        
        while(ptr2){
            int val = ptr2->data + carry;
            carry = val / 10;
            temp->next = new Node(val % 10);
            temp = temp->next;
            ptr2 = ptr2->next;
        }
        
        // printList(head);
        if(carry != 0){
            temp->next = new Node(carry);
            temp = temp->next;
        }
        
        head =  reverseList(head->next);
        while(head->next && (head->data == 0)){
            head = head->next;
        }
        return head;
        
        // code here
        
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