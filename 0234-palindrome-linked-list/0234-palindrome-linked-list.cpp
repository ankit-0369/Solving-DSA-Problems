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
    bool checkPalindrome(vector<int> a, int j){
            int i=0;
            while(i<=j){
                if(a[i]!= a[j]){
                    return false;
                }
                i++,j--;
            }
            return true;
    }
public:
    bool isPalindrome(ListNode* head) {
        //brute force will be- use an array and copy all value of linked list in it then check for palindrome ---t.c:- O(n) & auxilary-space:- O(n)
     vector<int> arr;
     while(head!= NULL){
         arr.push_back(head->val);
         head= head->next;
     } 
     return checkPalindrome(arr,arr.size()-1);  
    }
};