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
        int cnt= 0;

        while(head!= NULL){
            head= head->next;
            cnt++;
        }
        return cnt;
    }

void reverseList(ListNode* & head){
        ListNode* prev= NULL;
        ListNode* cur= head;
        while(cur!= NULL){
            ListNode* agla= cur->next;
            cur->next= prev;
            prev= cur;
            cur= agla;
        }
        head= prev;
}
public:

    int pairSum(ListNode* head) {
        //naive approach----
        ListNode* left= head;
        ListNode*right= head;
        int cnt=0;
        int n= getLength(head);
        while(cnt<n/2){
            right= right->next;
            cnt++;
        }
        reverseList(right);
        int maxSum= 0;
        while(right!= NULL){
            int twinSum= left->val + right->val;

            maxSum= max(maxSum, twinSum);
            left= left->next;
            right= right->next;
        }

        return maxSum;
       
    }
};