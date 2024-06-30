class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
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
        for(int i = 0; i< ans.size(); i++)
         {
            for( int j = 0; j < ans[0].size(); j++)
               cout<< ans[i][j]<<" ";
           
         }
        return ans;
    }
};