//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    string printMinNumberForPattern(string str){
        // code here 
        stack<int> nums;
        string ans = "";
        int number = 1;
        for(int i = 0; i<str.length(); i++){
            // cout<<"Char is: "<<str[i]<<"\n"; 
            if(str[i] == 'D'){
                nums.push(number);
                number++;
            }else{
                nums.push(number);
                number++;
                while(!nums.empty()){
                    ans = ans + to_string(nums.top());
                    // cout<<"Nums top: "<<nums.top()<<"\n";
                    nums.pop();
                }
            }
        }
        nums.push(number);
        while(!nums.empty()){
            ans = ans + to_string(nums.top());
            // cout<<"Nums top: "<<nums.top()<<"\n";
            nums.pop();
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
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 

// } Driver Code Ends