#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int n = arr.size();
        int count = 0;

        for (int i = 0; i <= n - 3; i++) {
            for (int j = i + 1; j <= n - 2; j++) {
                if (abs(arr[i] - arr[j]) <= a) {
                    for (int k = j + 1; k <= n - 1; k++) {
                        if (abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c) {
                            count++;
                        }
                    }
                }
            }
        }
        return count;
    }
};

int main() {
    Solution sol;
    vector<int> arr;
    int n, a, b, c;

    cout << "Enter the size of the array: ";
    cin >> n;

    cout << "Enter " << n << " elements of the array:\n";
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    cout << "Enter values for a, b, and c: ";
    cin >> a >> b >> c;

    int result = sol.countGoodTriplets(arr, a, b, c);
    cout << "Count of good triplets: " << result << endl;

    return 0;
}
