class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      int n= nums.size();
        map<int,int> m;
        for(int i=0; i<n; i++){
            m[nums[i]]++;
        }
        
    //    for(auto it : m){
    //        cout<< it.first<<" "<<it.second<<endl;
    //    }
    //    cout<<endl;
    multimap<int,int> mp;
    for(auto it : m){
        mp.insert({it.second, it.first});
    }
    vector<int> v;
    int ct=0;
    
    auto it =mp.end();
    it--;

    while(it!= mp.begin() && ct<k){
        // cout<<it->first<<" "<<it->second<<endl;
        v.push_back(it->second);
        it--, ct++;
        
    }
    if(ct<k){
         v.push_back(it->second);
    }
    // cout<<it->first<<" "<<it->second<<endl;

        return v;
        
    }
};