//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution{
    public:
   bool solve(string wild, string pattern,int i,int j)
    {
        if(i==wild.length())return j==pattern.length();
       
        if(wild[i]==pattern[j]||wild[i]=='?'){
            if(solve(wild,pattern,i+1,j+1))return true;
        }
        if(wild[i]=='*'){
            if(solve(wild,pattern,i+1,j))return true;
            for(int k=j+1;k<=pattern.length();k++){
                if(solve(wild,pattern,i+1,k))return true;
            }
        }
        return false;
    }
    bool match(string wild, string pattern)
    {
        // code here
        return solve(wild,pattern,0,0);// code here
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        string wild, pattern;
        cin>>wild>>pattern;
        
        Solution ob;
        bool x=ob.match(wild, pattern);
        if(x)
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
    return 0;
}
// } Driver Code Ends