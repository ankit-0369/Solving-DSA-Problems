class info{
    public:
    char data;
    int cnt;
    info(char d, int c){
        this->data= d;
        this->cnt= c;
        
    }
};

class cmp{
    public:
    
    bool operator()(info* a, info* b){
        return a->cnt< b->cnt;
    }
    
};

class Solution {
    
public:
    string reorganizeString(string s) {
        int fre[26]= {0};
        for(auto ch:s){
            fre[ch-'a']++;
        }
        
        priority_queue<info*, vector<info*>, cmp> mxHeap;
        for(int i=0; i<26; i++){
            
            if(fre[i]!=0){

                info* t= new info(i+'a', fre[i]);
                   mxHeap.push(t);
            }
             
             
        }
        string ans= "";
        
        while(mxHeap.size()>1){
            info* ele1= mxHeap.top();
            mxHeap.pop();
            info* ele2= mxHeap.top();
            mxHeap.pop();
            ans+= ele1->data;
            ans+= ele2->data;
            // cout<<ele1->data<<" "<<ele2->data<<"\n";
            ele1->cnt--;
            ele2->cnt--;
            if(ele1->cnt>0)
            mxHeap.push(ele1);
            if(ele2->cnt>0)
                mxHeap.push(ele2);
        }
        
        if(mxHeap.size()==1){
            if(mxHeap.top()->cnt>1){

                ans= "";
                return ans;
            }else{
                ans+= mxHeap.top()->data;
            }
        }
        
        return ans;
        
    }
};










