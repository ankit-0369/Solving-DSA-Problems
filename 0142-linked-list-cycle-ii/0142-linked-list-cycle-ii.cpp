/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {//t.c:- O(n) & auxilary-space:- O(n)
        //naive approach----using map---
        map<ListNode*, bool> m_p;
        ListNode* temp= head;
        while(temp!= NULL){
            if(!m_p.count(temp)){
                    m_p.insert({temp,true});
            }else{
                return temp;
            }
            temp= temp->next;
        }
        return NULL;
    }
};