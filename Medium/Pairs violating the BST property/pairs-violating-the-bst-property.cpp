//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// A Tree node
struct Node {
    int data;
    struct Node *left, *right;
};

// Utility function to create a new node
Node* newNode(int data) {
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return (temp);
}

Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

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
// User function Template for C++

/*// A Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};*/

class Solution {
  public:
    
    /*You are required to complete below function */
    
    void inOrder(Node* root, vector<int>& in){
        if(!root) return;
        inOrder(root->left, in);
        in.push_back(root->data);
        inOrder(root->right, in);
        return;
    }
    
    void merge(vector<int>& in, int left, int mid, int right, int &ans){
        vector<int> temp;
        int i= left, j= mid+1;
        // int inv=0;
        while(i<=mid && j<=right){
            if(in[i]<= in[j]){
                temp.push_back(in[i++]);
            }else{
                // inv+= (mid-i + 1);
                ans+= (mid-i +1);
                temp.push_back(in[j++]);
            }
        }
        
        while(i<=mid) temp.push_back(in[i++]);
        while(j<=right) temp.push_back(in[j++]);
        
        for(int i= left; i<=right; i++){
            in[i]= temp[i-left];
        }
        return;
        // return inv;
    }
    
    
    
    void mergeSort(vector<int>& in, int left, int right, int &ans){
        if(left >= right) return;
        
        if(left < right){
            int mid= left + (right- left)/2;
            // ans+= mergeSort(in, left, mid);
            // ans+= mergeSort(in, mid+1, right);
            // ans+= merge(in, left, mid, right);
            mergeSort(in, left, mid, ans);
            mergeSort(in, mid+1, right, ans);
            merge(in, left, mid, right, ans);
        }
        
        // return ans;
    }
    
    
    int pairsViolatingBST(int n, Node *root) {
        // your code goes here---
        vector<int> in;
        inOrder(root, in);
        // for(auto v: in) cout<<v<<" ";
        int ans= 0;
        mergeSort(in, 0, n-1, ans);
        
    
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    getchar();

    while (t--) {

        int n;
        cin >> n;
        getchar();

        string inp;
        getline(cin, inp);

        struct Node* root = buildTree(inp);

        Solution ob;
        int ans = ob.pairsViolatingBST(n, root);
        cout << ans << endl;
    }

    return 0;
}
// } Driver Code Ends