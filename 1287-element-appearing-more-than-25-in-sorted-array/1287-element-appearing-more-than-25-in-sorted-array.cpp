class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int cnt= arr.size()/4;
        int cur=1;
        for(int i=0; i+1<arr.size(); i++){
            if(arr[i]==arr[i+1]){
                cur++;
                if(cur>cnt) return arr[i];
            }else{
                cur=1;
            }
        }
        
        return arr.back();
    }
};