//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

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
    Node* root = new Node(stoi(ip[0]));
        
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
            currNode->left = new Node(stoi(currVal));
                
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
            currNode->right = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends


class Solution
{
    public:
    //Function to find the nodes that are common in both BST. 
    vector<int> in1, in2;
    void inOrder(Node* root, vector<int>&ans){
        while(!root)
        return;
        
        inOrder(root->left, ans);
        ans.push_back(root->data);
        inOrder(root->right, ans);
    }
    
    bool search(vector<int> v, int n){
        int e= v.size()-1;
        int s= 0;
        int m= s + (e-s)/2;
        while(s<=e){
            
            if(v[m]==n){
                return true;
            }else if(v[m]>n){
                 e= m-1;
            }else
            s= m+1;
           
            
             m= s + (e-s)/2;
        }
        
        return false;
    }
    
    vector <int> findCommon(Node *root1, Node *root2)
    {
     //Your code here---
     //naive approach---
     
     vector<int> ans;
     inOrder(root1, in1);
     inOrder(root2, in2);
    
     //search---
     for(auto n: in1){
         if(search(in2, n)){
             ans.push_back(n);
         }
     }
     
     return ans;
     
    }
};




//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root1 = buildTree(s);

        getline(cin,s);
        Node* root2 = buildTree(s);
        Solution ob;
        vector <int> res = ob.findCommon(root1, root2);
        for (int i : res)
            cout << i << " ";
        cout<< endl;
    }

	return 1;
}
// } Driver Code Ends