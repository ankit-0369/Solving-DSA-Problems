class Solution {
    private:
    vector<int> nextSmaller(vector<int> arr){
        vector<int> ans;
        stack<int> s;
        int n= arr.size();
        s.push(n);
        for(int i=n-1; i>=0; i--){
            int ele= arr[i];
            while( s.top()!= n && arr[s.top()]>= ele){
                s.pop();
            }
            ans.push_back(s.top());
            s.push(i);
        }
        reverse(ans.begin(), ans.end());
        
        return ans;
    }

    vector<int> prevSmaller(vector<int> arr){
        vector<int> ans;
        stack<int> s;
        s.push(-1);
        int i= 0;
        while(i<arr.size()){
            int ele= arr[i];
            while( s.top()!= -1 && arr[s.top()]>= ele ){
                s.pop();
            }

            ans.push_back(s.top());
            s.push(i);
            i++;
        }

        return ans;
    }
public:
    int largestRectangleArea(vector<int>& height) {
        vector<int> nextIndex= nextSmaller(height);
        vector<int> prevIndex= prevSmaller(height);
        int ans= 0;

        for(int i=0; i<height.size(); i++){
           int val= height[i]*(nextIndex[i]- prevIndex[i]- 1);
            ans= max(ans, val);
        }

        return ans;
    }
};