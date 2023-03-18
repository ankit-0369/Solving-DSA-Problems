class Solution {
public:
    int romanToInt(string s) {
        map<char, int> m= {{'I',1}, {'V',5}, {'X',10}, {'L',50},{'C',100}, {'D',500,}, {'M',1000}};
       
        int net=0;
        for(int i=s.size(); i>=0; i--){
            if((s[i]=='I'&&(s[i+1]=='V'||s[i+1]=='X'))&& i<s.size()){
                net-= m[s[i]];
            }else if((s[i]=='X'&&(s[i+1]=='L'||s[i+1]=='C'))&& i<s.size()){

                net-= m[s[i]];
            }else if((s[i]=='C'&&(s[i+1]=='D'||s[i+1]=='M'))&& i<s.size()){
                net-= m[s[i]];
            }else
                net+= m[s[i]];
                
        }
        return net;
        
    }
};