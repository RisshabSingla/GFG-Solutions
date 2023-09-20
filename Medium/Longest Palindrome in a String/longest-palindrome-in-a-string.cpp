//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int expand(string &str, int left, int right, int slen){
        // string ans = "";
        if(left == right){
            // ans+= str[left];
            left--;
            right++;
        }
        while(left>=0 && right<slen){
            if(str[left] != str[right]){
                break;
            }
            left--;
            right++;
        }
        return (right-left-1);
    }
    string longestPalin(string str) {
        // code here
        int slen = str.length();
        int length = 0;
        string ans = "";
        for(int i = 0; i<slen; i++){
            int odd = expand(str, i, i,slen);
            int even = expand(str, i, i+1,slen);
            // cout<<"Odd is: "<<odd<<endl;
            // cout<<"Even is: "<<even<<endl;
            if(length < odd){
                length = odd;
                // cout<<"Odd greater"<<endl;
                int start;
                if(i-length/2<=0){
                    start = 0;
                }else{
                    start = i-(length/2);
                }
                
                ans = str.substr(start, length);
                // ans = str.substr(i-length/2, length);
                // cout<<"Ans is: "<<ans<<endl;
            }
            
            if(length < even){
                length = even;
                // cout<<"Even greater"<<endl;
                int start;
                if(i-length/2<0){
                    start = 0;
                }else{
                    start = i-(length/2) + 1;
                }
                
                ans = str.substr(start, length);
                // cout<<"Ans is: "<<ans<<endl;
            }
            
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends