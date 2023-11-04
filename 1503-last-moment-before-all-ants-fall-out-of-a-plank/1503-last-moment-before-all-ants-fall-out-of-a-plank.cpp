class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int time=0;
        for(auto ind: right){
            time= max(time, n-ind);
        }
        for(auto ind: left){
            time= max(time, ind);
        }

        return time;
    }
};