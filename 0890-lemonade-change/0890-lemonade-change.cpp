class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        ios::sync_with_stdio(0);
        int a = 0, b = 0;
        for(int i = 0; i< bills.size(); i++)
        {
            if(bills[i] == 5){
                a++;
            }
            else if(bills[i] == 10){
                if(a == 0) return false;
                b++;
                a--;
            }
            else{
                if(a == 0) return false;
                if(b == 0){
                    if(a < 3) return false;
                    a = a - 3;
                }
                else{
                    b--;
                    a--;
                }
            }
        }
        return true;
    }
};