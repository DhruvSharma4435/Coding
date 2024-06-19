class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xor1 = 0, xor2 =0;
        for(auto i : nums)
           xor1 = xor1 ^ i;
        for(int i = 0; i<= nums.size(); i++)
           xor2 = xor2 ^i;
        return xor1^xor2;
    }
};