//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int DivisibleByEight(string s){
        int l = s.length();
        
    if(l==0){
        return 1;
        
    }
    if(l ==1){
        int num = s[0] - '0';
        if(num%8 == 0) return 1;
        else  return -1;
    }
    if(l==2){
        int num = (s[0] - '0')*10;
        num+= s[1] - '0';
        if(num%8 == 0) return 1;
        else return -1;
    }
       int num = (s[l - 3] - '0') * 100;
    num += (s[l - 2] - '0') * 10;
    num += (s[l - 1] - '0');

    if (num % 8 == 0)
        return 1;
    else
        return -1;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.DivisibleByEight(S)<<"\n";
    }
}
// } Driver Code Ends