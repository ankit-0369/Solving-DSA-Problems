class Solution {
public:
    int maxArea(vector<int>& height) {
        int n= height.size();
        int max= INT_MIN;
        // for(int i=0; i+1<n; i++){ O(n^2)

        //         for(int j=i+1; j<n; j++){
        //             int h= (height[i]>height[j]) ? height[j] : height[i];
        //             int a= h* (j-i);
        //             max= (a> max) ? a : max;
        //         }
        // }
        int i=0, j= n-1;
        while(i<=j){ // O(n/2)
              
              if(height[i]<height[j]){
               int  h= height[i];
                int a= h* (j-i);
            max= (a>max) ? a : max;
                    i++;
              }else{
                  int h= height[j];
                  int a= h* (j-i);
                 max= (a>max) ? a : max;
                 j--;
                }
             
            
              
        }

        return max;
    }
};