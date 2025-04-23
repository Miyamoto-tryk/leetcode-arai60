#include <map>
#include <stack>
#include <string>
class Solution {
 public:
  bool isValid(std::string s) {
    std::stack<char> remaining_parentheses;
    std::map<char, char> matching_parentheses = {{')', '('}, {'}', '{'}, {']', '['}};
    for (char parentheses : s) {
      if (parentheses == '(' || parentheses == '{' || parentheses == '[') {
        remaining_parentheses.push(parentheses);
      } else {
        if (!remaining_parentheses.empty()) {
          if (remaining_parentheses.top() == matching_parentheses[parentheses]) {
            remaining_parentheses.pop();
          } else return false;
        } else return false;
      }
    }
    if (remaining_parentheses.empty()) return true;
    else return false;
  }
};
