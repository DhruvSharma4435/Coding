class Solution {
public:
    int minOperations(vector<string>& logs) {
        ios::sync_with_stdio(0);
        int depth = 0;
        string subDepth = "../", sameDepth = "./";
        for(int i = 0; i< logs.size(); i++)
        {
            if(logs[i] == subDepth && depth == 0)
            {
                continue;
            }
            if(logs[i] == subDepth && depth > 0)
            {
                depth -= 1;
            }
            else if(logs[i] == sameDepth)
            {
                continue;
            }
            else 
            {
                depth += 1;
            }
            
        }
        if(depth <= 0)
           return 0;
        return depth;
    }
};