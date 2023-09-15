//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    // Complete the function
	    if(k == 1){
	        return n;
	    }
	    vector<int> sum(n,-1);
	    sum[0] = arr[0]%k;
	    unordered_map<int,int> pos;
	   // pos[sum[0]] = 0;
	    int max_length = INT_MIN;
	    int curr_sum = 0;
	    for(int i = 0; i<n; i++){
	        curr_sum+= arr[i];
	        sum[i] = ((curr_sum)%k + k)%k;
	        if(sum[i] == 0){
	            max_length = i+1;
	        }
	        if(pos.count(sum[i]) == 0){
	            pos[sum[i]] = i;
	        }else{
	           // cout<<"i: "<<i<<" pos: "<<pos[sum[i]]<<endl;
	            int length = i - pos[sum[i]];
	            max_length = max(length, max_length);
	        }
	    }
	    
	   // for(auto i: sum){
	   //     cout<<i<<" ";
	   // }
	   // cout<<endl;
	    if(max_length == INT_MIN){
	        return 0;
	    }
	    return max_length;
	    
	}
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,k,i;
	cin>>n>>k; int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution ob;
	cout<<ob.longSubarrWthSumDivByK(arr, n, k)<<"\n";
	}
	return 0;	 
}

// } Driver Code Ends