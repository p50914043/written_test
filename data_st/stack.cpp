#include <iostream>
#include <stack>
#include <vector>

// 有效括号
// 思路：使用栈，遍历字符串，遇到左括号入栈，遇到右括号出栈，判断是否匹配
bool isValid(std::string s) {
  std::stack<char> stack;
  for (auto c : s) {
    if (c == '(' || c == '[' || c == '{') {
      stack.push(c);
    } else {
      if (stack.empty()) {
        return false;
      }
      char top = stack.top();
      stack.pop();
      if ((c == ')' && top != '(') || (c == ']' && top != '[') || (c == '}' && top != '{')) {
        return false;
      }
    }
  }
  return stack.empty();
}

// 最小栈:
// 思路：使用两个栈，一个栈正常入栈出栈，另一个栈只入栈当前元素和当前栈顶元素的较小值
class MinStack {
 public:
  MinStack() {
  }

  void push(int x) {
    if (stack.empty()) {
      stack.push(x);
      minStack.push(x);
    } else {
      stack.push(x);
      minStack.push(std::min(x, minStack.top()));
    }
  }

  void pop() {
    stack.pop();
    minStack.pop();
  }
  int top() {
    return stack.top();
  }

  int getMin() {
    return minStack.top();
  }

 private:
  std::stack<int> stack;
  std::stack<int> minStack;
};

// 接雨水
// 思路：使用单调栈，遍历数组，如果栈为空或者当前元素小于栈顶元素，则入栈，否则，计算当前元素和栈顶元素的高度差，并计算宽度，并出栈，直到栈为空或者当前元素大于栈顶元素，然后将当前元素入栈
// 时间复杂度：O(n)
int trap(std::vector<int>& height) {
  int n = height.size();
  if (n <= 2) {
    return 0;
  }
  std::stack<int> stack;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    while (!stack.empty() && height[stack.top()] < height[i]) {  // 栈顶元素小于当前元素,
      int top = stack.top();
      stack.pop();
      if (stack.empty()) {
        break;
      }
      int left = stack.top();
      int h = std::min(height[i], height[left]) - height[top];  // 需要三根柱子才能接雨水
      int w = i - left - 1;
      ans += h * w;
    }
    stack.push(i);
  }
  return ans;
}

int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}