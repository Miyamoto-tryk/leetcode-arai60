
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    map<int, int> map;
    for (int i = 0; i < nums.size(); i++) {
      int rest = target - nums[i];
      if (map.contains(rest)) {
        return {map[rest], i};
      }
      map[nums[i]] = i;
    }
    return {0, 0};
  }
};