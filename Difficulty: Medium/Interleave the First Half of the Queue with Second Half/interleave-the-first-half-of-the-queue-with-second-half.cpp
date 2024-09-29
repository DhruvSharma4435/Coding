//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<int> rearrangeQueue(queue<int> &q){
        queue<int> q1;
        queue<int> q2;
        int size = q.size();
        
        for(int i = 0; i< size/2; i++){
            q1.push(q.front());
            q.pop();
        }
        for(int i = size/2; i< size; i++){
            q2.push(q.front());
            q.pop();
        }
        
        vector<int> ans;
        bool flag = true;
        
        for(int i = 0; i< size; i++){
            if(flag == true  &&  !q1.empty()){
                ans.push_back(q1.front());
                q1.pop();
                flag = false;
            }
            else if(flag == false &&  !q2.empty()){
                ans.push_back(q2.front()); 
                q2.pop();
                flag = true;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        queue<int> q;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            q.push(a);
        }
        Solution ob;
        vector<int> ans=ob.rearrangeQueue(q);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
// } Driver Code Ends