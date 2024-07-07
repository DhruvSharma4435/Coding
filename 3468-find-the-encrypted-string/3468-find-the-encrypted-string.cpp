class Solution {
public:
    string getEncryptedString(string s, int k) {
        k = k % s.length();
        string ans = "";
        for(int i = 0; i<s.length(); i++)
        {
            if(i + k < s.length())
              ans.push_back(s[i + k]);
            else 
              ans.push_back(s[i + k - s.length()]);
        }
        return ans;
    }
};