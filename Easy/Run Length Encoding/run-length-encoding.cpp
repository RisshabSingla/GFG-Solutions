//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends


/*You are required to complete this function */

string encode(string str)
{     
    string ans = "";
    char prev = str[0];
    int count = 1;
    for(int i =1; i<=str.length();i++){
        if(str[i]!= prev){
            ans+= char(prev);
            ans+= to_string(count);
            prev = str[i];
            count = 0;
        } 
        count++;
    }
    return ans;
  //Your code here 
}     
 
