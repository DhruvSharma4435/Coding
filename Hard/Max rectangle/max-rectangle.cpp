//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
    int maxHist(int A[],int n)
    {
        stack<int>S;
        int tp,maxArea=INT_MIN,area;
        int i=0;
        while(i<n)
        {
            if(S.empty() || A[S.top()] <= A[i])
            {
                S.push(i++);
            }
            else{
                tp=S.top();
                S.pop();
                area = A[tp]*(S.empty()? i:i-S.top()-1);
                maxArea = max(maxArea,area);
            }
        }
        while(!S.empty())
        {
            tp=S.top();
            S.pop();
            area = A[tp]*(S.empty()? i:i-S.top()-1);
            maxArea = max(maxArea,area);
        }
        return maxArea;
    }
  
    int maxArea(int M[MAX][MAX], int n, int m) 
    {
        int result = maxHist(M[0],m);
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(M[i][j] == 1)
                {
                    M[i][j]+=M[i-1][j];
                }
            }
            result = max(result,maxHist(M[i],m));
        }
        return result;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends