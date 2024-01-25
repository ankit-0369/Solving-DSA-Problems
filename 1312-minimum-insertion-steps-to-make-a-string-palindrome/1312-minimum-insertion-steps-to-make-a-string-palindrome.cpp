class Solution {
public:
int LPS(string s){
    string rev= s;
    reverse(s.begin(), s.end());
    int m= s.size();
    vector<int> prev(m+1, 0), cur(m+1, 0);

    for(int i=1; i<=m; i++){

        for(int j=1; j<=m; j++){

          if(s[i-1]== rev[j-1]){
                cur[j]= 1+ prev[j-1];
          }else
          cur[j]= max(cur[j-1], prev[j]);

        }

        prev= cur;
    }

    return prev[m];

}
    int minInsertions(string s) {
        return s.size()- LPS(s);
    }
};