//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    private:
       void solve(vector<vector<int>> m, string output, vector<string>& ans, int n, int currRow, int currCol, vector<vector<bool>> & marked)
       {
           if(currRow == n - 1  &&  currCol == n - 1)
           {
               ans.push_back(output);
               return;
           }
           marked[currRow][currCol] = true;
           
           if(currRow < n-1)//down ke lia ho gaya
           {
               if(m[currRow + 1][currCol] == 1 && !marked[currRow + 1][currCol])
               {
                   output.push_back('D');
                   solve(m, output, ans, n, currRow + 1, currCol, marked);
                   output.pop_back();
               }
           }
           
           if(currCol < n-1)//right ke lia ho gaya
           {
               if(m[currRow ][currCol + 1] == 1 && !marked[currRow ][currCol + 1])
               {
                   output.push_back('R');
                   solve(m, output, ans, n, currRow, currCol + 1, marked);
                   output.pop_back();
               }
           }
            
           if(currCol > 0)//left ke lia ho gaya
           {
               if(m[currRow][currCol - 1] == 1 &&!marked[currRow ][currCol - 1])
               {
                   output.push_back('L');
                   solve(m, output, ans, n, currRow, currCol - 1, marked);
                   output.pop_back();
               }
           }
           
           if(currRow > 0)//up ke lia ho gaya
           {
               if(m[currRow - 1][currCol] == 1 && !marked[currRow - 1][currCol])
               {
                   output.push_back('U');
                   solve(m, output, ans, n, currRow - 1, currCol, marked);
                   output.pop_back();
               }
           }
           marked[currRow][currCol] = false;
       }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        if(m[0][0] == 0 ||  m[n - 1][n - 1] == 0)
           return ans;
        string output;
        vector<vector<bool>> marked(n, vector<bool>(n, false));
        solve(m, output, ans, n, 0, 0, marked);
        
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
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends