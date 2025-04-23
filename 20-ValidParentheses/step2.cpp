#include <map>
#include <stack>
#include <string>
class Solution {
 public:
  bool isValid(std::string s) {
    std::stack<char> remaining_parentheses;
    std::map<char, char> matching_of_close_parenthesis = {{')', '('}, {'}', '{'}, {']', '['}};
    for (char parenthesis : s) {
      if (parenthesis == '(' || parenthesis == '{' || parenthesis == '[') {
        remaining_parentheses.push(parenthesis);
      } else {  // close parenthesis
        if (remaining_parentheses.empty()) return false;
        if (remaining_parentheses.top() != matching_of_close_parenthesis[parenthesis]) return false;
        remaining_parentheses.pop();
      }
    }
    if (!remaining_parentheses.empty()) return false;
    return true;
  }
};
