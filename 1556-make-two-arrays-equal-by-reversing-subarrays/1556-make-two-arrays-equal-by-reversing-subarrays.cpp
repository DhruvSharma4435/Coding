class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        ios::sync_with_stdio(0);
        // if(target.size() == 1) return true;
        sort(target.begin(), target.end());
        sort(arr.begin(), arr.end());

        if(target == arr)  return true;
        else return false;
    }
};