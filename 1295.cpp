#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        for (int i = 0; i < n; i++) {
            if ((nums[i] >= 10 && nums[i] <= 99) ||
                (nums[i] >= 1000 && nums[i] <= 9999) ||
                (nums[i] == 100000)) {
                result++;
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {12, 345, 2, 6, 7896, 100000};
    
    int count = sol.findNumbers(nums);
    cout << "Count of numbers with even number of digits: " << count << endl;

    return 0;
}
