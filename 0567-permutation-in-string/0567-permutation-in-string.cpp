class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> arr1(26,0);
        for(int i = 0; i< s1.length(); i++)
        {
            arr1[s1[i] - 'a']++;
        }
        for(int i = 0; i< s2.length(); i++)
        {
            vector<int> arr2(26,0);
            for(int j = i; j< i + s1.length()  &&  j<s2.length(); j++)
            {
                arr2[s2[j] - 'a']++;
            }
            if(arr1 == arr2)
              return true;
        }
        return false;
    }
};