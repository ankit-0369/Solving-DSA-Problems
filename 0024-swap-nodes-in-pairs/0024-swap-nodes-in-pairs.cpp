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
    ListNode* swapPairs(ListNode* head) {
        //t.c:- O(n) & auxilary-space:- O(1)
        //naive approach-----
        // ListNode* temp= head;
        // while(temp!= NULL && temp->next!= NULL){
        //     swap(temp->val, temp->next->val);
        //     temp= temp->next->next;
        // }
        // return head;
        //swapping complete Nodes(Not only values)-----

        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* temp= new ListNode();
        temp->next= head;
        ListNode* prev= temp;
        ListNode* cur= head;
        while(cur && cur->next){
            prev->next= cur->next;
            cur->next= cur->next->next;
            prev->next->next= cur;
            prev= cur;
            cur= cur->next;

        }

        return temp->next;

    }
};