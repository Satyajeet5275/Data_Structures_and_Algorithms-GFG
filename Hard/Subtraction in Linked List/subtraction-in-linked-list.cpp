//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Node Class
class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(NULL) {}
};

// Linked List Class
class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() : head(NULL), tail(NULL) {}

    // creates a new node with given value and appends it at the end of the linked list
    void insert(int val) {
        if (head == NULL) {
            head = new Node(val);
            tail = head;
        } else {
            tail->next = new Node(val);
            tail = tail->next;
        }
    }
};


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    Node *reverseList(Node *head){
        Node *prev = NULL, *curr = head;
        while(curr!=NULL){
            Node *frwd = curr->next;
            curr->next = prev;
            prev = curr;
            curr = frwd;
        }
        return prev;
    }
    int getLength(Node *head){
        int len = 0;
        Node *curr = head;
        while(curr!=NULL){
            len++;
            curr = curr->next;
        }
        return len;
    }
    Node *removeZeros(Node *head){
        while(head!=NULL && head->data==0){
            head = head->next;
        }
        return head;
    }
    Node* subLinkedList(Node* head1, Node* head2) {
        
        // step1 : remove trailing zeros
        head1 = removeZeros(head1);
        head2 = removeZeros(head2);
        
        // step2 check which linked list is bigger
        int len1 = getLength(head1);
        int len2 = getLength(head2);
        if(len1<len2){
            swap(head1,head2);
        }else if(len1==len2){
            Node *curr1 = head1, *curr2 = head2;
            while(curr1!=NULL && curr2!=NULL && curr1->data == curr2->data){
                curr1 = curr1->next;
                curr2 = curr2->next;
            }
            if(curr1==NULL && curr2==NULL) return new Node(0);
            if(curr1->data < curr2->data)
                swap(head1,head2);
        }
        
        // step3 reverse the linked list
        head1 = reverseList(head1);
        head2 = reverseList(head2);
        
        // step4 substraction
        Node *dummy = new Node(-1);
        Node *curr = dummy;
        int carry = 0;
        while(head1!=NULL && head2!=NULL){
            int n1 = head1->data - carry;
            int n2 = head2->data;
            int val;
            if(n1>=n2){
                val = n1-n2;
                carry = 0;
            }else{
                val = (n1 + 10) - n2;
                carry = 1;
            }
            curr->next = new Node(val);
            curr = curr->next;
            head1 = head1->next;
            head2 = head2->next;
        }
        while(head1!=NULL){
            int n1 = head1->data - carry;
            int val;
            if(n1<0){
                val = n1 + 10;
                carry = 1;
            }else{
                val = n1;
                carry = 0;
            }
            curr->next = new Node(val);
            curr = curr->next;
            head1 = head1->next;
        }
        Node *result = dummy->next;
        result = reverseList(result);
        result = removeZeros(result);
        return result;
    }
};

//{ Driver Code Starts.

// prints the elements of linked list starting with head
void printList(Node* n) {
    while (n) {
        cout << n->data;
        n = n->next;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        LinkedList LL1;
        string l1,l2;
        cin>>l1;
        for (int j = 0; j < n; ++j) {
            int x=(l1[j]-'0');
            LL1.insert(x);
        }

        int m;
        cin >> m;
        LinkedList LL2;
        cin>>l2;
        for (int j = 0; j < m; ++j) {
            int x=(l2[j]-'0');
            LL2.insert(x);
        }

        Solution ob;
        Node* res = ob.subLinkedList(LL1.head, LL2.head);
        printList(res);
    }

    return 0;
}

// } Driver Code Ends