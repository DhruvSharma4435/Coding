class Solution {
public:
     string reverseParentheses(string s) {
        ios::sync_with_stdio(0);
        vector<int> openBracket;
        for(int i = 0; i< s.length(); i++)
        {
            if(s[i] == '(')
              openBracket.push_back(i);
            if(s[i] == ')')
            {
                reverse(s.begin() + openBracket[openBracket.size() - 1], s.begin() + i);
                openBracket.pop_back();
            }
        }
        s.erase(remove(s.begin(), s.end(), '('), s.end());
        s.erase(remove(s.begin(), s.end(), ')'), s.end());
        return s;
    }
};