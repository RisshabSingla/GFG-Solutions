//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    void helper(int target, int index, vector<int> curr, vector<vector<int>> &ans, vector<int> &arr){
        if(index == arr.size()){
            if(target == 0){
                ans.push_back(curr);
            }
            return;
        }
        if(target - arr[index] >= 0){
            curr.push_back(arr[index]);
            helper(target-arr[index], index, curr, ans, arr);
            curr.pop_back();
        }
        helper(target, index+1, curr, ans,arr);
    }
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    vector<vector<int> > combinationSum(vector<int> &arr, int target) {
        // Your code here
        sort(arr.begin(), arr.end());
        vector<int> numbers;
        numbers.push_back(arr[0]);
        int index = 0;
        for(int i =1; i<arr.size(); i++){
            if(arr[i] != numbers[index]){
                numbers.push_back(arr[i]);
                index++;
            }
        }
        vector<vector<int>> ans;
        vector<int> curr;
        helper(target, 0, curr, ans, numbers);
        sort(ans.begin(), ans.end());
        return ans;
        
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	
// } Driver Code Ends