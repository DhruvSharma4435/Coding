//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long gcd(long long  a, long long b)
    {
        if(b == 0)
          return a;
        else
          return gcd(b, a%b);
    }
    long long int InternalCount(long long int p[], long long int q[], long long int r[]) 
    {
        long long  p0 = p[0];
        long long  p1 = p[1];
        
        long long  q0 = q[0];
        long long  q1 = q[1];
        
        long long  r0 = r[0];
        long long  r1 = r[1];
        
        long long pointSum = 0;
        pointSum += gcd(abs(q0 - p0), abs(q1 - p1)) ;
        pointSum += gcd(abs(r0 - q0), abs(r1 - q1)) ;
        pointSum += gcd(abs(p0 - r0), abs(p1 - r1)) ;
        
          long long int Area = abs(p[0] * (q[1] - r[1]) + q[0] * (r[1] - p[1]) + r[0] * (p[1] - q[1])) / 2;
        Area++;
        
        
        return Area - pointSum/2;
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int p[2], q[2], r[2];
        cin >> p[0] >> p[1] >> q[0] >> q[1] >> r[0] >> r[1];
        Solution ob;
        long long int ans = ob.InternalCount(p, q, r);
        cout << ans << "\n";
    }
}
// } Driver Code Ends