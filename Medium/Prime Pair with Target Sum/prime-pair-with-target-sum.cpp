//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    vector<int> seivePrime(int n)
    {
        vector<int> arr(n+1, 1);
        arr[0] = arr[1] = -1;
        for(int i = 2; i< n; i++)
        {
            for(int j = i * 2; j<= n; j = j + i)
            {
                arr[j] = -1;
            }
        }
        vector<int> primes;
        for(int i = 0; i< arr.size() - 1; i++)
        {
            if(arr[i] == 1)
              primes.push_back(i);
        }
        return primes;
    }
    vector<int> getPrimes(int n) {
        //pahele seive laga ke saare prime less than n nikaal le
        vector<int> primeList = seivePrime(n);
        vector<int> ans;
        int s = 0, e = primeList.size() - 1;
        while( s < e)
        {
            if(primeList[s] + primeList[s] == n){
                ans.push_back(primeList[s]);
                ans.push_back(primeList[s]);
                return ans;
            }
             if(primeList[e] + primeList[e] == n){
                ans.push_back(primeList[e]);
                ans.push_back(primeList[e]);
                return ans;
            }
            if(primeList[s] + primeList[e] ==  n){
                ans.push_back(primeList[s]);
                ans.push_back(primeList[e]);
                return ans;
            }
            else if((primeList[s] + primeList[e])< n){
                s++;
            }
            else 
                e--;
        }
        ans = {-1, -1};
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        vector<int> res = obj.getPrimes(n);

        Array::print(res);
    }
}

// } Driver Code Ends