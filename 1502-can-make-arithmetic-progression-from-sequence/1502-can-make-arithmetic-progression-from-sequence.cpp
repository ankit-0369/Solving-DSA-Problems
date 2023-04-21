class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n= arr.size();
        int d= arr[1]-arr[0];
        for(int i=1; i+1<n; i++){
            if(arr[i+1]-arr[i]!=d)
                return false;
        }
        if(arr[n-1]-arr[n-2]!=d)
            return false;
        return true;
    }
};