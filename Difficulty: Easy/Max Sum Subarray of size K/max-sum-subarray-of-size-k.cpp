//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &arr , int N){
        if(K>N)
          return -1;
        long windowSum = 0;
        int i = 0;
        for(; i<K; i++)
           windowSum += arr[i];
         //initial window to bana li;
        
        long sum = INT_MIN;
        sum = max(sum, windowSum);
        for(;i<arr.size(); i++)
        {
            windowSum += arr[i] - arr[i - K];
            sum = max(sum, windowSum);
        }
        return sum;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends