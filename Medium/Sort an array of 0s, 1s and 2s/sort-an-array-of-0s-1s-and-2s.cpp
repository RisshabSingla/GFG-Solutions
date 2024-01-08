//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    void sort012(int arr[], int n)
    {
        int zeros = 0;
        int ones = 0;
        int twos = 0;
        for(int i = 0; i<n; i++){
            if(arr[i] == 0){
                zeros++;
            }else if(arr[i] == 1){
                ones++;
            }else{
                twos++;
            }
        }
        
        int index = 0;
        
        while(zeros--){
            arr[index] = 0;
            index++;
        }
        
        while(ones--){
            arr[index]=1;
            index++;
        }
        while(twos--){
            arr[index] = 2;
            index++;
        }
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}


// } Driver Code Ends