/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    private:
    // ListNode* naiveApproach(ListNode* head){
            
    //     map<ListNode*, bool> m_p;
    //     ListNode* temp= head;
    //     while(temp!= NULL){
    //         if(!m_p.count(temp)){
    //                 // m_p.insert({temp,true});
    //                 m_p[temp]= true;
    //         }else{
    //             return temp;
    //         }
    //         temp= temp->next;
    //     }
    //     return NULL;
    // }
    
    ListNode* floydAlgo(ListNode* head){
            ListNode* slow= head;
            ListNode* fast= head;
            while(fast!= NULL && fast->next!= NULL){
                fast= fast->next->next;
                slow= slow->next;

                if(fast==slow)
                return slow;
            }
            return NULL;
    }

    ListNode* optimized(ListNode* head){
  
            if(head==NULL)
            return NULL;

            ListNode* floydPoint= floydAlgo(head);
            if(!floydPoint)
            return NULL;

            ListNode* slow= head;
            while(slow!= floydPoint){
                floydPoint= floydPoint->next;
                slow= slow->next;
            }
            return slow;
    }
    
public:
    ListNode *detectCycle(ListNode *head) {//t.c:- O(n) & auxilary-space:- O(n)
        //naive approach----using map---
            // t.c:- O(nLogn) & auxilary-space:- O(n)
        // return naiveApproach(head);

        //using Floyd Algo of Loop detection---
        // t.c:- O(n) & auxilary-space:- O(1)
        return optimized(head);
    }
};