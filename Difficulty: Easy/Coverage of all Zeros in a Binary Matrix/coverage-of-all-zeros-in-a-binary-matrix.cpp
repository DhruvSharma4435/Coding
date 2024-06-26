//{ Driver Code Starts


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int findCoverage(vector<vector<int>>& matrix) {
        // Code here
       
        int row = matrix.size();
        int col = matrix[0].size();
        int count = 0;
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j< col; j++)
            {
                if(matrix[i][j] == 0)
                   {
                       if( i - 1 >= 0)
                         count += matrix[i-1][j];
                       if( i + 1 < row)
                         count += matrix[i + 1][j];
                       if( j - 1 >= 0)
                         count += matrix[i][j - 1];
                       if( j + 1 < col)
                         count += matrix[i][j + 1];
                   }
            }
        }
        return count;
    }
    
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> matrix[i][j];
        Solution obj;
        int ans = obj.findCoverage(matrix);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends