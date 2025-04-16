#include <map>
#include <stack>
#include <string>

class Solution {
 public:
  bool isValid(std::string s) {
    std::stack<char> open_brackets;
    for (char bracket : s) {
      if (OPEN_TO_CLOSE.contains(bracket)) {
        open_brackets.push(bracket);
        continue;
      }
      if (open_brackets.empty()) return false;
      if (bracket != OPEN_TO_CLOSE.at(open_brackets.top())) return false;
      open_brackets.pop();
    }
    return open_brackets.empty();
  }

 private:
  static const std::map<char, char> OPEN_TO_CLOSE;
};
const std::map<char, char> Solution::OPEN_TO_CLOSE = {{'(', ')'}, {'[', ']'}, {'{', '}'}};
