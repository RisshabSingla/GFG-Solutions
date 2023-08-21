//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:

    int smallestSubWithSum(int arr[], int n, int target)
    {
        int front = 0;
        int min_length = INT_MAX;
        int sum = 0;
        
        for(int i = 0; i<n; i++){
            sum+= arr[i];
            while(sum>target){
                min_length = min(min_length, i-front+1);
                sum-=arr[front];
                front++;
            }
        }
        
        if(min_length == INT_MAX){
            return 0;
        }
        return min_length;
        // Your code goes here   
    }
};




//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution obj;
		cout<<obj.smallestSubWithSum(a,n,x)<<endl;
	}
	return 0;
}
// } Driver Code Ends