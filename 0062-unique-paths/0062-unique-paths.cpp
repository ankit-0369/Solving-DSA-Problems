class Solution {
public:
    // void solve(int m, int n, vector<vector<int>> &vis, int & ans, int x, int y){

    //         if(x==m-1 && y==n-1){
    //             ans++;
    //             return;
    //         }
    //         if(x+1<m && y<n && vis[x+1][y]!=1){
    //             vis[x+1][y]= 1;
    //             solve(m,n,vis,ans,x+1,y);
    //             vis[x+1][y]=0;

    //         }
    //         if(x<m && y+1<n && vis[x][y+1]!= 1){
    //             vis[x][y+1]=1;
    //              solve(m,n,vis,ans,x,y+1);
    //              vis[x][y+1]=0;
    //         }

    //         return;
    // }
    // int recursiveWay(int m, int n){
    //     vector<vector<int>> vis;
    //     for(int i=0; i<m; i++){
    //         vector<int> t;
    //         for(int j=0; j<n; j++){
    //             t.push_back(0);
    //         }
    //         vis.push_back(t);
    //     }

    //    int ans=0;
    //    int x= 0, y=0;
    //    vis[0][0]=1;
    //    solve(m,n,vis,ans, x,y);

    //    return ans;
    // }
    int totalPaths(int x, int y, int m, int n, vector<vector<int>> & memo){

            if(x== m-1 && y==n-1){
                return 1;
            }

            if(memo[x][y]!= -1){
                return memo[x][y];
            }
            int right=0, down=0;
            if(x<m-1){
                 right= totalPaths(x+1, y, m,n, memo);

            }
            if(y<n-1){
                down= totalPaths(x, y+1, m,n, memo);

            }

            memo[x][y]= right+ down;
            return memo[x][y];

    }
    int uniquePaths(int m, int n) {
        // return recursiveWay(m,n);
        // vector<vector<int>> memo(m, vector<int>(n,-1));

    //     return totalPaths(0,0, m,n, memo);
        vector<int> prev(n,0);
        for(int i=0; i<m; i++){
            vector<int> temp(n, 0);
            for(int j=0 ; j<n; j++){
                if(i==0 || j==0) temp[j]=1;
                else{

                    temp[j]= prev[j] + temp[j-1];
                }

            }
            prev= temp;
        }
        return prev[n-1];
    }
};