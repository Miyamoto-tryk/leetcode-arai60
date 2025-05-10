#include <algorithm>
#include <string>
#include <vector>
using namespace std;
class Solution {
 public:
  string convert(string s, int numRows) {
    vector<string> zigzag_array(numRows, "");
    const int MOD = max(numRows + (numRows - 2), 1);
    for (int i = 0; i < s.size(); i++) {
      int row = i % MOD;
      if (row >= numRows) {
        row = MOD - row;
      }
      zigzag_array[row] += s[i];
    }
    string result = "";
    for (string line : zigzag_array) {
      result += line;
    }
    return result;
  }
};