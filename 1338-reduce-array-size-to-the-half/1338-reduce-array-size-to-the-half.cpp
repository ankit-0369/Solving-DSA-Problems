
class cmp{
    public:
    bool operator()(pair<int, int> a, pair<int, int> b){
        return a.second < b.second;
    }
};

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        //navie approach---
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> mxheap;
        
        //first->value , second->cnt
        map<int, int> mp;
        for(auto n: arr){
            mp[n]++;
        }
        
        for(auto p: mp){
            mxheap.push(p);
        }
        
        int cur= 0;
        int ans=0;
        int req= arr.size()/2;
        while(cur< req){
            pair<int, int> p= mxheap.top();
            mxheap.pop();
            cur+= p.second;
            ans++;
        }
        return ans;
        
    }
};