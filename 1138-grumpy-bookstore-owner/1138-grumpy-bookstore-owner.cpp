class Solution {
public:
   bool isPossible(vector<int>& customers, vector<int>& grumpy, int minutes, int mid)
    {
        int n = customers.size();
        int satisfied = 0, tempCus = 0;
        
        // Calculate initial satisfied customers
        for (int i = 0; i < n; i++) {
            if (grumpy[i] == 0) {
                satisfied += customers[i];
            }
        }
        
        if (satisfied >= mid)
            return true;
        
        int maxSat = satisfied, temp = 0;
        
        // Creating a window of size minutes
        for (int i = 0; i < minutes; i++) {
            if (grumpy[i] == 1) {
                temp += customers[i];
            }
        }
        
        maxSat = max(maxSat, satisfied + temp);
        
        for (int i = minutes; i < n; i++) {
            if (grumpy[i] == 1) {
                temp += customers[i];
            }
            if (grumpy[i - minutes] == 1) {
                temp -= customers[i - minutes];
            }
            
            maxSat = max(maxSat, satisfied + temp);
        }
        
        return maxSat >= mid;
    }

    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        int sum = 0;
        for(auto i : customers){
            sum += i;
        }
        int s = 0, e = sum;
        if(minutes == customers.size())
          return sum;
        int mid = s + (e - s)/2, ans = 0;
        while(s <= e)
        {
            if(isPossible(customers, grumpy, minutes, mid)){
                ans = mid;
                s = mid + 1;
            }
            else
                e = mid - 1;
            
            mid = s + (e - s)/2;
        }
        return ans;
    }
};