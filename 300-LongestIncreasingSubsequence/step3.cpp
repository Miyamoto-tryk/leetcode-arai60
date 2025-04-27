#include <algorithm>
#include <vector>
using namespace std;
class Solution {
 public:
  int lengthOfLIS(vector<int>& nums) {
    const int NUMS_LENGTH = nums.size();
    // DP
    vector<int> index_to_LISlength(NUMS_LENGTH, 0);
    for (int index = 0; index < NUMS_LENGTH; index++) {
      int prev_LISlength = 0;
      for (int prev_index = 0; prev_index < index; prev_index++) {
        if (nums[prev_index] < nums[index]) {
          prev_LISlength = max(index_to_LISlength[prev_index], prev_LISlength);
        }
      }
      index_to_LISlength[index] = prev_LISlength + 1;
    }
    return *max_element(index_to_LISlength.begin(), index_to_LISlength.end());
  }
};