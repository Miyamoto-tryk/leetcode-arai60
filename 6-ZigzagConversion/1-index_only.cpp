#include <algorithm>
#include <string>
#include <vector>
using namespace std;
class Solution {
 public:
  string convert(string s, int numRows) {
    string result = "";
    for (int row = 0; row < numRows; row++) {
      const int MOD = max(1, numRows + numRows - 2);
      int index = row;
      bool is_rising = false;
      while (index < s.size()) {
        result += s[index];
        int distance_to_next_top = MOD - index % MOD;
        if (is_rising || row == numRows - 1) {
          index += distance_to_next_top + row;
          is_rising = false;
        } else {
          index += distance_to_next_top - row;
          is_rising = true;
        }
      }
    }
    return result;
  }
};