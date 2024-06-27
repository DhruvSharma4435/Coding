class Solution {
    void powerSet(vector<int>nums, vector<vector<int>> & ans, vector<int>& temp, int s)
    {
        
        if(s == nums.size())
          {
            ans.push_back(temp);
            return;
          }
        //exclude ke lia 
        powerSet(nums, ans, temp, s + 1);
        //include ke lia
        temp.push_back(nums[s]);
        powerSet(nums, ans, temp, s + 1);
        temp.pop_back();

    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        ios::sync_with_stdio(0);
        vector<vector<int>> ans = {};
        vector<int> temp = {};
        if(nums.empty())
        {
            ans.push_back(temp);
            return ans;
        }
        powerSet(nums, ans, temp, 0);
        return ans;
    }
};