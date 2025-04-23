#include <map>
#include <stack>
#include <string>
class Solution {
 public:
  bool isValid(std::string s) {
    static const std::map<char, char> kOpenToClose = {{'(', ')'}, {'{', '}'}, {'[', ']'}};
    std::stack<char> open_brackets;
    for (char bracket : s) {
      if (kOpenToClose.contains(bracket)) {
        open_brackets.push(bracket);
        continue;
      }
      if (open_brackets.empty()) {
        return false;
      }
      if (bracket != kOpenToClose.at(open_brackets.top())) {
        return false;
      }
      open_brackets.pop();
    }
    return open_brackets.empty();
  }
};