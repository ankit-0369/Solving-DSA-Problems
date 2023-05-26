//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position)
{
    if(position==0) return;
    
    Node* walk = head;
    for(int i=1; i<position; i++)
        walk = walk->next;
    tail->next = walk;
}

int countNodesinLoop(Node* head);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, num;
        cin>>n;
        
        Node *head, *tail;
        cin>> num;
        head = tail = new Node(num);
        
        for(int i=0 ; i<n-1 ; i++)
        {
            cin>> num;
            tail->next = new Node(num);
            tail = tail->next;
        }
        
        int pos;
        cin>> pos;
        loopHere(head,tail,pos);
        
        cout<< countNodesinLoop(head) << endl;
    }
	return 0;
}

// } Driver Code Ends


/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

//Function to find the length of a loop in the linked list.

Node* floydAlgo(struct Node* head){
    Node* slow= head;
    Node* fast= head;
    while(fast!= NULL && fast->next!= NULL){
        fast= fast->next->next;
        slow= slow->next;
        
        if(slow==fast){
            return slow;
        }
    }
    
    return false;
}

int cntLength(struct Node* head, struct Node* cutPoint){
        
        Node* cur= head;
        while(cur!= NULL){
            if(cur==cutPoint){
                break;
            }
            
            cur= cur->next;
            cutPoint= cutPoint->next;
        }
        
        int cnt=1;
        // cout<<cur->data<<endl;
        if(cur!=NULL){
             while(cur->next!= cutPoint){
            cnt++;
            cur= cur->next;
        }
    }
       
    
    return cnt;
}


int countNodesinLoop(struct Node *head)
{
    // Code here
    Node* cutPoint= floydAlgo(head);
    
    // cout<<cutPoint->data<<endl;
    
    if(cutPoint){
        return cntLength(head,cutPoint);
    }
    
    return 0;
    
}