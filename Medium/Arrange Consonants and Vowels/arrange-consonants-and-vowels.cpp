//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printlist(Node *head) {
    if (head == NULL)
        return;
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void append(struct Node **headRef, char data) {
    struct Node *new_node = new Node(data);
    struct Node *last = *headRef;

    if (*headRef == NULL) {
        *headRef = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    return;
}


// } Driver Code Ends
/*
Structure of the node of the linked list is as
struct Node
{
    char data;
    struct Node *next;

    Node(char x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:
    // task is to complete this function
    // function should return head to the list after making
    // necessary arrangements
    struct Node* arrangeCV(Node* head) {
        // Code here
        struct Node* vowelH = NULL;
        struct Node* otherH = NULL;
        struct Node* vowelT = NULL;
        struct Node* otherT = NULL;
        struct Node* ptr = head;
        string vowels = "aeiou";
        while(ptr){
            if(find(vowels.begin(), vowels.end(), ptr->data) != vowels.end()){
                if(vowelH == NULL){
                    vowelH = ptr;
                    vowelT = ptr;
                }else{
                    vowelT->next = ptr;
                    vowelT = vowelT->next;
                }
            }else{
                if(otherH == NULL){
                    otherH = ptr;
                    otherT = ptr;
                }else{
                    otherT->next = ptr;
                    otherT = otherT->next;
                }
            }
            ptr = ptr->next;
        }
        if(vowelH == NULL){
            return otherH;
        }
        vowelT->next = otherH;
        otherT->next = NULL;
        return vowelH;
    }
};


//{ Driver Code Starts.

// task is to complete this function
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        char tmp;
        struct Node *head = NULL;
        cin >> n;
        while (n--) {
            cin >> tmp;
            append(&head, tmp);
        }
        Solution obj;
        head = obj.arrangeCV(head);
        printlist(head);
    }
    return 0;
}

// } Driver Code Ends