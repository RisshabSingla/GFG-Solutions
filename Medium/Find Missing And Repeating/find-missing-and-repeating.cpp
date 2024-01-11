//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        unordered_map<int,int> freq;
        for(int i = 0; i<n;i++){
            freq[arr[i]]++;
        }
        int missing = -1;
        int repeat = -1;
        for(int i = 1; i<=n; i++){
            if(freq[i] == 0){
                missing = i;
            }
            if(freq[i] == 2){
                repeat = i;
            }
        }
        return {repeat, missing};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends