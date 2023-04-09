class Solution {
public:
    string addStrings(string nums1, string nums2) {//t.c:- O(n) & auxilay-space:- O(n)
        int i=nums1.size()-1;
        int j= nums2.size()-1;
        int sum=0, carry=0;
       
        string s;
        while(i>=0 || j>=0|| carry>0){
            int x=0;
            int y=0;
            if(i>=0)
            x= int(nums1[i]) ? int(nums1[i]-48)  : 0;
            if(j>=0)
             y= int(nums2[j]) ? int(nums2[j]-48) : 0;
                sum= x + y + carry;
                char d= char(sum%10+48);
             s.push_back(d);
                carry= sum/10;
                i--,j--;
        }
        i=0, j=s.size()-1;
        while(i<=j){//same can be done with-- reverse(s.begin(),s.end());--
            swap(s[i++],s[j--]);
        }
    return s;
    }
};