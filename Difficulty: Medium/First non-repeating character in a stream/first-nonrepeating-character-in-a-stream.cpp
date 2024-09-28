//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    vector<int> arr(26, 0);
		    deque<char> q;
		    string ans;
		    for(int i = 0; i< A.length(); i++){
		        arr[A[i] - 'a']++;
		        if(arr[A[i] - 'a'] > 1){
		            arr[A[i] - 'a']++;
		        }
		        else{
		            q.push_back(A[i]);
		        }
		        bool flag = true;
		        while(flag && !q.empty()){
		            if(arr[q.front() - 'a'] > 1){
		                q.pop_front();
		            }
		            else {
		                 ans.push_back(q.front());
		                 flag = false;
		            }
		               
		        }
		        if(flag && q.empty()) ans.push_back('#');
		    }
		       
		    return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends