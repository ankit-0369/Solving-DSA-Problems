class Solution {
    private:
    void solve(vector<char>& letters, char target, int s,int e, char& res){
        
        if(s>e)
        return;

        int m= s+ (e-s)/2;
    

            if(letters[m]>target){
                if(letters[m]<res) res= letters[m];
                    e=m-1;
                     solve(letters,target,s,e,res);
                    
            }else{
                s= m+1;
                solve(letters,target,s,e,res);
            }

        return;
    }

    char recursiveWay(vector<char>& letters, char target){
        char res='{'; 
      
      solve(letters,target,0,letters.size()-1, res);
      if(res=='{')
      return letters[0];
      return res;
    }

    char iterativeWay(vector<char>& letters, char tar){
        char res= '{';
        int s=0, e= letters.size()-1;
        int m= s+(e-s)/2;

        while(s<=e){
             if(letters[m]>tar){
                res= min(res, letters[m]);
                e= m-1;
            }else{
                s= m+1;
            }

            m= s+ (e-s)/2;
        }
            if(res=='{')
            return letters[0];
        return res;
    }

public:
    char nextGreatestLetter(vector<char>& letters, char target){
        //using recursion--- time-complexity:- O(logn) & auxilary-space:- O(logn)
    //    return recursiveWay(letters, target);

       return iterativeWay(letters, target);
    }
};