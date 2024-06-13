class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n = part.size();
        int i = 0; 
        while(1)
        {
           i =  s.find(part);
           if(i == -1)
             break;

           s.erase(i, n);
        }
        return s;
    }
};