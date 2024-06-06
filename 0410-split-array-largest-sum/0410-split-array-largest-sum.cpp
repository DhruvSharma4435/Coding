class Solution {
public:
    bool isPossible(vector<int> nums, int mid, int k){
        int sum = 0;
        int count = 1;
        for(int i = 0; i< nums.size(); i++){
            if((sum + nums[i])<= mid)
               sum += nums[i];
            else{
                count++;
                if(count> k || nums[i]> mid)
                  return false;
                sum = nums[i];
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        //first we create the sample space
        int sum  = 0;
        for(int i = 0; i<nums.size(); i++)
           sum += nums[i];
        int s = 0, e = sum, ans = -1;
        int mid = s + (e-s)/2;
        while(s <= e){
            if(isPossible(nums, mid, k)){
                ans = mid;
                e = mid-1;
            }
            else 
                s = mid+ 1;

            mid = s + (e-s)/2;
        }
        return ans;
    }
};