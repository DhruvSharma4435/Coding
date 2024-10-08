class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        ios::sync_with_stdio(0);
        int maxi = 0, count = 0, ans = 0;
        for(int i = 0; i< nums.size(); i++){
            if(nums[i] > maxi){
                maxi = nums[i];
                count = 1;
                ans = 1;
            }
            else if(nums[i] == maxi){
                count++;
                ans = max(ans, count);
            }
            else{
                count = 0;
            }
        }
        return ans;
    }
};