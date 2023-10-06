//{ Driver Code Starts
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
/* A linked list node */


struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

struct Node *start = NULL;

/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
    
}

void insert()
{
    int n,value;
    cin>>n;
    struct Node *temp;
    for(int i=0;i<n;i++)
    {
        cin>>value;
        if(i==0)
        {
            start = new Node(value);
            temp = start;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp = temp->next;
        }
    }
}


// } Driver Code Ends
/*
  reverse alternate nodes and append at the end
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
      int data;
      struct Node *next;
    
      Node(int x){
        data = x;
        next = NULL;
      }
    
   };

*/
class Solution
{
    public:
    
    struct Node* reverse(struct Node* head){
        struct Node* prev= NULL;
        struct Node* cur= head;
        while(cur){
            struct Node* agla= cur->next;
            cur->next= prev;
            prev= cur;
            cur= agla;
        }
        
        return prev;
    }
    
    // void printL(struct Node* head){
    //     cout<<endl;
    //     while(head){
    //         cout<<head->data<<" ";
    //         head= head->next;
            
    //     }
        
    //     cout<<endl;
    // }
    
    void rearrange(struct Node *odd)
    {
        //add code here----
        if(!odd->next)
        return;
        
        struct Node* alt= odd->next;
        struct Node* alt1= alt;
        struct Node* temp= odd;
        struct Node* tail= odd;
        while(alt1!= NULL){
         
            temp->next= alt1->next;
            tail= temp;
          if(alt1->next!= NULL)
          alt1->next= alt1->next->next;
           
            temp= temp->next;
            alt1= alt1->next;
        }
        
        if(tail->next)
        tail= tail->next;
        
        // printL(alt);
        
        struct Node* rev= reverse(alt);
        //  printL(rev);
        
        tail->next= rev;
    
        
    }
};















//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while (t--) {
        insert();
        Solution ob;
        ob.rearrange(start);
        printList(start);
    }
    return 0;
}

// } Driver Code Ends