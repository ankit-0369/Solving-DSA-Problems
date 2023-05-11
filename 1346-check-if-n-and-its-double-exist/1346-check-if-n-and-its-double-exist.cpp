class Solution {
    private:
    bool binarySearch(vector<int> arr, int n, int tar, int i){
        int s=0, e= n-1;
        int m= s+(e-s)/2;
        while(s<=e){
                if(arr[m]==2*tar && i!=m){
                    cout<<arr[m]<<endl;
                    return true;
                }else if(arr[m]<2*tar){
                    s= m+1;
                }else
                e= m-1;

               m= s+(e-s)/2;
        }
        return false;
    }
public:
    bool checkIfExist(vector<int>& arr) {
        //naive appproach---
        int i=0;
        int n= arr.size();
        sort(arr.begin(), arr.end());
        for(i=0; i<n; i++){
            if(binarySearch(arr,n, arr[i],i)){
                return true;
            }
        }
        return false;
    }
};