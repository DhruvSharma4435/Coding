class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        ios::sync_with_stdio(0);
        bool flag = true;
        string ans;
        int i = 0, j = 0;
        while(i < word1.length()  &&  j < word2.length())
        {
            if(flag == true)
            {
                ans.push_back(word1[i++]);
                flag = false;
            }
            else
            {
                ans.push_back(word2[j++]);
                flag = true;
            }
        }
        while( i < word1.length())
        {
            ans.push_back(word1[i++]);
        }

        while( j < word2.length())
        {
            ans.push_back(word2[j++]);
        }
      
        return ans;
    }
};