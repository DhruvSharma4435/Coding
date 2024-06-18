//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int padovanSequence(int n) {
        int m = 1e9 + 7;
        if(n == 0 || n == 1 || n == 2)
          return 1;
        int prev3 = 1, prev2 = 1, prev1 = 1, ans = 0;
        
        for(int i = 3; i <= n; i++)
        {
            ans = (prev3%m + prev2%m)%m;
            int temp = prev1 % m;
            
            prev1 = ans;
            prev3 = prev2;
            prev2 = temp;
            
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.padovanSequence(n) << endl;
    }
    return 0;
}
// } Driver Code Ends