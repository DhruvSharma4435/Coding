class Solution {
public:
    bool isPalindrome(string s) {
        int count = 0;
        string newString(s.length(), '\0');
        for(int i = 0; i<s.length(); i++)
        {
            
            char ch = s[i];
            if('A'<= ch && ch<= 'Z')
            {
                newString[i - count] = ch - 'A' + 'a';
            }
            else if('a' <= ch && ch<= 'z')
            {
                newString[i - count] = ch;
            }
            else if('0'<= ch && ch<= '9')
            {
               newString[i-count] = ch;
            }
            else
              count++;
              continue;
        }
        
        
        int start = 0, end = s.length() -1 - count;
        while(start<= end)
        {
            if(newString[start] != newString[end])
              return false;
            start++;
            end--;
        }
        return true;
    }
};