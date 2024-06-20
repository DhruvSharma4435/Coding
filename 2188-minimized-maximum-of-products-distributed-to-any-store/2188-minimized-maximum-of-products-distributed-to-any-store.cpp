class Solution {
public:
  bool isPossible(const std::vector<int>& quantities, int mid, int n) {
        int count = 0;
        
        for (int i = 0; i < quantities.size(); ++i) {
            long long quantity = quantities[i];
            // Calculate how many stores are needed for the current quantity
            while (quantity > 0) {
                quantity -= mid;
                count++;
                if (count > n) {
                    return false;
                }
            }
        }
        return count <= n;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        ios::sync_with_stdio(0);
        //sabse pahel sample sapce bana le, aur phir use BS se conquer kr le
        long long sum = 0;
        for(auto i : quantities)
           sum += i;

        long long  s = 1, e = sum;
        long long mid = s + (e - s)/2, ans = -1;
        while(s<=e)
        {
            if(isPossible(quantities, mid, n)){
                ans = mid;
                e = mid - 1;
            }
            else
                s = mid + 1;
            mid = s + (e - s)/2;
        }
        return mid;
    }
};