//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	void rearrange(int arr[], int n) {
	    // code here
	    vector<int> neg;
	    vector<int> pos;
	    for(int i = 0; i<n; i++){
	        if(arr[i]<0){
	            neg.push_back(arr[i]);
	        }else{
	            pos.push_back(arr[i]);
	        }
	    }
	    
	    int index1 = 0;
	    int positives = pos.size();
	    int negatives = neg.size();
	    int index2 = 0;
	    int index = 0;
	    while(index1 < positives && index2< negatives){
	        if(index%2 == 0){
	            arr[index] = pos[index1];
	            index1++;
	        }else{
	            arr[index] = neg[index2];
	            index2++;
	        }
	        index++;
	    }
	    
	    while(index1 < positives){
	        arr[index] = pos[index1];
	        index1++;
	        index++;
	    }
	    
	    while(index2 < negatives){
	        arr[index] = neg[index2];
	        index2++;
	        index++;
	    }
	    
	    
	    
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends