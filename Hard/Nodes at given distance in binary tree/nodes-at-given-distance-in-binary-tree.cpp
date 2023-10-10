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
    Node* find(Node* root,int target,int k, unordered_map<Node*,Node*>&mp){
            Node* ans=NULL;
            queue<Node*>q;
            q.push(root);
            while(!q.empty()){
                Node *temp=q.front();
                q.pop();
                if(temp->data==target)
                 ans=temp;
                 if(temp->left){q.push(temp->left);
                   mp[temp->left]=temp;
                 }
                 if(temp->right){
                     q.push(temp->right);
                     mp[temp->right]=temp;
                 }
                 
            }
            return ans;
}
    vector<int> kth(Node *t,vector<int>&ans,unordered_map<Node*,Node*>&mp,int k){
    queue<Node*>q;
    q.push(t);
   
    unordered_map<Node*,int>vis;
     vis[t]=1;
    int count=0;
    while(!q.empty()){
        
        int size=q.size();
        while(size-- ){
           Node* temp=q.front();
           q.pop();
           if(temp->left && !vis[temp->left]){
               q.push(temp->left);
               vis[temp->left]=1;
               
           }
           if(temp->right && !vis[temp->right]){
               q.push(temp->right);
               vis[temp->right]=1;
           }
           if(mp.find(temp)!=mp.end() && vis[mp[temp]]==0){
               q.push(mp[temp]);
               vis[mp[temp]]=1;
           }
           
        }
        count++;
        if(count==k)
          break;
        
        
    }
    while(!q.empty()){
        ans.push_back(q.front()->data);
        q.pop();
    }
   sort(ans.begin(),ans.end());
   return ans;
}
    
    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        // return the sorted vector of all nodes at k dist---
         vector<int> ans;
        unordered_map<Node*,Node*>mp;
        Node *t=find(root,target,k,mp);
        return kth( t,ans,mp,k);
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