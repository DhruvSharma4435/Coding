class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> ans;
        for(int i = 0; i< nums.size(); i += 2)
        {
            //ye frequency hai
           
                int count = nums[i];
                for(int j = 0; j< count; j++){
                    ans.push_back(nums[i+1]);
                }
            
        }
        return ans;
    }
};