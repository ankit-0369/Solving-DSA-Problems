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
public:
    char nextGreatestLetter(vector<char>& letters, char target){
        //using recursion--- time-complexity:- O(logn) & auxilary-space:- O(1)
       char res='{'; 
      cout<<res+1<<endl;
      solve(letters,target,0,letters.size()-1, res);
      if(res=='{')
      return letters[0];
      return res;
    }
};