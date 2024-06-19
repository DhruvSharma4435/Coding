class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        ios::sync_with_stdio(0);
        //pahele binary search indexes ke upar laga ke minIndex nikaal le
        int s = 0, e = nums.size() - 1, minIndex = INT_MAX, maxIndex = -1;
        int mid = s + (e -s)/2;
        while(s <= e)
        {
            if(nums[mid] == target)
            {
                minIndex = min(minIndex, mid);
                e = mid - 1;
            }
            if(nums[mid] < target)
               s = mid + 1;
            else 
               e = mid - 1;
            mid = s + (e -s)/2;
        }
        s = 0; e = nums.size() - 1;
        mid = s + (e -s)/2;

        //same kaam maxIndex ke liye
        while(s <= e)
        {
            // cout<<"mid = "<<mid;
            if(nums[mid] == target)
            {
                maxIndex = max(maxIndex, mid);
                s = mid + 1;
            }
            else if(nums[mid] < target)
               s = mid + 1;
            else 
               e = mid - 1;
            mid = s + (e -s)/2;
            cout<<"mid = "<<mid;
        }
        vector<int> ans;
        if(minIndex == INT_MAX)
            minIndex = -1;
        ans.push_back(minIndex);
        ans.push_back(maxIndex);
        return ans;
    }
};