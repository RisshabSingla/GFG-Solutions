//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends


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
int countRev (string s)
{
    // your code here
    
    stack<char> stk;
    for(int i = 0; i<s.length(); i++){
        if(isOpening(s[i])){
            stk.push(s[i]);
            }else{
                if(stk.empty()){
                    stk.push(s[i]);
                    continue;
                }
                char ch = stk.top();
                if(ch == '{' && s[i] == '}'){
                    stk.pop();
                }else if(ch == '[' && s[i] == ']'){
                    stk.pop();
                }else if(ch == '(' && s[i] == ')'){
                    stk.pop();
                }else{
                    stk.push(s[i]);
                }
            }
        }
        
        int size = stk.size();
        // cout<<"Size is: "<<size<<endl;
        if(size % 2 == 1){
            return -1;
        }
        
        int count = 0;
        while(!stk.empty()){
            int top = stk.top();
            stk.pop();
            int sec = stk.top();
            stk.pop();
            
            if(top == sec){
                count++;
            }else{
                count+=2;
            }
            
        }
        return count;
        
        // return false;
    
    
    
}