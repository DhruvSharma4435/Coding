//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
		void permute(string ans, vector<string> &vect, int i)
	    {
	        if(i==ans.length())
	        {
	            vect.push_back(ans);
	            return;
	        }
	        int j;
	        int len=ans.length();
	        for(j=i;j<len;j++)
	        {
	            if(ans[i]==ans[j] && i!=j)continue;
	            char t=ans[i];
	            ans[i]=ans[j];
	            ans[j]=t;
	            permute(ans,vect,i+1);
	            
	        }
	        
	    }
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    string s=S;
		    int len=s.length();
		    char arr[len];
		    int i;
		    for(i=0;i<len;i++)
		    {
		        arr[i]=s[i];
		    }
		    sort(arr,arr+len);
		    string ans="";
		    for(i=0;i<len;i++)ans=ans+arr[i];
		    vector<string>vect;
		    permute(ans,vect,0);
		    return vect;
		    
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends