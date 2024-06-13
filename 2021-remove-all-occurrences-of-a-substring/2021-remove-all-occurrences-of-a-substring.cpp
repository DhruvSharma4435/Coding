class Solution {
public:
    string removeIndices(string str, int indexFrom, int indexTo)
    {   int n = str.length();
        int size = str.length(), k = indexTo - indexFrom + 1;
        for(int j = indexFrom + k; j< size; j++)
        {
            str[j - k] = str[j];
        }
        str.resize(n - k);
        return str;
    }
    string removeOccurrences(string s, string part) {
        
        while(s.find(part) != -1)
        {
        int indexFrom = s.find(part);
        int indexTo = indexFrom +  part.length() -1;
         s = removeIndices(s, indexFrom, indexTo);
        }
        return s;
    }
};