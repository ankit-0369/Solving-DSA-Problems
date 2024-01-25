class Solution {
public:
    int LCSub(string s1, string s2){
        int m= s1.size();
        int n= s2.size();
        int mx= max(m,n);
        
        vector<int> prev(mx+1,0), cur(mx+1,0);
        int mxLen= 0;
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(s1[i-1]== s2[j-1]){
                    cur[j]= 1+ prev[j-1];
                    mxLen= max(mxLen, cur[j]);
                }else
                cur[j]= max(prev[j], cur[j-1]);
            }
            
            prev= cur;
        }
        
        return prev[n];
    }
    
    int minDistance(string word1, string word2) {
        cout<<LCSub(word1, word2);
        return (word1.size() + word2.size() - 2*LCSub(word1, word2));
    }
};