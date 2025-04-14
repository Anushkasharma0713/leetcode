#include <iostream>
using namespace std;

class Solution {
public:
    const int M = 1e9 + 7;

    long findPower(long a, long long b) { // binary exponentiation
        if (b == 0) { // base case
            return 1;
        }
        long long half = findPower(a, b / 2);
        long long result = (half * half) % M;
        if (b % 2 == 1) {
            result = (result * a) % M;
        }
        return result;
    }

    long countGoodNumbers(long long n) {
        return (long long)findPower(5, (n + 1) / 2) * findPower(4, n / 2) % M;
    }
};

int main() {
    Solution sol;
    long long n;

    cout << "Enter the value of n: ";
    cin >> n;

    long result = sol.countGoodNumbers(n);
    cout << "Count of good numbers: " << result << endl;

    return 0;
}
