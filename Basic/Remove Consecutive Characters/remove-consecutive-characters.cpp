//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
class Solution{
    public:
    string removeConsecutiveCharacter(string str)
    {
        // code here.
        string ans = "";
        ans += str[0];
        int index = 0;
        for(int i = 1; i<str.length(); i++){
            if(str[i]!= ans[index]){
                ans+= str[i];
                index++;
            }
        }
        return ans;
        
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.removeConsecutiveCharacter(s)<<endl;
    }
} 




// } Driver Code Ends