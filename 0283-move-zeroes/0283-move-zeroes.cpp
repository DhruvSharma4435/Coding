class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count = 0;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] == 0)
            {
              count++;
              continue;    
            }  
            else
            {
                nums[i - count] = nums[i];
            }
        }
        int n = nums.size();
        while(count--){
            nums[n - 1] = 0;
            n--;
        }
    }
};