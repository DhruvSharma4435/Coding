class Solution {
public:
    string reversePrefix(string word, char ch) {
        ios::sync_with_stdio;
        int n = word.length();
        int index = 0;
        while(index < n)
        {
            if(word[index] == ch)
                break;
            index++;
        }
        if(index < n)
           reverse(word.begin(), word.begin() + index + 1);
        
        return word;
         
    }
};