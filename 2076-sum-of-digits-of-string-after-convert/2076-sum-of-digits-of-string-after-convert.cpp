#include<string>
class Solution {
public:
    int getLucky(string s, int k) {
    int sum = 0;
        for (char ch : s) {
            int a = ch - 96;
            sum += a % 10; a /= 10;     // First digit
            sum += a % 10; a /= 10;     // Second digit 
            sum += a;                      // Third digit if (ch > 99)
        }
        k--;   // One Transform operation is done
        while (k > 0) {
            int temp = sum;
            sum = 0;
            while (temp != 0) {
                sum += temp % 10;
                temp /= 10;
            }
            k--;
        }
        return sum;
    }
};