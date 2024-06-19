class Solution {
public:
    bool isSolution(vector<int>& bloomDay, int m, int k, int mid) {
        int i = 0;
        int countBoq = 0;
        while (i < bloomDay.size()) {
            if (bloomDay[i] <= mid) {
                int j;
                for (j = i; j < (i + k) && j < bloomDay.size(); j++) {
                    if (bloomDay[j] > mid) break;
                }
                if (j == (i + k)) {
                    countBoq++;
                    if (countBoq >= m) return true;
                    i += k;
                } else {
                    i = j + 1;
                }
            } else {
                i++;
            }
        }
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long)m*k > bloomDay.size())
           return -1;
        //first we create the sample space
        int s = *min_element(bloomDay.begin(), bloomDay.end());
        int e = *max_element(bloomDay.begin(), bloomDay.end());
        
        
        int mid = s + (e -s)/2;
        
        while(s <= e)
        {
            
            if(isSolution(bloomDay, m, k, mid))
                e = mid - 1;
            
            else
                s = mid + 1;
            
            mid = s + (e -s)/2;
            
        }
        
        return s;
    }
};