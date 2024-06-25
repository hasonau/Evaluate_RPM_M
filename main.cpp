#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <stdexcept>
using namespace std;

class Solution {
private:
    stack<int> s;

public:
    int evalRPN(vector<string>& tokens) {
        for (string s1 : tokens) {
            try {
                int save = stoi(s1);
                s.push(save);
            } catch (const invalid_argument& e) {
                char a = s1[0];
                int save1 = s.top();
                s.pop();
                int save2 = s.top();
                s.pop();
                if (a == 43 || a == 42) {
                    if (a == 43) {
                        int save3 = save2 + save1;
                        s.push(save3);
                    } else {
                        int save3 = save2 * save1;
                        s.push(save3);
                    }
                } else if (a == 45) {
                    int save3 = save2 - save1;
                    s.push(save3);
                } else {
                    int save3 = save2 / save1;
                    s.push(save3);
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
