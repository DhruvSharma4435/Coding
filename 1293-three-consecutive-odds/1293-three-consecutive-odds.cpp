class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        ios::sync_with_stdio(0);
        if(arr.size() < 3)
          return false;
        //create intitial window
        bool first = false, second = false, third = false;
        if(arr[0] & 1)
           first = true;
        if(arr[1] & 1)
           second = true;
        if(arr[2] & 1)
           third = true;   
        if(first == true  &&  second == true  &&  third == true)
           return true;
        
        for(int j = 3; j < arr.size(); j++)
        {
            first = second;
            second = third;
            if(arr[j] & 1)
              third = true;
            else 
              third = false;

            if(first == true  &&  second == true  &&  third == true)
               return true;  
        }
        return false;
         
    }
};