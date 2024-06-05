class Solution {
public:
    int mySqrt(int x) {
        if(x == 0 || x == 1)
          return x;
        int s = 1, e = x, result = -1;
        int m = s + (e - x)/2;
        while(s <= e){
            if( m == x/m)
               return m;
            if(m < x/m)
             {
                result = m;
                s = m + 1;
             }
             else {
                e = m -1;
             }
             m = s + (e -s)/2;
        } 
        return result;
    }
};