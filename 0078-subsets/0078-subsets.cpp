class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        ios::sync_with_stdio(0);
        vector<vector<int>> ans;
        int n = nums.size();
        int subsets = (1 << n);
        for(int num = 0; num < subsets; num++)
        {
            vector<int> temp; 
            for(int i = 0; i < nums.size(); i++)
            {
                if(num & (1 << i))
                  temp.push_back(nums[i]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};