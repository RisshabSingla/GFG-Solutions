//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    bool isOpening(char &ch){
        if(ch == '('){
            return true;
        }
        if(ch == '['){
            return true;
        }
        
        if(ch == '{'){
            return true;
        }
        return false;
    }
    
    
    //Function to check if brackets are balanced or not.
    bool ispar(string s)
    {
        // Your code here
        stack<char> stk;
        for(int i = 0; i<s.length(); i++){
            if(isOpening(s[i])){
                stk.push(s[i]);
            }else{
                if(stk.empty()){
                    return false;
                }
                char ch = stk.top();
                if(ch == '{' && s[i] == '}'){
                    stk.pop();
                }else if(ch == '[' && s[i] == ']'){
                    stk.pop();
                }else if(ch == '(' && s[i] == ')'){
                    stk.pop();
                }else{
                    return false;
                }
            }
        }
        if(stk.empty()){
            return true;
            
        }
        return false;
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends