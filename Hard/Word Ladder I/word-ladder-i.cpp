//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        // Code here----
        
        queue<pair<string, int>> q;
        q.push({startWord, 1});
        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(startWord);
        
        while(!q.empty()){
            string word= q.front().first;
            int step= q.front().second;
            q.pop();
            
            if(word == targetWord) return step;
            
            //for each character of word we need to try---
            for(int i=0; i<word.size(); i++){
                char ch= word[i];
                for(char c= 'a'; c<='z'; c++){
                    word[i]= c;
                    if(st.find(word)!= st.end()){
                        //means word exist-
                        st.erase(word);
                        q.push({word, step+1});
                    }
                }
                
                word[i]= ch;
            }
        }
        
        return 0;
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends