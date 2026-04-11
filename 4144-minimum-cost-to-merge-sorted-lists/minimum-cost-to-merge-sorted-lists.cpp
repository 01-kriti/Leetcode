#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Count numbers < guess in enabled lists
    static int num_lt(const vector<vector<int>>& lists, int enabled, int guess) {
        int result = 0;
        for (int i = 0; i < lists.size(); i++) {
            if ((enabled >> i) & 1) {
                // first element >= guess
                int num_lt = lower_bound(lists[i].begin(), lists[i].end(), guess) - lists[i].begin();
                result += num_lt;
            }
        }
        return result;
    }

    long long minMergeCost(vector<vector<int>>& lists) {
        int n = lists.size();

        vector<int> all_nums;
        for (auto& lst : lists) {
            all_nums.insert(all_nums.end(), lst.begin(), lst.end());
        }
        sort(all_nums.begin(), all_nums.end());

        // Precompute (length, median) for all subsets
        vector<pair<long long, long long>> subsets(1 << n, {0, 0});

        for (int subset = 1; subset < (1 << n); subset++) {
            int result_len = 0;
            for (int i = 0; i < n; i++) {
                if ((subset >> i) & 1) {
                    result_len += lists[i].size();
                }
            }

            int median_lt = (result_len - 1) / 2;

            // Binary search for median
            int low = 0, high = all_nums.size() - 1;
            int actual_median = -1;

            while (low <= high) {
                int mid = (low + high) / 2;
                int num = all_nums[mid];

                int count = num_lt(lists, subset, num);

                if (count <= median_lt) {
                    actual_median = num;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }

            subsets[subset] = {result_len, actual_median};
        }

        // DP for minimum merge cost
        vector<long long> dp(1 << n, LLONG_MAX);

        for (int subset = 0; subset < (1 << n); subset++) {
            if (__builtin_popcount(subset) <= 1) {
                dp[subset] = 0;
            } else {
                int a = (subset - 1) & subset;
                while (a > 0) {
                    int b = subset ^ a;

                    auto [lenA, medA] = subsets[a];
                    auto [lenB, medB] = subsets[b];

                    long long cost = lenA + lenB + llabs(medA - medB);

                    dp[subset] = min(dp[subset], dp[a] + dp[b] + cost);

                    a = (a - 1) & subset;
                }
            }
        }

        return dp[(1 << n) - 1];
    }
};