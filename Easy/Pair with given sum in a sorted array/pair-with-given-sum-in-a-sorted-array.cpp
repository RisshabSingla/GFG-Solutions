//{ Driver Code Starts
#include <bits/stdc++.h>


using namespace std;




// } Driver Code Ends

class Solution{
  public:
    int Countpair(int arr[], int n, int sum){
        
        // Complete the function
        int front = 0;
        int last = n-1;
        int count = 0;
        while(front<last){
            int s = arr[front]+arr[last];
            if(s == sum){
                // cout<<arr[front]<<" "<<arr[last]<<endl;
                count++;
                front++;
                last--;
            }else if(s<sum){
                front++;
            }else{
                last--;
            }
        }
        if(count == 0){
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
        
        int n;
        cin>>n;
        int arr[n+1];
        
        for(int i=0;i<n;i++)
        cin>>arr[i];

        int sum;
        cin>>sum;
        Solution obj;
        cout << obj.Countpair(arr, n, sum) << endl;
        
    }
	return 0;
}

// } Driver Code Ends