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
            {swap(nums[index], nums[i]);
            solve(nums, ans, index + 1);}
             
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        ios::sync_with_stdio(0);
        vector<vector<int>> ans;
        solve(nums,ans, 0);
        set<vector<int>> unique_permutations(ans.begin(), ans.end());

        // Convert the set back to a vector
        vector<vector<int>> result(unique_permutations.begin(), unique_permutations.end());
        
        return result; 
    }
};