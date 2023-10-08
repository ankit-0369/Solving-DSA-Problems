
class info{
    public:
    int cnt;
    char ch;
    info(int no, char c){
        cnt= no;
        ch= c;
    }
};

class cmp{

    public:
 
    bool operator()(info* a, info* b){
        return a->cnt < b->cnt;
    }
};

class Solution {
public:
    string frequencySort(string s) {
//         int freL[26]= {0};
//           int freH[26]= {0};
//         for(auto ch: s){
//             if(ch>='a' && ch<='z')
//             freL[ch-'a']++;
//             else
//                 freH[ch-'A']++;
                
//         }
        map<char, int> mp;
        for(auto ch:s){
            mp[ch]++;
        }
        
        
        priority_queue<info*, vector<info*>, cmp> mxheap;
        
             for(auto it:mp){
                 info* temp= new info(it.second, it.first);
                 mxheap.push(temp);
             }
        s.clear();
        
        while(!mxheap.empty()){
            info* temp= mxheap.top();
            int cnt= temp->cnt;
            while(cnt--)
            s.push_back(temp->ch);
            mxheap.pop();
        }
        
        return s;
        
    }
};