#include <iostream>
int n, k;
std::string s;

int main() {
    std::cin >> n >> k >> s;
    // 统计大小写字母、数字是否存在
    bool exist[128] = {false};
    for (int i = 0; i <= n-k; i++) {
        exist[s[i]] = true;
    }
    std::string output;
    for (int i = n-k+1; i < n; i++) {
        if (exist[s[i]]) {
            output += s[i];
            output += "\n";
        } else {
            std::cout << -1 << std::endl;
            return 0;
        }
    }
    std::cout << k << std::endl;
    std::cout << s.substr(0,n-k+1) << std::endl;
    std::cout << output << std::endl;
    return 0;
}