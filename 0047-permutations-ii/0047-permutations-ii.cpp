class Solution {
private:
    void solve(vector<int> nums, vector<vector<int>> & ans, int index)
    {
        if(index == nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for(int i = index ; i< nums.size(); i++)
        {
            if( i == index || nums[index] != nums[i])
            {
                swap(nums[index], nums[i]);
                solve(nums, ans, index + 1);
            }
             
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        ios::sync_with_stdio(0);
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        solve(nums,ans, 0);
        return ans; 
    }
};