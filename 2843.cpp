#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;

        for(int num = low; num <= high; num++) {
            string s = to_string(num);

            int l = s.length();

            if(l % 2 != 0) {
                continue;
            }

            int leftSum = 0;
            int rightSum = 0;

            for(int i = 0; i < l / 2; i++) {
                leftSum += s[i] - '0';
            }

            for(int i = l / 2; i < l; i++) {
                rightSum += s[i] - '0';
            }

            if(leftSum == rightSum) {
                count++;
            }
        }

        return count;
    }
};

int main() {
    Solution sol;

    int low, high;

    cout << "Enter the lower bound: ";
    cin >> low;

    cout << "Enter the upper bound: ";
    cin >> high;

    int result = sol.countSymmetricIntegers(low, high);
    cout << "Number of symmetric integers between " << low << " and " << high << ": " << result << endl;

    return 0;
}
