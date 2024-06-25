#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <stdexcept>
using namespace std;

class Solution {
private:
    std::stack<int> s;
public:
    int evalRPN(std::vector<std::string>& tokens) {
        for (std::string token : tokens) {
            try {
                int num = std::stoi(token);
                s.push(num);
            } catch (const std::invalid_argument& e) {
                char op = token[0];
                int operand2 = s.top(); s.pop();
                int operand1 = s.top(); s.pop();

                switch (op) {
                    case '+':
                        s.push(operand1 + operand2);
                        break;
                    case '-':
                        s.push(operand1 - operand2);
                        break;
                    case '*':
                        s.push(operand1 * operand2);
                        break;
                    case '/':
                        s.push(operand1 / operand2);
                        break;
                    default:
                        throw std::invalid_argument("Invalid operator: " + token);
                }
            }
        }
        return s.top();
    }
};

int main() {
    Solution solution;
    vector<string> tokens = {"2", "1", "+", "3", "*"};
    cout << "Result: " << solution.evalRPN(tokens) << endl;

    tokens = {"4", "13", "5", "/", "+"};
    cout << "Result: " << solution.evalRPN(tokens) << endl;

    tokens = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    cout << "Result: " << solution.evalRPN(tokens) << endl;

    return 0;
}
