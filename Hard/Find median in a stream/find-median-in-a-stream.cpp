//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
   priority_queue<int> left;
    priority_queue<int,vector<int>,greater<int> > right;
    
    public:
    
    void insertHeap(int &x)
    {
        if((int)left.size()==0) {
            left.push(x);
            return;
        }
        if(x<=left.top()) {
            left.push(x);
        }
        else right.push(x);
        int sz1=left.size(),sz2=right.size();
        if(sz2>sz1) {
            left.push(right.top());
            right.pop();
        }
        if(sz1-sz2>=2) {
            right.push(left.top());
            left.pop();
        }
    }
    
    
    
    double getMedian()
    {
        int sz=left.size()+right.size();
        if(sz%2) return left.top();
        return ((left.top()+right.top())/2.0);
    }
};


//{ Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}
// } Driver Code Ends