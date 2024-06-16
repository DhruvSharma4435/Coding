//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> primeRange(int M, int N) {
       // bhai agar isme seive theorem laga dala, to life jhingalala
       vector<int>arr(N + 1, 1);
       arr[0] = arr[1] = -1;
       for(int i = 2; i<N; i++){
           for(int j = i * 2; j<= N; j = j + i){
               arr[j] = -1;
           }
       }
       vector<int> ans;
       for(int i = M; i<= N;  i++){
           if(arr[i] == 1)
             ans.push_back(i);
       }
       return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, K;
        cin >> M >> N;
        Solution ob;
        vector<int> ans = ob.primeRange(M, N);
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
}
// } Driver Code Ends