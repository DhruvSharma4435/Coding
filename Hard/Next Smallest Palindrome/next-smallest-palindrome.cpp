//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	 vector<int> func(int num[], int n,int y, int x){
        // cout<<x<<endl;
        int c = 1, i = x-1;
        vector<int> v;
        if(n%2 == 1){
            i++;
        }
        while(i >= 0){
            v.push_back((num[i]+c)%10);
            c = (num[i]+c)/10;
            i--;
        }
        if(c){
            v.push_back(c);
        }
        reverse(v.begin(), v.end());
        return v;
    }
    bool check(int num[], int n){
        for(int i = 0;i  <n;i++){
            if(num[i] != 9) return false;
        }
        return true;
    }
	vector<int> generateNextPalindrome(int num[], int n) {
	    if(check(num, n)){
	        vector<int> ans(n+1, 1);
	        for(int h = 1;h < n;h++) ans[h] = 0;
	        
	        return ans;
	    }
	    int x = n/2;
	    vector<int> v;
	    
	    int i, j, f = 0, f1 = 0;
	    if(n%2 == 1){
	        i = x-1;j=x+1;
	    }
	    else{
	        i = x-1;j = x;
	    }
	    
	    for(;i >= 0, j< n;i--, j++){
	        if(num[i] != num[j]){
	            f =1;
	           // cout<<i<<" "<<j<<endl;
	            if(num[i] > num[j]){
	                
	                for(int k = 0;k < x;k++){
	                    v.push_back(num[k]);
	                }
	                if(n%2 == 1)
	                v.push_back(num[x]);
	            }
	            else{
	                f1 = 1;
	                v = func(num, n, i, x);
	            }
	            break;
	        }
	    }
	    if(f == 0){
	        f1 = 1;
	         v = func(num, n, i, x);
	    }
	    int k = v.size()-1;
	    if(n%2 == 1){
	       // if(f1 == 0)
	        
	        k--;}
        
	    
	    for(;k >=0;k--){
	        v.push_back(v[k]);
	    }
	    
	    return v;
	}

};

//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int num[n];
        for (int i = 0; i < n; i++) {
            cin >> num[i];
        }
        Solution ob;
        auto ans = ob.generateNextPalindrome(num, n);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends