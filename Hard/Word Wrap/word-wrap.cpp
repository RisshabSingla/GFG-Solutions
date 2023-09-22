//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int dp[501][2001];
    // int min_cost = INT_MAX;
    // void helper(vector<int> &nums, int capacity, int current, int index, int lines, int cost){
    //     if(index == lines){
    //       min_cost = min(min_cost, cost);
    //       return;
    //     }
    //     int new_curr = current == 0 ? 0 : current+1;
    //     if(new_curr + nums[index] <= capacity){
    //         // same line possible
    //         // cout<<"Adding "<<nums[index]<<" in the same line"<<endl;
    //         // cout<<"current capacity of line is: "<<new_curr + nums[index]<<endl;
    //         helper(nums, capacity, new_curr + nums[index], index+1, lines, cost);
    //     }
        
    //     // placing in new line
    //     int c = pow(capacity-current, 2);
    //     // cout<<"Adding "<<nums[index]<<" in a new line"<<endl;
    //     // cout<<"Additional cost of prev line is: "<<c<<endl;
    //     helper(nums, capacity, nums[index], index+1, lines, cost+c);
    // }
    
    int helperMemo(vector<int>&nums, int capacity, int remaining, int index){
        
        if(index == nums.size()){
            return 0;
        }
        
        if(dp[index][remaining] != -1){
            return dp[index][remaining];
        }
        
        int ans = 0;
        if(nums[index] > remaining){
            // not possible in the same line
            ans = (remaining+1)*(remaining+1) + helperMemo(nums, capacity, capacity-nums[index]-1, index+1);
        }else{
            // possible in the same line
            // in the next line
            int choice1 = (remaining+1)*(remaining+1) +  helperMemo(nums, capacity, capacity-nums[index]-1, index+1);
            // in the same line
            int choice2 = helperMemo(nums, capacity, remaining-nums[index]-1, index+1);
            ans = min(choice1, choice2);
        }
        dp[index][remaining] = ans;
        return dp[index][remaining];
    }
    
    
    int solveWordWrap(vector<int>nums, int k) 
    { 
        // Code here
        // recursive code
        // helper(nums, k, 0,0,nums.size(),0);
        // return min_cost;
        memset(dp, -1, sizeof(dp));
        int n = nums.size();
        // vector<vector<int>> dp(n+1, vector<int>(k+1,-1));
        return helperMemo(nums, k, k, 0);
        
        
        
        
        
    } 
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
	}
	return 0;
}
// } Driver Code Ends