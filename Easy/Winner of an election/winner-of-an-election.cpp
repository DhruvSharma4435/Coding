//{ Driver Code Starts
#include <iostream>
#include <map>
#include <algorithm>
#include <cstdlib>
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{
  public:
  
    //Function to return the name of candidate that received maximum votes.
   vector<string> winner(string arr[], int n) {
        unordered_map<string, int> votes;

        // Counting the votes for each candidate
        for (int i = 0; i < n; ++i) {
            votes[arr[i]]++;
        }

        int maxVotes = 0;
        string winner = "";

        // Finding the candidate with maximum votes
        for (auto it : votes) {
            if (it.second > maxVotes || (it.second == maxVotes && it.first < winner)) {
                maxVotes = it.second;
                winner = it.first;
            }
        }

        // Converting the number of votes to string format
        string maxVotesStr = to_string(maxVotes);

        // Returning the winner and the number of votes as a vector of strings
        return {winner, maxVotesStr};
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    
    for(int i=0;i<t;i++)
    {
        
        
        int n;
        cin>>n;
        
        string arr[n];
        
        for (int i=0;i<n;i++)
        cin>>arr[i];
        Solution obj;
        vector<string> result = obj.winner(arr,n);
        
        cout<<result[0] << " " << result[1] << endl;
    }
    return 0;
}

// } Driver Code Ends