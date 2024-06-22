//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long ExtractNumber(string sentence) {
       string s = "";
       vector<long long> numbers;
       for(int i = 0; i< sentence.length(); i++)
       {
           bool temp = true;
           char ch = sentence[i];
           if('0'<= ch && ch<= '9')
              {
                  int j = i;
                  for(; j < sentence.length() && sentence[j] != ' '; j++)
                  {
                      if(sentence[j] == '9'){
                          temp = false;
                      }
                      else
                          s.push_back(sentence[j]);
                  }
                  
                  i = j ;
                  
                if(temp == false)
                   s.clear();
                else{
                    long long num = stoll(s);
                    numbers.push_back(num);
                }
                s.clear();
              }
          
           
       }
       if(!numbers.empty())
         return *max_element(numbers.begin(), numbers.end());
       return -1;
    }
};

//{ Driver Code Starts.
int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);

        Solution ob;
        cout << ob.ExtractNumber(s) << "\n";
    }

    return 0;
}

// } Driver Code Ends