#include <iostream>
#include <vector> 
using namespace std;

class Solution {
public:
    vector<vector<int>> result;

    void solve(vector<int>& nums, int idx, vector<int>& temp) {
        if (idx >= nums.size()) {
            result.push_back(temp);
            return;
        }

        temp.push_back(nums[idx]);
        solve(nums, idx + 1, temp);
        temp.pop_back();
        solve(nums, idx + 1, temp);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        solve(nums, 0, temp);
        return result;
    }
};
int main() {
    Solution s;
    vector<int> nums = {1, 2};
    vector<vector<int>> subsets = s.subsets(nums);

    for (auto subset : subsets) {
        cout << "[ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}

