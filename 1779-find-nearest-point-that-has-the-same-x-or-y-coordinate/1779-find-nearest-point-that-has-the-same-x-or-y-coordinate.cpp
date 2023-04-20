class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& p) {//t.c:- O(n) & auxilary-space:-o(1)
        int index= p.size();
        int m_d= INT_MAX;;
        for(int i=0; i<p.size(); i++){
            if(p[i][0]==x || p[i][1]==y){
                int d= abs(x-p[i][0]) + abs(y-p[i][1]);
                if(d<m_d){
                    index= i;
                    m_d= d;
                }else if(d==m_d){
                    // cout<<d<<" "<<i<<"\n";
                        index= min(index,i);
                }
            }
        }
        if(index==p.size())
        return -1;
        return index;
    }
};