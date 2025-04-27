#include <algorithm>
#include <vector>
using namespace std;
class Solution {
 public:
  int lengthOfLIS(vector<int>& nums) {
    const int NUMS_LENGTH = nums.size();
    vector<int> dp(NUMS_LENGTH, 0);
    dp[0] = 1;
    for (int i = 1; i < NUMS_LENGTH; i++) {
      int _max = 0;
      for (int j = 0; j < i; j++) {
        if (nums[j] < nums[i]) {
          _max = max(dp[j], _max);
        }
      }
      dp[i] = _max + 1;
    }
    return *max_element(dp.begin(), dp.end());
  }
};