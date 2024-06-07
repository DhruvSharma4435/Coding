class Solution {
public:
    int minimumChairs(string s) {
        int ans = 0; 
        int maxi = 0;
        for(int i = 0; i< s.length(); i++)
        {

            if(s[i] == 'E')
                ans++;
            else
                ans--;
            maxi = max(ans, maxi);
        }
        return maxi;
    }
};