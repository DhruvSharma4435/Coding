//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution
{
    public:
    
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
        stack<int> s1, s2, s3;
        for(int i = 0; i < k; i++){
            s1.push(q.front());
            q.pop();
        }
        // while(!q.empty()){
        //     cout<<q.front(); q.pop(); cout<<" ";
        // }
        
        while(!q.empty()){
            s2.push(q.front());
            q.pop();
        }
        
        while(!s2.empty()){
            s3.push(s2.top());
            s2.pop();
        }
        
        while(!s1.empty()){
            q.push(s1.top()); 
            s1.pop();
        }
        while(!s3.empty()){
            q.push(s3.top());
            s3.pop();
        }
        return q;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        Solution ob;
        queue<int> ans = ob.modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends