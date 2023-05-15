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
        int cnt=0;
        while(head!= NULL){
            cnt++;
            head= head->next;
        }
        return cnt;
    }
public:
    ListNode* swapNodes(ListNode* head, int k) {
        //naive approach---
            //t.c:- O(n) & auxilary-space:- O(1)
        int n= getLength(head);
        int i=0;
        ListNode* ptr1=head;
        ListNode* ptr2=head;
        ListNode* temp= head;
        while(i<n){
                if(i==k-1){
                    ptr1= temp;
                }
                if(i==n-k){
                    ptr2= temp;
                }
                temp= temp->next;
                i++;
        }
        swap(ptr1->val, ptr2->val);
        return head;

    }
};