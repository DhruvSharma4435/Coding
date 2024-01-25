//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    
     void permutations(string str,string s,int n,vector<int> &visited,vector<string> &ans){
        if(str.size()==n){
            ans.push_back(str);
        }
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                str+=s[i];
                visited[i]=1;
                permutations(str,s,n,visited,ans);
                str.pop_back();
                visited[i]=0;
            }
        }
    }
    vector<string> permutation(string S)
    {
        vector<string>ans;
        // sort(S.begin(),S.end());
        int n=S.size();
        vector<int>visited(n,0);
        string str="";
        for(int i=0;i<n;i++){
            fill(visited.begin(),visited.end(),0);
            str = S[i];
            visited[i]=1;
            permutations(str,S,n,visited,ans);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends