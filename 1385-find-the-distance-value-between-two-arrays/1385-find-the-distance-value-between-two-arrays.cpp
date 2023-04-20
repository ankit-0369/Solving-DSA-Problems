class Solution {
    private:
    int closestDistance(vector<int>& arr2, int cur, int d){
        int s=0, e= arr2.size()-1;
        int m= s+(e-s)/2;
        // int d= INT_MAX;
        while(s<=e){
            if(abs(cur-arr2[m])<=d){
                return false;
                
            }else if(arr2[m]<cur){
                s= m+1;
            }else
              e= m-1;
          
            m= s+(e-s)/2;
        }
    // cout<<"fn: "<<d<<endl;
        return true;
    }
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
         sort(arr2.begin(),arr2.end());
        int res=0;
        cout<<arr1.size()<<"\n";
        for(int i=0; i<arr1.size(); i++){
                if(closestDistance(arr2,arr1[i],d)){
                    res++;
                }
        }
        return res;
    }
};