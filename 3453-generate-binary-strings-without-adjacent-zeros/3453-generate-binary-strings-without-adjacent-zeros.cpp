class Solution {
private:
    void solve(vector<string> & ans, int n , string output, int index)
    {
        if(index == n ){
            if(output.find("00") != std::string::npos)
               return;
            ans.push_back(output);
            return;
        }
       
            solve(ans, n, output + '0', index + 1);
            solve(ans, n, output + '1', index + 1);
        
        return;
    }
public:
    vector<string> validStrings(int n) {
        vector<string>ans;
        string output = "";
        solve(ans, n, output, 0);
        for(auto i : ans)
          cout<<i<<" ";
        return ans;
    }
};