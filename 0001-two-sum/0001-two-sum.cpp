class Solution {
public:
     vector<int> twoSum(vector<int>& nums, int target) {
        map<int , int > m;
        vector<int> ans;
        
        for(int i =0; i < nums.size(); i++){ 
            int complement = target - nums[i];
            if(m.find(complement) != m.end()){
                ans.push_back(i);
                ans.push_back(m[complement]);
                return ans;
            }

            m[nums[i]] = i;
        }

        return ans;
    }
};