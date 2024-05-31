//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int swapNibbles(int n) {
        int num = 0;
        for(int i = 0; i<4; i++){
            int bit = n&1;
            num = num + bit* pow(2, i);
            n = n>>1;
        }
         num = num<<4;
         int ans = num ^ n;
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
        cout << ob.swapNibbles(n) << endl;
    }
    return 0;
}
// } Driver Code Ends