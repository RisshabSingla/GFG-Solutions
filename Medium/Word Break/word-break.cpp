//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:

    int findNum(string &str, string &word, int index){
        for(int i = 0; i<word.length(); i++){
            if(index+i == str.length()){
                return 0;
            }
            if(str[index+i] != word[i]){
                return 0;
            }
        }
        return word.length();
    }
    
    int wordBreak(string str, vector<string> &arr) {
        //code here
        int slen = str.length();
        int wlen = arr.size();
        vector<bool> dp(slen+1, false);
        dp[slen] = true;
        for(int i = slen-1; i>=0; i--){
            for(int j = 0; j<wlen; j++){
                
                if(str[i] != arr[j][0]){
                    continue;
                }
                
                int numMatched = findNum(str, arr[j],i);
                if(numMatched!= 0){
                    dp[i] = dp[i] || dp[i+numMatched];
                }
            }
        }
        
        return dp[0];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends