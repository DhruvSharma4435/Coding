class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(p.length() > s.length())
            {
                vector<int> arr = {};
                return arr;
            }
        vector<int> arr1(26,0);
        for(int i = 0; i<p.size(); i++)
        {
            arr1[p[i] - 'a']++;
        }
        vector<int> ans;

        vector<int> arr2(26,0);
        int i = 0;
        for(; i<p.size(); i++){
            arr2[s[i] - 'a']++;
        }
        if(arr1 == arr2)
          ans.push_back(0);

        //now implement sliding window technique
        
        int k = p.size();
        i = k;
        while(i< s.size())
        {   arr2[s[i - k] - 'a']--;
            arr2[s[i] - 'a']++;

            if(arr1 == arr2)
              ans.push_back(i-k + 1);
            i++;
        }
        return ans;
    }
};