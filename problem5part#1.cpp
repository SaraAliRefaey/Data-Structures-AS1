#include <iostream>
using namespace std;
#include <string>
#include <stack>

class ExpressionEvaluation {
private:
	stack <int> st;
    int number;
    int sign;
    int total;

public:
    ExpressionEvaluation() {
        number = 0;
        sign = 1;
        total = 0;
    }
    int evaluate(string s) {
        for (int i = 0; i < s.length(); i++) {

            if (s[i] == ' ') {
                continue;
            }
            if (isdigit(s[i])) {
                number = number * 10 + (s[i] - '0');
            }

            if (s[i] == '+' || s[i] == '-') {
                st.push(sign * number);
                number = 0;
                if (s[i] == '+') {
                    sign = 1;
                }
                else {
                    sign = -1;
                }
            }

            if (s[i] == '(') {
                st.push(sign);
                st.push(-999);
                sign = 1;
                continue;
            }
            if (s[i] == ')') {
                st.push(sign * number);
                number = 0;
                int sum = 0;

                while (!st.empty() && st.top() != -999) {
                    sum += st.top();
                    st.pop();
                }
                st.pop();
                int prevSign = st.top();
                st.pop();
                st.push(prevSign * sum);
                continue;
            }
        }
        st.push(sign * number);
        while (!st.empty()) {
            total += st.top();
            st.pop();
        }
        return total;
    }
    bool isValid(string s) {
        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                continue;
            }
            if (s[i] == '(') {
                count++;
            }
            else if (s[i] == ')') {
                count--;
                if (count < 0) {
                    return false;
                }
            }
            if(s[i]== '+')
            {
                if (i > 0 && s[i - 1] == '(')
                {
                    return false;
                }
                if (i==0){
                    return false;
				}
			}
            if (i < s.length() - 1) {
                if ((s[i] == '+' || s[i] == '-') && (s[i + 1] == '+' || s[i + 1] == '-')) {
                    return false;
                }
            }
        }
        return count == 0;
    }
};

int main() {
    string exp;
    cout << "Enter a expression: ";
    getline(cin, exp);
    ExpressionEvaluation evaluation;

    if(!evaluation.isValid(exp)) {
        cout << "Invalid expression" << endl;
        return 0;
	}
    int result = evaluation.evaluate(exp);
    cout << result << endl;
    return 0;
}
