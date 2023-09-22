//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int maxSubStr(string str){
        //Write your code here
        int count = 0;
        int left = 0;
        int right = 0;
        int slen = str.length();
        int ones = 0;
        int zeros = 0;
        while(right<slen){
            if(str[right] == '0'){
                zeros++;
            }
            if(str[right] == '1'){
                ones++;
            }
            if(str[left]!= str[right] && ones == zeros){
                count++;
                left = right+1;
                ones = 0;
                zeros = 0;
            }
            right++;
        }
        if(count == 0 || zeros!= ones){
            return -1;
        }
        return count;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin >> str;
	    Solution ob;
	    int ans = ob.maxSubStr(str);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends