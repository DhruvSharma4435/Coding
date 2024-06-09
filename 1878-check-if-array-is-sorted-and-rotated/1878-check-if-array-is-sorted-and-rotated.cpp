class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0, i = 1;
        for(; i< nums.size(); i++)
        {
            if(nums[i - 1]<=nums[i]){
                continue;
            }
            else
            {
                count++;
                break;
            }
        }
        if( i == nums.size())
          return true;
        for(; i<nums.size(); i++)
        {
            if(nums[i] <= nums[( i+1) % nums.size()] )
              continue;
            else 
              count++;

        }
        if(count == 1)
          return true;
        else
          return false;
        }
     
};