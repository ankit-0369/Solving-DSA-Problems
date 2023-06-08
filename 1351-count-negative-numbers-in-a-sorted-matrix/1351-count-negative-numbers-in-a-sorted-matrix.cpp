class Solution {
    private:
    int searchNeg(vector<int> arr, int n){
            int s=0, e=n-1;
            int m= s+(e-s)/2;
            int index=-1;
            while(s<=e){
                if(arr[m]<0){
                    index=m;
                    e=m-1;
                }else{
                    s= m+1;
                }
                m= s+(e-s)/2;
            }
            return index;
    }
    
    int method1(vector<vector<int>>& grid){

        int m=grid.size();
        int n= grid[0].size();
        int ans=0;
        for(int row=0; row<m; row++){
            int index= searchNeg(grid[row],n);
            // cout<<index<<"\n";
            if(index!=-1)
            ans+= (n-index);

        }
        return ans;
    }
    
    int method2(vector<vector<int>>& grid){
        int cnt=0;
        int n= grid[0].size();
        int negIndex=n-1;
        
        for(auto& row : grid){
            
            while(negIndex>=0 && row[negIndex]<0){
                negIndex--;
            }
            // cout<<(n-negIndex-1)<<" "<<negIndex<<endl;
            cnt+= (n-negIndex-1);
        }
        
        return cnt;
    }
    
public:
    int countNegatives(vector<vector<int>>& grid) {
        
        // return method1(grid);
        
        return method2(grid);
    }
};