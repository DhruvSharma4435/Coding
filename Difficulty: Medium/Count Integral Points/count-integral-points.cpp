//{ Driver Code Starts


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
  public:
    int gcd(int a, int b)
    {
        if(b == 0)
          return a;
        else
          return gcd(b,a%b);
    }
    int countIntegralPoints(int x1, int y1, int x2, int y2) {
        // code here
        if(x1 == x2  &&  y1 == y2)
          return 0;
        return gcd(abs(x1 - x2), abs(y1 - y2)) - 1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int x1,y1,x2,y2;
        
        cin>>x1>>y1>>x2>>y2;

        Solution ob;
        cout << ob.countIntegralPoints(x1,y1,x2,y2) << endl;
    }
    return 0;
}
// } Driver Code Ends