#include <map>
#include <vector>

using namespace std;
class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    map<int, int> num_to_index;
    for (int index = 0; index < nums.size(); index++) {
      int num = nums[index];
      int rest_num = target - num;
      if (num_to_index.contains(rest_num)) {
        return {num_to_index[rest_num], index};
      }
      num_to_index[num] = index;
    }
    return {-1, -1};
  }
};