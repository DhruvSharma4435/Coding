//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    long long sumMatrix(long long n, long long q) {
        if(q < 2 || q> 2*n)
          return 0;
        if( q == 2 || q == 2*n)
            return 1;
        if(q < (n+1))
        {
            q = 2*n - q + 2;
        }
        if(q == n + 1)
          return n;
        if( q & 1)//if q is odd
        {
            q = q - 1;//now q is definitely an even number
            long long steps = q/2 - 1;
            return 2*(n - steps) - 2;
        }
        else//if q is even
        {
            long long steps = q/2 - 1;
            return 2*(n - steps) - 1;
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n,q;
        
        cin>>n>>q;

        Solution ob;
        cout << ob.sumMatrix(n,q) << endl;
    }
    return 0;
}
// } Driver Code Ends