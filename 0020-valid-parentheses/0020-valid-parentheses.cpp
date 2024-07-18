class Solution {
public:
    bool isValid(string s) {
        ios::sync_with_stdio(0);
        if(s.length() < 2) return false;
        
        stack<char> stak;
        for(int i = 0; i< s.length(); i++){
            if((s[i] == '(') || (s[i]== '[') || (s[i] == '{')){
                stak.push(s[i]);
            }
            else {
                if (stak.empty()) return false;
                
                char top = stak.top();
                if ((s[i] == ')' && top == '(') || 
                    (s[i] == ']' && top == '[') || 
                    (s[i] == '}' && top == '{')) {
                    stak.pop();
                } else {
                    return false;
                }
            }
        }
        if(stak.empty())
           return true;
        return false;
    }
};