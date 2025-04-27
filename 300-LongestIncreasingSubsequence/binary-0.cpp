#include <algorithm>
#include <vector>
using namespace std;
class Solution {
 public:
  int lengthOfLIS(vector<int>& nums) {
    vector<int> tails;
    for (int num : nums) {
      auto upper = upper_bound(tails.begin(), tails.end(), num - 1);
      if (upper == tails.end()) {
        tails.push_back(num);
        continue;
      }
      *upper = num;
    }
    return tails.size();
  }
};