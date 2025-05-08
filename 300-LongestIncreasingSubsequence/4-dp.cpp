#include <algorithm>
#include <vector>

using namespace std;
class Solution {
 public:
  int lengthOfLIS(vector<int>& nums) {
    const int NUM_LENGTH = nums.size();
    vector<int> last_index_to_LISlength(NUM_LENGTH, 0);
    for (int i = 0; i < NUM_LENGTH; i++) {
      int LIS_length_prev_i = 0;
      for (int j = 0; j < i; j++) {
        if (nums[j] < nums[i]) {
          LIS_length_prev_i = max(LIS_length_prev_i, last_index_to_LISlength[j]);
        }
      }
      last_index_to_LISlength[i] = LIS_length_prev_i + 1;
    }
    int result = *max_element(last_index_to_LISlength.begin(), last_index_to_LISlength.end());
    return result;
  }
};