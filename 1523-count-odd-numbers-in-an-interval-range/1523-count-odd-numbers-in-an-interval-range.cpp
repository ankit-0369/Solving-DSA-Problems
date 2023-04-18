class Solution {
public:
    int countOdds(int low, int high) {
        
        //if low odd and high even
        if((low&1) && !(high&1)){
            return (high/2-low/2);
        
        }
                //if low and even both even
        else if(!(low&1) &&   !(high&1)){
            
            return  high/2 - low/2 ; 
        
        }
        //other cases
        

        return high/2 - low/2 +1;
    }
};