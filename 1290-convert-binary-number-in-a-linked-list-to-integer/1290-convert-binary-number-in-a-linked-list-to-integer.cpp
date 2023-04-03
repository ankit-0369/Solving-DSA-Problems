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
        while(head->next!=NULL){
            cnt++;
            head= head->next;
        }
     return cnt;
    }
public:
    int getDecimalValue(ListNode* head) {

        ListNode* temp= head;
        int res=0;
        int k=getLength(head)-1;
        while(temp->next!= NULL){
                int d= temp->val;
                res+= d*pow(2,k--);
                
                temp= temp->next;
        }
        res+= (temp->val)* pow(2,k--);
        return res;
    }
};