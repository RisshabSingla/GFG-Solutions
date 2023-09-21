//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	    void helper(string str, vector<string> &ans, int index, int slen){
	        if(index == slen){
	            ans.push_back(str);
	            return;
	        }
	        unordered_set<char> done;
	        for(int i = index; i<slen; i++){
	            if(done.count(str[i])){
	                continue;
	            }
	            done.insert(str[i]);
	            swap(str[index], str[i]);
	           // cout<<str<<endl;
	            helper(str, ans, index+1, slen);
	            swap(str[index], str[i]);
	        }
	    }
		vector<string>find_permutation(string str)
		{
		    // Code here there
		    vector<string> ans;
		    int slen = str.length();
		    helper(str, ans, 0, slen);
		    return ans;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends