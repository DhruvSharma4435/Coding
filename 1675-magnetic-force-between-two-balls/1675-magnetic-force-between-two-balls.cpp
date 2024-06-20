class Solution {
public:
    bool isPossible(vector<int> position, int m , int mid)
    {
        int count = 1, prevPos = position[0];
        for(int i = 1; i< position.size(); i++)
        {
           
            if(abs(position[i] - prevPos) >= mid)
              {
                count++;
                prevPos = position[i];
              }
              if(count>= m)
               return true;
        }
         
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
       int s = 1; // Minimum possible distance
       int e = position.back() - position.front(); // Maximum possible distance
       int ans = 0;
       int mid = s + (e-s)/2;
        while(s <= e)
        {
            if(isPossible(position, m, mid))
            {
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