
#include <map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    map<int, int> value_to_index;
    for (int index = 0; index < nums.size(); index++) {
      int value = nums[index];
      int rest_value = target - value;
      if (value_to_index.contains(rest_value)) {
        return {value_to_index[rest_value], index};
      }
      value_to_index[value] = index;
    }
    return {-1, -1};
  }
};