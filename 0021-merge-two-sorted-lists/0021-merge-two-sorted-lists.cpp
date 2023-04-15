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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
            if(list1==NULL){
                return list2;
            }
            if(list2==NULL ){
                return list1;
            }
            if(list1!= NULL && list2== NULL){
                return list1;
            }
        ListNode* p1= list1;
        ListNode* p2= list2;
        ListNode* p3= new ListNode(p1->val);
        
        if(p1->val< p2->val){
            p3->next= p1;
            p1= p1->next;
         
        }else{
            p3->next= p2;
            p2= p2->next;

        }
     p3= p3->next;
     ListNode* ans= p3;

        while(p1!= NULL && p2!= NULL){
             if(p1->val< p2->val){
            p3->next= p1;
            p1= p1->next;
      
             }else{
               p3->next= p2;
               p2= p2->next;
              
            }
            p3= p3->next;
        }

        while(p1!= NULL){
             p3->next= p1;
            p1= p1->next;
            p3= p3->next;
        }
        while(p2!= NULL){
             p3->next= p2;
               p2= p2->next;
                p3= p3->next;
        }
        return ans;
    }
};