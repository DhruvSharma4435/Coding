class Solution {
public:
    bool isValid(vector<int> arr1, vector<int> arr2)
    {
        for(int i = 0; i< arr1.size(); i++)
        {
            if(arr1[i] != arr2[i])
            return false;
        }
        return true;
          
    }
    bool checkInclusion(string s1, string s2) {
        if(s1.length()> s2.length())
          return 0;
        vector<int> arr1(26,0);
        for(int i = 0; i< s1.length(); i++)
        {
            arr1[s1[i] - 'a']++;
        }
        int k = s1.length();
       // sliding window technique implement karenge;
       // pahele ek s2 ki window to bana le
       vector<int> arr2(26, 0);
       int i = 0;
       for(; i<k; i++)
           arr2[s2[i] - 'a']++;

        if(arr1 == arr2)
          return true;
        
        //ab sliding window implement kar de
        i = k;
        while(i< s2.length())
        {
            arr2[s2[i-k] - 'a']--;
            
            if( i < s2.length())
             arr2[s2[i] - 'a']++;

            if(isValid(arr1, arr2))
              return true;
            i++;
        }
      
        return false;
    }
};