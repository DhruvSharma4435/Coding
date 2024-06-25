class Solution {
private:
    int partition(vector<int>& nums, int s, int e) {
        // Randomly select a pivot index and swap with the start
        int randomPivotIndex = s + rand() % (e - s + 1);
        swap(nums[s], nums[randomPivotIndex]);
        
        int pivot = nums[s];
        int count = 0;

        // Count elements less than pivot
        for (int i = s + 1; i <= e; ++i) {
            if (nums[i] < pivot) {
                ++count;
            }
        }

        // Place pivot at its correct position
        int pivotIndex = s + count;
        swap(nums[s], nums[pivotIndex]);

        // Partition the array around the pivot
        int i = s, j = e;
        while (i < pivotIndex && j > pivotIndex) {
            while (i < pivotIndex && nums[i] < pivot) {
                ++i;
            }
            while (j > pivotIndex && nums[j] >= pivot) {
                --j;
            }
            if (i < pivotIndex && j > pivotIndex) {
                swap(nums[i], nums[j]);
            }
        }
        return pivotIndex;
    }


    void quickSort(vector<int> & nums, int s, int e)
    {
        if(s >= e)
           return;
        int p = partition(nums, s, e);
        quickSort(nums, s , p - 1);
        quickSort(nums, p + 1, e);
    }
public:
//This time it's done using quick sort, date - next day after merge sort!
    vector<int> sortArray(vector<int>& nums) {
        ios::sync_with_stdio(0);
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }
};