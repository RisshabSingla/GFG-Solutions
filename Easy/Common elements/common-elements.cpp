//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:    
       vector <int> commonElements (int arr1[], int arr2[], int arr3[], int n1, int n2, int n3)
        {
            //code here.
            vector<int> ans;
            int index1 = 0;
            int index2 = 0;
            int index3 = 0;
            while(index1<n1 && index2 < n2 && index3 < n3){
                if(arr1[index1] == arr2[index2] && arr2[index2] == arr3[index3]){
                    ans.push_back(arr1[index1]);
                    while(arr1[index1] == arr2[index2]){
                        index1++;
                    }
                    // index1++;
                    index2++;
                    index3++;
                }
                
                if(arr1[index1]< arr2[index2]  || arr1[index1]< arr3[index3]){
                    index1++;
                }
                
                if(arr2[index2]< arr3[index3] || arr2[index2]< arr1[index1]){
                    index2++;
                }
                
                if(arr3[index3]< arr1[index1] || arr3[index3] < arr2[index2]){
                    index3++;
                }
            }
            return ans;
            
        }

};

//{ Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; 
        cin >> n1 >> n2 >> n3;
        int A[n1];
        int B[n2];
        int C[n3];
        
        for (int i = 0; i < n1; i++) cin >> A[i];
        for (int i = 0; i < n2; i++) cin >> B[i];
        for (int i = 0; i < n3; i++) cin >> C[i];
        
        Solution ob;
        
        vector <int> res = ob.commonElements (A, B, C, n1, n2, n3);
        if (res.size () == 0) 
            cout << -1;
        for (int i = 0; i < res.size (); i++) 
            cout << res[i] << " "; 
        cout << endl;
    }
}
// } Driver Code Ends