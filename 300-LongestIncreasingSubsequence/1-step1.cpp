#include <vector>
using namespace std;
class Solution {
 public:
  int lengthOfLIS(vector<int>& nums) {
    const int kLengthOfNums = nums.size();
    vector<int> length_to_mini(kLengthOfNums + 1, 1e5);
    length_to_mini[0] = -1e5;
    for (int num : nums) {
      vector<int> prev = length_to_mini;
      for (int i = 1; i < kLengthOfNums + 1; i++) {
        if (prev[i - 1] < num) {
          if (num < prev[i]) {
            length_to_mini[i] = num;
          }
        }
      }
    }
    int _min = 1;
    for (int i = 0; i < kLengthOfNums + 1; i++) {
      if (length_to_mini[i] == 1e5) {
        break;
      }
      _min = i;
    }
    return _min;
  }
};
