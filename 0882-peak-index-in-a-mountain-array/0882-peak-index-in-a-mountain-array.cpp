class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int s = 0, e = n - 1;
        int m = s + (e - s)/2;
        while ( s<= e){
          
          
            if(arr[m - 1]< arr[m]  &&  arr[m]> arr[m + 1])
              return m;
            else if(arr[m - 1]< arr[m]  &&  arr[m]<arr[m + 1])
              s = m + 1;
            else
              e = m ;

            m = s + (e - s)/2;
        }
        return -1;
        
    }
};