#include <algorithm>
#include <string>
#include <vector>
using namespace std;
class Solution {
 public:
  string convert(string s, int numRows) {
    vector<string> conversion_array(numRows, "");
    const int kTopToNextTop = max((numRows - 1) * 2, 1);
    for (int i = 0; i < s.size(); i++) {
      int row = i % kTopToNextTop;
      if (row >= numRows) {
        row = kTopToNextTop - row;
      }
      conversion_array[row] += s[i];
    }
    string result = "";
    for (string str_line : conversion_array) {
      result += str_line;
    }
    return result;
  }
};