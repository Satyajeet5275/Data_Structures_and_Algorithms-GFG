//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};

void print(struct Node *Node)
{
    while (Node!=NULL)
    {
        cout << Node->data << " ";
        Node = Node->next;
    }
}


Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}


// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
};

*/
class Solution
{
    public:
    
Node* reverse(Node* head){
        if(head==NULL || head->next==NULL) return head;
        Node* prev=NULL;
        Node* node=head;
        while(node!=NULL){
            Node* temp=node->next;
            node->next=prev;
            prev=node;
            node=temp;
        }
        return prev;
    }
    
    struct Node * mergeResult(Node *node1,Node *node2)
    {
        // your code goes here
        if(node1==NULL && node2==NULL) return NULL;
        else if(node1==NULL) return reverse(node2);
        else if(node2==NULL) return reverse(node1);
        Node* n1=node1, *n2=node2;
        Node* d=new Node{-1, NULL};
        Node* nxt=d;
        while(n1!=NULL && n2!=NULL){
            if(n1->data<=n2->data){
                nxt->next=n1;
                nxt=n1;
                n1=n1->next;
            }else{
                nxt->next=n2;
                nxt=n2;
                n2=n2->next;
            }
        }
        if(n1!=NULL) nxt->next=n1;
        if(n2!=NULL) nxt->next=n2;
        
        return reverse(d->next);
    } 
};


//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int nA;
        cin>>nA;
        int nB;
        cin>>nB;

        struct Node* headA=NULL;
        struct Node* tempA = headA;

        for(int i=0;i<nA;i++)
        {
            int ele;
            cin>>ele;
            if(headA==NULL)
            {
                headA=tempA=newNode(ele);

            }else{
                tempA->next = newNode(ele);
				tempA=tempA->next;
            }
        }

        struct Node* headB=NULL;
        struct Node* tempB = headB;


        for(int i=0;i<nB;i++)
        {
            int ele;
            cin>>ele;
            if(headB==NULL)
            {
                headB=tempB=newNode(ele);

            }else{
                tempB->next = newNode(ele);
				tempB=tempB->next;
            }
        }
        
        Solution ob;
        struct Node* result = ob.mergeResult(headA,headB);

        print(result);
        cout<<endl;


    }
}

// } Driver Code Ends