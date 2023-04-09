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
    ListNode* deleteDuplicates(ListNode* head) {//t.c:-O(n) & auxilary-space:-O(1)
        if(head==NULL){
            return head;
        }
        ListNode* ptr1=head;
        ListNode* ptr2= head;
        ListNode* prev= NULL;
        while(ptr1!= NULL){
            while(ptr2!=NULL && ptr1->val==ptr2->val){
                prev= ptr2;
                ptr2= ptr2->next;
            }
            ptr1->next= prev->next;
            ptr1=ptr2;
           }
        return head;
    }
};