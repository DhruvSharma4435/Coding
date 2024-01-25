//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
   int place_queen(int arrangement[], int x, int y) {
        for (int i=0; i<x; i++) {
            if (arrangement[i] == y || abs(arrangement[i]-y) == abs(i-x))
                return 0;
        }
    
        arrangement[x] = y;
        return 1;
    }
    
    vector <vector <int>> v;
    void n_queens(int col_no, int n, int arrangement[]) {
        for (int i=0; i<n; i++)
            if (place_queen(arrangement, col_no, i))
                if (col_no == n-1) {
                    vector <int> v2;
                    for (int j=0; j<n; j++)
                        v2.push_back(arrangement[j]+1);
                    v.push_back(v2);
                    
                } else
                    n_queens(col_no+1, n, arrangement);
    }
    
    vector<vector<int>> nQueen(int n) {
        int arrangement[n];
        n_queens(0, n, arrangement);
        return v;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends