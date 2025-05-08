#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

class Solution {
 public:
  int lengthOfLIS(vector<int>& nums) {
    vector<int> length_to_min_last_num;
    for (int num : nums) {
      // 末尾の最小値をnumに更新できるlength
      auto new_LIS_itr =
          upper_bound(length_to_min_last_num.begin(), length_to_min_last_num.end(), num - 1);
      if (new_LIS_itr == length_to_min_last_num.end()) {
        length_to_min_last_num.push_back(num);
        continue;
      }
      *new_LIS_itr = num;
    }
    return length_to_min_last_num.size();
  }
};