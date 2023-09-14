//{ Driver Code Starts
// C++ program to find minimum swaps required
// to club all elements less than or equals
// to k together
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution
{
public:
    int minSwap(int arr[], int n, int k) {
        // Complet the function
        int favourable = 0;
        for(int i = 0; i<n;i++){
            if(arr[i]<=k){
                favourable++;
            }
        }
        
        int start = 0;
        int end = 0;
        int non = 0;
        while(end != favourable){
            if(arr[end]>k){
                non++;
            }
            end++;
        }
        int ans = non;
        while(end!= n){
            if(arr[end]>k){
                non++;
            }
            if(arr[start]>k){
                non--;
            }
            start++;
            end++;
            ans = min(ans, non);
        }
        return ans;
        
        
    }
};


//{ Driver Code Starts.

// Driver code
int main() {

	int t,n,k;
	cin>>t;
	while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        Solution ob;
        cout << ob.minSwap(arr, n, k) << "\n";
    }
	return 0;
}

// } Driver Code Ends