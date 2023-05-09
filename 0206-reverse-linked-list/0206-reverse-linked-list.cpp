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
    ListNode* iterativeWay(ListNode* head){
        ListNode* prev= NULL;
        ListNode* cur=head;
        while(cur!=NULL){
            ListNode* forward= cur->next;
            cur->next= prev;
            prev= cur;
            cur= forward;
        }
        return prev;
    }
public:
    ListNode* reverseList(ListNode* head) {
        return iterativeWay(head);

        // return recursiveWay(head);
    }
};