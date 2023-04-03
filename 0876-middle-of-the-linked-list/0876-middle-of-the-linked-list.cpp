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
        int cnt=1;
        while(head->next!= NULL){
            cnt++;
            head= head->next;
        }
        return cnt;
    }
public:
    ListNode* middleNode(ListNode* head) {
        //brute force approach will be -find length of linked List and traverse to the middle of linked list in O(n/2) time complexity.
        int len= getLength(head);
        int i=0;
        while(i<len/2){
            head=head->next;
            i++;
        }
        return head;
    }
};