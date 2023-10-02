//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to find list of all words possible by pressing given numbers.
    
    string getCodes(int n){
        
        switch(n){
            case 2:
                return "abc";
            case 3:
                return "def";
            case 4:
                return "ghi";    
            case 5:
                return "jkl";
            case 6:
                return "mno";
            case 7:
                return "pqrs";
            case 8:
                return "tuv";
            case 9:
                return "wxzy";
            default:
                return "";
        }
        return "";
    }
    
    void duplicateArray(vector<string> &ans, int len){
        int size = ans.size();
        for(int i = size; i<size*len; i++){
            ans.push_back(ans[i%size]);
        }
    }
    
    vector<string> possibleWords(int arr[], int n)
    {
        //Your code here
        vector<string> ans;
        ans.push_back("");
        for(int i = 0; i<n; i++){
            string a = getCodes(arr[i]);
            int size = ans.size();
            int alen = a.length();
            duplicateArray(ans, alen);
            int index = -1;
            for(int i = 0; i<alen*size; i++){
                if(i%size == 0){
                    index++;
                }
                ans[i]+= a[index];
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
        
        
    }
};


//{ Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}
// } Driver Code Ends