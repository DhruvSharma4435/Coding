//{ Driver Code Starts
#include <iostream>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
        long long lucas(int n)
        {
            int m = 1e9 + 7;
            if(n == 0)
              return 2;
            if( n == 1)
              return 1;
            int prev1 = 1, prev2 = 2, ans = 0;
            for(int i = 2; i<=n ; i++)
            {
                ans = (long long) (prev1%m + prev2%m)%m;
                int temp = prev1;
                prev1 = ans;
                prev2 = temp;
            }
            return ans;
              
        }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		cout<<ob.lucas(n)<<endl;
	}
	return 0;
}
// } Driver Code Ends