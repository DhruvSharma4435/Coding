//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void solve (vector<vector<int>> m, vector<string>& ans, string output, int n, int currRow, int currCol, vector<vector<bool>> visited)
    {
        visited[currRow][currCol] = true;
        if(currRow == n -1 &&  currCol == n -1)
         {
            ans.push_back(output);
            return;
         }
         if(currRow > 0)//up ke lia ho gaya
         {
             if(m[currRow - 1][currCol]  ==  1  && !visited[currRow - 1][currCol])
             {
                 output.push_back('U');
                 solve(m, ans, output, n, currRow - 1, currCol, visited);
                 output.pop_back();
             }
         }
         
         if(currCol > 0)//left ke lia ho gaya
         {
             if(m[currRow][currCol - 1]  ==  1 && !visited[currRow ][currCol -1])
             {
                 output.push_back('L');
                 solve(m, ans, output, n, currRow , currCol -1, visited);
                 output.pop_back();
             }
         }
         
         if(currRow < n-1)//down ke lia ho gaya
         {
             if(m[currRow + 1][currCol]  ==  1 && !visited[currRow + 1][currCol])
             {
                 output.push_back('D');
                 solve(m, ans, output, n, currRow + 1, currCol, visited);
                 output.pop_back();
             }
         }
         
         if(currCol < n-1)//Right ke lia ho gaya
         {
             if(m[currRow][currCol + 1]  ==  1 && !visited[currRow][currCol + 1])
             {
                 output.push_back('R');
                 solve(m, ans, output, n, currRow , currCol +1, visited);
                 output.pop_back();
             }
         }
         visited[currRow][currCol] = false;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<vector<bool>> visited(n, vector<bool>(n,false));
        vector<string> ans;
        string output;
        if(m[0][0] == 0 || m[n-1][n-1] == 0)
          return ans;
        solve(m, ans,output, n, 0, 0, visited);
        
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