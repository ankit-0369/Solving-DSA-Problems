/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
    private:
    void insertAtTail(Node* & head, Node* & tail, int x){
         Node* temp= new Node(x);
        if(head==NULL){
            head= temp;
            tail= temp;
            return;
        }
        tail->next= temp;
        tail= temp;
        
    }
    
    Node* method1(Node* head){
                //create new List.
        Node* cloneHead= NULL;
        Node* cloneTail= NULL;
        Node* clone= cloneHead;
        Node* temp= head;

        while(temp!= NULL){
            insertAtTail(cloneHead, cloneTail, temp->val);
            temp= temp->next;
        }

        //insert clone nodes in between real nodes
        clone= cloneHead;
        Node* originalNode= head;
        while(originalNode!= NULL && clone!= NULL){
            Node* agla= originalNode->next;
            originalNode->next= clone;
            originalNode= agla;

            agla= clone->next;
            clone->next= originalNode;
            clone= agla;
        }

        //arrange random pointers-----
        originalNode= head;
        while(originalNode!= NULL){

            if(originalNode->next!= NULL)
            originalNode->next->random= originalNode->random ? originalNode->random->next :  NULL ;

            originalNode= originalNode->next->next;

        }

        //rearranging next pntrs-----

        originalNode= head;
        clone= cloneHead;

        while(originalNode!= NULL && clone!= NULL){

            originalNode->next= clone->next;
            originalNode= originalNode->next;

            if(originalNode)
            clone->next= originalNode->next;
            clone= clone->next;
        }

        return cloneHead;
    }
    
    Node* method2(Node* head){

        Node* cloneHead= NULL;
        Node* clone= cloneHead;
        Node* cloneTail= NULL;
        Node* ptr1= head;
        while(ptr1!= NULL){
            insertAtTail(cloneHead, cloneTail, ptr1->val);
            ptr1= ptr1->next;
            
        }
        ptr1= head;
        Node* ptr2= cloneHead;
        
        //mapping created---
        
        map<Node*, Node*> m;
        while(ptr1!= NULL){
            
            m[ptr1]= ptr2;
            ptr1= ptr1->next;
            ptr2= ptr2->next;
            
        }
        
        ptr2= cloneHead;
        ptr1= head;
        //cloning rnd ptrs----
        while(ptr2!= NULL){
            ptr2->random= m[ptr1->random];
            ptr2= ptr2->next;
            ptr1= ptr1->next;
            
        }
        
        return cloneHead;
    }
    
public:
    Node* copyRandomList(Node* head) {
        
        return method1(head);
        // return method2(head);
    }
};