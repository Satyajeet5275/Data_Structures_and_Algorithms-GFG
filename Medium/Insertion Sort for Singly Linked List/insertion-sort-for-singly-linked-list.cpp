//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};

/* Function to print linked list */
void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}




// } Driver Code Ends
//User function Template for C++

/*Link list node
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};*/

class Solution
{
    public:
Node* insertionSort(struct Node* root)
    {
        if(!root || !root->next)return root;
        struct Node *dummy=new Node(0);
        dummy->next=root;
        struct Node* p=root, *q=dummy, *prev=root, *cur=root->next, *nextOne;
        while(cur){
            nextOne=cur->next;
            while(p->data<cur->data){
                q=p;
                p=p->next;
            }
            
            if(p!=cur){
                q->next=cur;
                cur->next=p;
                prev->next=nextOne;
                cur=nextOne;
            }
            else{
                prev=cur;
                cur=nextOne;
            }

            q=dummy;
            p=dummy->next;
        }
        return dummy->next;
    }


    
};

//{ Driver Code Starts.
int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int n;
		cin >> n;

		Node *head = NULL;
		Node *temp = head;

		for (int i = 0; i < n; i++) {
			int data;
			cin >> data;
			if (head == NULL)
				head = temp = new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}

        Solution ob;

		head = ob.insertionSort(head);
		printList(head);

		cout << "\n";



	}
	return 0;
}
// } Driver Code Ends