//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string beginWord, string endWord, vector<string>& list) {
        // Code here
        unordered_set<string> st(list.begin(),list.end());
        queue<pair<string,int>> q;
        q.push({beginWord,1});

        while(!q.empty()){
            string word=q.front().first;
            int step=q.front().second;
            q.pop();

            if(word==endWord) return step;

            for(int i=0;i<word.size();i++){
                char org=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.find(word)!=st.end()){
                        q.push({word,step+1});
                        st.erase(word);
                    }
                }
                word[i]=org;
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