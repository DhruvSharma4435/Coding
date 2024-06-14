class Solution {
public:
//faltu me question ko complex mat kr;
    int compress(vector<char>& chars) {
        if(chars.size() == 1)
          return 1;
        if(chars.size() == 0)
          return 0;
        int i = 0; 
        int ansIndex = 0; 
        int n = chars.size();
        while( i< n)
        {
            int j = i + 1;
            while( j< n && chars[i] == chars[j])
                 j++;
            //loop se bahar do hi conditions me aa sakte ho
            // ye to j >n  ya phir new character mil gaya ho
            chars[ansIndex++] = chars[i]; 
            int count = j - i;
            if(count > 1)
            {
                string s = to_string(count);
                for(char ch : s)
                {
                    chars[ansIndex++] = ch;
                }
                 
            }
           
            i = j;
        }
        return ansIndex;
    }
};