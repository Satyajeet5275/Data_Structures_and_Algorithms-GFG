//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& list) {
        // code here
        unordered_set<string> st(list.begin(),list.end());
        queue<vector<string>> q;
        q.push({beginWord});
        vector<vector<string>> ans;
        int level=0;
        vector<string> used{beginWord};

        while(!q.empty()){
            vector<string> seq=q.front();
            q.pop();
            string word=seq.back();
            if(level<seq.size()){
                level++;
                for(auto x:used){
                    st.erase(x);
                }
            }

            if(word==endWord){
                if(ans.size()==0) ans.push_back(seq);
                else if(seq.size()==ans[0].size()) ans.push_back(seq);
            }
        
            for(int i=0;i<word.size();i++){
                char org=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.find(word)!=st.end()){
                        seq.push_back(word);
                        q.push(seq);
                        used.push_back(word);
                        seq.pop_back();
                    }
                }
                word[i]=org;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

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
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends