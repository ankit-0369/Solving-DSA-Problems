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
public:
    ListNode* method1(ListNode* head, int x){
                if(!head || !head->next)
        return head;
        ListNode* l1= new ListNode(-1);
        ListNode* l2= new ListNode(-1);
        ListNode* list1= l1;
        ListNode* list2= l2;
        while(head!= NULL){
            if(head->val<x){
                ListNode* temp= new ListNode(head->val);
                    l1->next= temp;
                    l1= l1->next;

            }else{
                   ListNode* temp= new ListNode(head->val);
                    l2->next= head;
                    l2= l2->next;
                }
            
            head= head->next;
        }
       
        list1= list1->next;
        list2= list2->next;
         if(!list1){
            return list2;
        }
        if(!list2){
            return list1;
        }
        l1->next= list2;
        l2->next= NULL;
            return list1;
    }
    ListNode* partition(ListNode* head, int x) {
        // return method1();

        ListNode* list1= new ListNode(-1);
        ListNode* list2= new ListNode(-1);
        ListNode* l1= list1;
        ListNode* l2= list2;
        ListNode* temp= head;
        while(temp){
            if(temp->val<x){
                l1->next= temp;
                l1= l1->next;
            }else{
                l2->next= temp;
                l2= l2->next;
            }

            temp= temp->next;
        }

        l2->next= NULL;
        list1= list1->next;
        list2= list2->next;

        if(!list1 ){
            return list2;
        }

        if(!list2){
            return list1;
        }
        l1->next= list2;
      
        return list1;
    }
};