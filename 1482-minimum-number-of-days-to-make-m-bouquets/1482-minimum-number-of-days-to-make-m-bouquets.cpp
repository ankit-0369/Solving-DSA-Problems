class Solution {
    private:
    bool isPossible(vector<int>& day, int times, int bloom, int mid){
        int ct=0;
         for(int i=0; i<day.size(); i++){
                if(day[i]<=mid){
                   ct++;
                if(ct>=bloom){
                times--;
                if(times==0){
                    return true;
                }
                ct=0;
                 }
            }else{
                ct=0;
            }

        }
        
     return false;
    }
public:
    int minDays(vector<int>& day, int m, int k) {// t.c:- O(nlogn)  & auxilary-space:- O(1)
        int left=0;
        int right= *max_element(day.begin(),day.end());
        int mid= left+(right-left)/2;
        int res=-1;
        while(left<=right){
                if(isPossible(day,m,k,mid)){
                    res=mid;
                   right=mid-1;
                }else{
                    left=mid+1;
                }
               mid= left+(right-left)/2;
        }

        return res;
    }
};