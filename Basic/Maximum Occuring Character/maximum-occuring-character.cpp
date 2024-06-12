//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string str)
    {   vector<int>arr(26, -1);
        for(int i = 0; i<str.length(); i++)
        {
            char ch = str[i];
            arr[ch - 'a'] += 1;
        }
        int maxIndex = 0;
        int maxi = INT_MIN;
        for(int i = 0; i< arr.size(); i++)
        {
            if(arr[i] > maxi)
             {   maxi = arr[i];
                 maxIndex = i;
             }     
        }
        char ans = maxIndex  + 'a';
        return ans;
    }

};

//{ Driver Code Starts.

int main()
{
   
    int t;
    cin >> t;
    while(t--)
    {
        string str;
        cin >> str;
    	Solution obj;
        cout<< obj.getMaxOccuringChar(str)<<endl;
    }
}
// } Driver Code Ends