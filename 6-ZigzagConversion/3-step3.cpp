#include <string>
#include <vector>

using namespace std;
class Solution {
 public:
  string convert(string s, int numRows) {
    if (s.size() < numRows || numRows == 1) {
      return s;
    }
    vector<string> convert_array(numRows);
    int row = 0;
    bool is_rising = false;
    for (char c : s) {
      convert_array[row] += c;
      if (row == 0) {
        is_rising = false;
      } else if (row == numRows - 1) {
        is_rising = true;
      }
      row += is_rising ? -1 : 1;
    }
    string result;
    result.reserve(s.size());
    for (auto& line : convert_array) {
      result += line;
    }
    return result;
  }
};