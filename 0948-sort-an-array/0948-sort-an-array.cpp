class Solution {
public:
    void merge(vector<int>& nums, int s, int e)
    {
        int mid = s + (e - s)/2, len1 = mid - s + 1, len2 = e - mid, k = s;
        vector<int> arr1(len1);
        vector<int> arr2(len2);
        for(int i = 0; i< len1; i++)
            arr1[i] = nums[k + i];
        k = mid + 1;
        for(int i = 0; i< len2; i++)
            arr2[i] = nums[k + i];
        k = s;
        int i = 0, j = 0;
        while(i < len1 &&  j < len2)
        {
            if(arr1[i] == arr2[j])
            {
                nums[k++] = arr1[i++];
                nums[k++] = arr2[j++];
                continue;
            }
            if(arr1[i] < arr2[j])
            {
                nums[k++] = arr1[i++];
                continue;
            }
            else{
                nums[k++] = arr2[j++];
                continue;
            }
        }
        
        while(i < len1)
            nums[k++] = arr1[i++];
        
        while(j < len2)
            nums[k++] = arr2[j++];
        return;
    }


    void mergeSort(vector<int>& nums, int s, int e)
    {
        if( s >= e)
          return;
        int mid = s + (e - s)/2;
        mergeSort(nums, s, mid);
        mergeSort(nums, mid + 1, e);
        merge(nums, s, e);
    }

    vector<int> sortArray(vector<int>& nums) {
        
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};