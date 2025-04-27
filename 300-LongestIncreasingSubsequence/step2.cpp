#include <vector>
using namespace std;
class Solution {
 public:
  int lengthOfLIS(vector<int>& nums) {
    const int NUMS_LENGTH = nums.size();
    const int INF = 1e5;
    vector<int> length_to_mini(NUMS_LENGTH + 1, INF);
    length_to_mini[0] = -INF;
    for (int num : nums) {
      vector<int> previous = length_to_mini;
      for (int i = 0; i < NUMS_LENGTH; i++) {
        if (previous[i] == INF) {
          break;
        }
        if (previous[i] < num && num < previous[i + 1]) {
          length_to_mini[i + 1] = num;
        }
      }
    }
    int ans = 1;
    for (int i = 1; i <= NUMS_LENGTH && length_to_mini[i] != INF; i++) {
      ans = i;
    }
    return ans;
  }
};