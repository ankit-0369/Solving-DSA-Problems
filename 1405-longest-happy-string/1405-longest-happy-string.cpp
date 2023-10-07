
class cmp{
    public:
    bool operator()(pair<int, char> p1, pair<int,char> p2){
        return p1.first<p2.first;
    }
};

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string ans;
        priority_queue<pair<int,char>, vector<pair<int,char>>, cmp> mxHeap;
        
       if(a!=0) mxHeap.push({a,'a'});
       if(b!=0)   mxHeap.push({b,'b'});
        if(c!=0)  mxHeap.push({c,'c'});
       
        while(mxHeap.size()>1){
            pair<int, char> t1= mxHeap.top();
            mxHeap.pop();
            pair<int, char> t2= mxHeap.top();
            mxHeap.pop();
            
            // if(t1.first>0)
            //     ans.push_back(t1.second);
            //     t1.first--;
            // if(t1.first>0)
            //     ans.push_back(t1.second);
            // t1.first--;
            if(t1.first>1){
                ans.push_back(t1.second);
                ans.push_back(t1.second);
                t1.first-=2;
            }else{
                ans.push_back(t1.second);
                t1.first-=1;
            }
            
            if(t2.first>1 && t2.first>=t1.first){
                ans.push_back(t2.second);
                ans.push_back(t2.second);
                t2.first-=2;
            }else{
                ans.push_back(t2.second);
                t2.first-=1;
            }
            
            
            
//             if(t2.first>0)
//                 ans.push_back(t2.second);
//                 t2.first--;
//             if(t2.first>0)
//                 ans.push_back(t2.second);
//             t2.first--;
            
            if(t1.first>0)
                mxHeap.push(t1);
            if(t2.first>0)
                mxHeap.push(t2);  
            
        }
        
        if(mxHeap.size()==1){
            pair<int, char> p= mxHeap.top();
            mxHeap.pop();
            if(p.first>0)
                ans.push_back(p.second);
            p.first--;
            if(p.first>0)
                ans.push_back(p.second);
            
        }
        
        return ans;
        
        
    }
};