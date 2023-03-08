class Solution {
private:
    bool ispossible(vector<int> piles, int k, int h){

        
        double hrs= 0;
        int i=0;
        while(i<piles.size()){
            
            double y= k;
            double z= ceil(piles[i]/y);
          hrs+= z;
            i++;
        }
        cout<<"hrs:"<<hrs<<endl;
        if(hrs>h){
            return false;
        }
        return true;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int s=0;
        int e= 0;
        for(int i=0; i<piles.size(); i++){
            e= max(e,piles[i]);
        }
        int m= s+ (e-s)/2;
        int res=INT_MAX;
        while(s<=e){
            if(ispossible(piles,m,h)){
                res=min(m,res);
                cout<<"res: "<<res<<endl;
                e= m-1;
            }else
            s= m+1;
            m= s+ (e-s)/2;
        }

        return res;
    }
};