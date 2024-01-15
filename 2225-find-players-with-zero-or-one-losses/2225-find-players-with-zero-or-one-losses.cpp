class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, vector<int>> player_data;
        for(auto v: matches){
            int wPlayer= v[0];
            int lPlayer= v[1];
            if(player_data.find(wPlayer)== player_data.end()){
                player_data[wPlayer]= vector<int>(2,0);
            }
            if(player_data.find(lPlayer)== player_data.end()){
                player_data[lPlayer]= vector<int>(2,0);
            }
            player_data[wPlayer][0]++;
            player_data[lPlayer][1]++;
            
        }
        vector<vector<int>> ans;
        vector<int> w,l;
        for(auto [player, data] : player_data){
           int lData= data[1];
            if(lData==0){
                w.push_back(player);
            }
            if(lData==1){
                l.push_back(player);
            }
        }
        
        sort(w.begin(), w.end());
        sort(l.begin(), l.end());
        
        ans.push_back(w);
        ans.push_back(l);
        return ans;
    }
};