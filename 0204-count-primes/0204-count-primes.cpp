
class Solution {
public:
    
    int countPrimes(int n) {
        
        
        int count = 0; 
        if(n<= 2)
          return 0;
        //sieve therorem se kar rahe hai.
        //initially mano ki saare numbers prime hai
        vector<bool> prime(n + 1, true);
        int i = 2;
        while(i<n)
        {   
            if(prime[i])
            {
                count++;
                for(int j = i*2; j<=n; j += i)
                   prime[j] = false;
            }
            i++;
        }
        return count;
    }
};