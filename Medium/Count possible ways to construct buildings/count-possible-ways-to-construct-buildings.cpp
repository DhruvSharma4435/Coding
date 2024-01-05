//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int mod=1000000007;
    pair<int,int > newfunc(int n){
       
        if(n==1) return {1,1};
        
        auto p=newfunc(n-1);
        int s=p.first;
        int b=p.second;
        
        int temp=s;
        s=((s%mod)+(b%mod))%mod;
        b=temp;
        return {s,b};
    }
    int TotalWays(int N)
    {
        // Code here
        auto p=newfunc(N);
        int ans= ((p.first)%mod + (p.second)%mod)%mod;
        ans=(1LL* (ans)*(ans))%mod;
        return ans;
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends