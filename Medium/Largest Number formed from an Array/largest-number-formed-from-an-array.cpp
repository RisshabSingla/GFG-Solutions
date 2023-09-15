//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	// The main function that returns the arrangement with the largest value as
	// string.
	// The function accepts a vector of strings
	static bool comp(string a, string b){
	    
	    string ab = a+b;
	    string ba = b+a;
	    return ab > ba;
	   //if(a+'0' == b){
	   //    return true;
	   //}
	   //if(b+'0' == a){
	   //    return false;
	   //}
	   
	   // if(a[0]==b[0]){
	   //     if(a.length() == b.length()){
	   //         for(int i = 1; i<a.length();i++){
	   //             if(a[i]!=b[i]){
	   //                 return a[i]>b[i];
	   //             }
	   //         }
	   //     }
	        
	        
	   //    // if(a[a.length()-1] == '0'){
	   //    //     return true;
	   //    // }
	        
	   //    // if(b[b.length()-1] == '0'){
	   //    //     return false;
	   //    // }
	   //     return a.length()>b.length();
	   // }
	   // return a[0]>b[0];
	}
	string printLargest(vector<string> &arr) {
	    // code here
	    sort(arr.begin(), arr.end(), comp);
	    string str = "";
	    for(auto i: arr){
	       // cout<<i<<" ";
	        str+= i;
	    }
	    return str;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<string> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.printLargest(arr);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends