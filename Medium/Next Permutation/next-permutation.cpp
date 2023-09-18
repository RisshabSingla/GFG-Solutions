//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> nextPermutation(int n, vector<int> arr){
        // code here
        int pivot = -1;
        for(int i = n-1; i>0; i--){
            if(arr[i-1] < arr[i]){
                pivot = i-1;
                break;
            }
        }
        if(pivot == -1){
            // array is sorted
            reverse(arr.begin(), arr.end());
            return arr;
        }
        // cout<<"pivot: "<<pivot<<endl;
        for(int i = n-1; i>=pivot; i--){
            if(arr[i]>arr[pivot]){
                swap(arr[i], arr[pivot]);
                break;
            }
        }
        
        // int index = pivot+1;
        // while(index<n && arr[index] == arr[pivot]){
        //     index++;
        // }
        // swap(arr[pivot], arr[index]);
        reverse(arr.begin()+pivot+1, arr.end());
        
        // for(auto i: arr){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        return arr;
    }
    
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends