class Solution {
    private:
    int process(int spellValue, vector<int>& p, long long success){
            int s=0, e= p.size()-1;
            int m= s+ (e-s)/2;
            int index= p.size();
            while(s<=e){
                long long prod= (long long)spellValue* (long long)p[m];
                if(prod>=success){
                    index=m;
                    e= m-1;
                }else
                s= m+1;
                m= s+ (e-s)/2;
            }
            return index;
    }
public:
    vector<int> successfulPairs(vector<int>& spell, vector<int>& p, long long success) {
         vector<int > res;
        sort(p.begin(),p.end());
        int n= p.size();
        for(int i=0; i<spell.size(); i++){// O(nlogn) time-complexity & O(1) auxilary-space
           int index= process(spell[i],p,success);
            res.push_back(n-index);
        }
         return res;
    }
};