//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
        // Your code here
        
        // Approach 1: O(n^2)
        // vector<long long> jumps(n,INT_MAX);
        // jumps[0] = 0;
        // for(int i = 0; i<n; i++){
        //     int possible = arr[i];
        //     for(int j = 0; j<possible && (i+j+1)<n; j++){
        //         jumps[i+j+1] = min(jumps[i] +1, jumps[i+j+1]);
        //     }
        //     if(jumps[n-1]!= INT_MAX){
        //         return jumps[n-1];
        //     }
        // }
        // return -1;
        
        
        
        // Approach 2: O(n)
        // Storing the farthest index we can reach
        if(arr[0] == 0){
            return -1;
        }
        
        int maxReachableIndex = arr[0];
        int jumps = 1;
        int stepsPossible = arr[0];
        
        
        for(int i = 1; i<n; i++){
            if(i == n-1){
                return jumps;
            }
            maxReachableIndex = max(maxReachableIndex, i+arr[i]);
            stepsPossible--;
            if(stepsPossible == 0){
                jumps++;
                if(i >= maxReachableIndex){
                    return -1;
                }
                stepsPossible = maxReachableIndex - i;
            }
        }
        return -1;
        
        
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends