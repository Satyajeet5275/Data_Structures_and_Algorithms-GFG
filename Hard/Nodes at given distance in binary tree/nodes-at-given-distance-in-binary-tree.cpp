//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution
{
private:

public:

    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        // return the sorted vector of all nodes at k dist
        unordered_map<Node*, Node*> parantNode;
        findParantNode(parantNode, root);
        
        Node* targetNode = findTargetNode(root, target);
        unordered_map<Node*, bool> visited;
        
        queue<Node*> kNode;
        kNode.push(targetNode);
        visited[targetNode] = true;
        int distence = 0;
        
        while(!kNode.empty() && distence != k){
            int size = kNode.size();
            for(int i = 0; i < size; i++){
                Node* current = kNode.front();
                kNode.pop();
                
                if(current->left && !visited[current->left]){
                    kNode.push(current->left);
                    visited[current->left] = true;
                }
                
                if(current->right && !visited[current->right]){
                    kNode.push(current->right);
                    visited[current->right] = true;
                }
                
                if(parantNode[current] && !visited[parantNode[current]]){
                    kNode.push(parantNode[current]);
                    visited[parantNode[current]] = true;
                }
            }
            distence++;
        }
        vector<int> result;
        while(!kNode.empty()){
            Node* current = kNode.front();
            kNode.pop();
            result.push_back(current->data);
        }
        
        sort(result.begin(), result.end());
        
        return result;
    }
    
    void findParantNode(unordered_map<Node*, Node*>& parantNode, Node* root){
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            Node* current = q.front();
            q.pop();
            if(current->left){
                parantNode[current->left] = current;
                q.push(current->left);
            }
            if(current->right){
                parantNode[current->right] = current;
                q.push(current->right);
            }
        }
    }
    
    /*Node* findTargetNode(Node* root, int target){
        if(root == NULL) return NULL;
        if(root->data == target) return root;
        if(root->left){findTargetNode(root->left, target);}
        if(root->right){findTargetNode(root->right, target);}
        return NULL;
    }*/
    Node* findTargetNode(Node* root, int target) {
        if (root == NULL) return NULL;
        if (root->data == target) return root;
        Node* leftSearch = findTargetNode(root->left, target);
        if(leftSearch) return leftSearch; // returning if found in left subtree
        Node* rightSearch = findTargetNode(root->right, target);
        if(rightSearch) return rightSearch; // returning if found in right subtree
        return NULL;
    }


};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    Solution x = Solution();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int target, k;
        cin>> target >> k;
        getchar();
        
        vector <int> res = x.KDistanceNodes(head, target, k);
        
        for( int i=0; i<res.size(); i++ )
            cout<< res[i] << " ";
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends