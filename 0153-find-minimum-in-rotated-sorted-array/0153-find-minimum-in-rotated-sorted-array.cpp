class Solution {
public:
    int findMin(vector<int>& nums) {
        int s = 0, e = nums.size() - 1;
        int m = s + (e-s)/2;
        if (nums[s] <= nums[e]) {
        return nums[0];
    }

        while(s<e){
            m = s + (e - s)/2;
            if(nums[m] >= nums[0])
               s = m + 1;
            else 
               e = m;
            
            
        }
        return nums[s];
    }
};