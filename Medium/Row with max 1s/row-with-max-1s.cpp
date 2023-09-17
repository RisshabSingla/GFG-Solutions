//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
	    int indexJ = -1;
	    for(int i = 0; i<m; i++){
	        if(arr[0][i] == 1){
	            indexJ = i;
	            break;
	        }
	    }
	    if(indexJ == 0){
	        return 0;
	    }
	    int row = 0;
	    if(indexJ == -1){
	        row = -1;
	        indexJ = m;
	    }
	    
	   // for(auto i: arr){
	   //     for(auto j: i){
	   //         cout<<j<<" ";
	   //     }
	   //     cout<<endl;
	   // }
	   // int indexJ = j;
	   
	   // cout<<"IndexJ is: "<<indexJ<<endl;
	    for(int i = 1; i<n; i++){
	       // cout<<"Checking for row: "<<i;
	        int j = min(indexJ,m-1);
	        for(; j>=0; j--){
	            if(arr[i][j] == 0){
	                break;
	            }
	        }
	       // cout<<" j is: "<<j<<endl;
	        if(j == -1){
	            return i;
	        }
	        if(j+1<indexJ){
	            indexJ = j+1;
	            row = i;
	        }
	       // indexJ = min(indexJ, j);
	    }
	    return row;
	}
	

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends