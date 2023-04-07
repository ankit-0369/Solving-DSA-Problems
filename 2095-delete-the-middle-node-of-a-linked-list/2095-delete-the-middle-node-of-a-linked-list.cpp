/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    private:
    int getLength(ListNode* head){
        int ct=0;
        while(head!=NULL){
            ct++;
            head= head->next;
        }
        return ct;
    }
public:
    ListNode* deleteMiddle(ListNode* head) {
        //if single Node is there---
        if(head->next==NULL){
            head= NULL;
            return head;
        }
        //If more than 1 node is present---
        int len= getLength(head);//O(n)
        int pos=0;
        ListNode* cur=head;
        ListNode* prev= head;
        while(pos<len/2){
            prev= cur;
            cur= cur->next;
            pos++;
        }
        prev->next= cur->next;
       return head;

    // if(head->next==NULL){
    //     head= NULL;
    //     return head;
    // }               //O(n/2) and O(1) time complexity and auxilary-space-----
    // ListNode* fast=head;
    // ListNode* slow= head;
    // ListNode* prev=NULL;
    // while(fast!= NULL && fast->next!= NULL){
    //     prev=slow;
    //     slow= slow->next;
    //     fast= fast->next->next;
    // }
      
    //     prev->next= slow->next;
    //     return head;  
    }
    
};