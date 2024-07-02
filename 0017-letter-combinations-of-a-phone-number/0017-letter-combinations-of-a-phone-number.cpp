class Solution {
public:
    void solve(string digits, string output, vector<string> & ans, vector<string> map, int index )
    {
        //base case
        if(index == digits.length()){
            if(output == "")
               return;
            ans.push_back(output); return;
        }
        int number = digits[index] - '0';
        string value = map[number];

        for(int i = 0; i < value.length(); i++)
        {
            output.push_back(value[i]);
            solve(digits, output, ans, map, index + 1);
            output.pop_back();
        }
        
    }
    vector<string> letterCombinations(string digits) {
        vector<string> map = {"","","abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv","wxyz"};
        ios::sync_with_stdio(0);
        string output = "";
        vector<string> ans;
        solve(digits, output, ans, map,0);
        return ans;
    }
};
