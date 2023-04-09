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
void insertNode(ListNode* &res,int d){
     ListNode* temp= new ListNode(d);
     res->next= temp;
     res=temp;
}
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            //O(n) time-complexity and O(n) space complexity
        int sum=l1->val+ l2->val;
        int carry= sum/10;
        ListNode* res=new ListNode(sum%10);
        ListNode* ans= res;
        l1= l1->next;
        l2= l2->next;
        ListNode* ptr1=l1;
        ListNode* ptr2= l2;
        while(ptr1!= NULL && ptr2!= NULL){
            sum= carry+ ptr1->val+ ptr2->val;
            insertNode(res,sum%10);
            carry= sum/10;
             ptr1= ptr1->next;
            ptr2= ptr2->next;
        }
        //bacha hua part--
        while(ptr1!= NULL){
            sum= carry+ ptr1->val;
            carry=sum/10;
          insertNode(res,sum%10);
            ptr1= ptr1->next;

        }

        while(ptr2!= NULL){
            sum= carry+ ptr2->val;
            carry= sum/10;
           insertNode(res,sum%10);
            ptr2= ptr2->next;
        }
        if(carry!=0){
            insertNode(res,carry);
        }
        return ans;
    }
};