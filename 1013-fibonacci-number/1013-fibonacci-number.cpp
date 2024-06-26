class Solution {
public:
    int fib(int n) {
    ios::sync_with_stdio(0);
    double phi = (1 + sqrt(5)) / 2;
    double psi = (1 - sqrt(5)) / 2;
    return round((pow(phi, n) - pow(psi, n)) / sqrt(5));
    }
};