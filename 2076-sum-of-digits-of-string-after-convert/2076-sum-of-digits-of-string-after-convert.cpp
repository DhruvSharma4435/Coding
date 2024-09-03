#include<string>
class Solution {
public:
    int getLucky(string s, int k) {
    ios::sync_with_stdio(0);
    string temp;
    for(int i = 0; i< s.length(); i++){
        int digit = s[i] - 'a' + 1;
        string num = to_string(digit);
        temp = temp + num;
    } 
    int sum = 0;
    while(k--){
        sum = 0;
        for(int i = 0; i<temp.length(); i++){
            int x = temp[i] - '0';
            sum = sum + x;
        }
        temp = to_string(sum);
    } 
    return sum; 
    }
};