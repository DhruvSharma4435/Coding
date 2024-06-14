class Solution {
public:
    bool isValid(vector<int> nums, int mid, int k )
    {   
        int sum = 0, count = 1;
        for(int i = 0; i< nums.size(); i++)
        {
            if(sum + nums[i] <= mid)
               sum += nums[i];
            else
            {
                count++;
                if(count>k ||  nums[i] > mid)
                  return false;
                
                sum = nums[i];
            }
        }
        return true; 
    }

    //already solved question hai, 1 st revision kr raha hu
    int splitArray(vector<int>& nums, int k) {
        int sum = 0;
        for(int i = 0; i< nums.size(); i++)
           sum += nums[i];
        //Sample space to bana li

        int s = 0, e = sum;
        int mid = s + (e -s)/2;
        int ans = -1;
        while(s <= e)
        {
            if(isValid(nums,mid, k))
              {
                ans = mid;
                e = mid - 1;
              }
            else 
               s = mid + 1;
            mid = s + ( e -s)/2;
        }

        return ans;
    }
};