#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int M = 1e9 + 7;

    int idealArrays(int n, int maxVal) {
        // Step 1: Precompute factorial and inverse factorial
        vector<long long> fact(n + 1, 1), invFact(n + 1, 1);
        for (int i = 2; i <= n; i++) {
            fact[i] = (fact[i - 1] * i) % M;
        }
        invFact[n] = power(fact[n], M - 2);
        for (int i = n - 1; i >= 0; i--) {
            invFact[i] = (invFact[i + 1] * (i + 1)) % M;
        }

        // Step 2: DP - dp[len][val] = number of arrays of length len ending with val
        int maxLen = 14;
        vector<vector<int>> dp(maxLen + 1, vector<int>(maxVal + 1, 0));

        for (int i = 1; i <= maxVal; i++) {
            dp[1][i] = 1;
        }

        for (int len = 2; len <= maxLen; len++) {
            for (int i = 1; i <= maxVal; i++) {
                for (int k = 2 * i; k <= maxVal; k += i) {
                    dp[len][k] = (dp[len][k] + dp[len - 1][i]) % M;
                }
            }
        }

        // Step 3: Combine using nCr
        long long res = 0;
        for (int len = 1; len <= maxLen; len++) {
            long long total = 0;
            for (int i = 1; i <= maxVal; i++) {
                total = (total + dp[len][i]) % M;
            }
            res = (res + total * nCr(n - 1, len - 1, fact, invFact)) % M;
        }

        return res;
    }

private:
    long long power(long long a, long long b) {
        long long res = 1;
        while (b > 0) {
            if (b & 1)
                res = (res * a) % M;
            a = (a * a) % M;
            b >>= 1;
        }
        return res;
    }

    long long nCr(int n, int r, const vector<long long>& fact, const vector<long long>& invFact) {
        if (r < 0 || r > n) return 0;
        return ((fact[n] * invFact[r]) % M * invFact[n - r]) % M;
    }
};

int main() {
    Solution sol;

    int n, maxVal;
    cout << "Enter value of n: ";
    cin >> n;
    cout << "Enter value of maxVal: ";
    cin >> maxVal;

    int result = sol.idealArrays(n, maxVal);
    cout << "Number of ideal arrays: " << result << endl;

    return 0;
}
