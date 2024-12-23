#include <iostream>
#include <stack>
#include <vector>

std::string s;

bool is_matched(char a, char b) {
    return (a == '(' && b == ')') || (a == '[' && b == ']');
}

int main() {
    std::cin >> s;
    int n = s.size();
    std::vector<bool> matched(n+1, false);
    std::stack<int> st_index;

    for (int i = 0; i < n; i++) {
        if (s[i] == '[' || s[i] == '(') {
            st_index.push(i);
        } else if (!st_index.empty() && is_matched(s[st_index.top()], s[i])) {
            matched[i] = true;
            matched[st_index.top()] = true;
            st_index.pop();
        } else {
            st_index.push(i);
        }
    }

    int max_length = 0;
    int max_start = 0;
    int length = 0;
    int start = 0;
    for (int i = 0; i < n+1; i++) {
        if (matched[i]) {
            length++;
        } else {
            if (length > max_length) {
                max_length = length;
                max_start = start;
            }
            length = 0;
            start = i + 1;
        }
    }

    for (int i = max_start; i < max_start + max_length; i++) {
        std::cout << s[i];
    }

    return 0;
}