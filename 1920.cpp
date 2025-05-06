#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            ans[i] = nums[nums[i]];
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {0, 2, 1, 5, 3, 4};
    vector<int> result = sol.buildArray(nums);
    for (int num : result) {
        cout << num << " ";
    }
    return 0;
}
