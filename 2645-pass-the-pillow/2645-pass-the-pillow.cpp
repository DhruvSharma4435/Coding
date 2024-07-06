class Solution {
public:
    int passThePillow(int n, int time) {
        ios::sync_with_stdio(0);
        if(time > (n - 1))
        {
            int noOfTimes = time / (n - 1);
            time = time % (n - 1);
            if(noOfTimes % 2 == 0)
               return time + 1;
            else
               return n - time ;
        }
        else return time + 1; 
    }
};