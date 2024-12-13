#include <iostream>
#include <map>

int main() {
    // 数字字典
    std::map<char, int> num_dict;
    num_dict['0'] = 0;
    num_dict['1'] = 0;
    num_dict['2'] = 0;
    num_dict['3'] = 0;
    num_dict['4'] = 0;
    num_dict['5'] = 0;
    num_dict['6'] = 0;
    num_dict['7'] = 0;
    num_dict['8'] = 0;
    num_dict['9'] = 0;
    // 输入数字字符串
    std::string num_str;
    std::cin >> num_str;
    // 统计数字出现次数
    char recent_num = num_str[0];
    num_dict[recent_num] = 1;
    if (num_str.size() == 1) {
        std::cout << num_dict[recent_num] << recent_num;
        return 0;
    }
    for (int i = 1; i < num_str.size(); i++) {
        if (num_str[i] == recent_num) {
            num_dict[recent_num]++;
            recent_num = num_str[i];
        } else {
            std::cout << num_dict[recent_num] << recent_num;
            num_dict[recent_num] = 0;
            recent_num = num_str[i];
            num_dict[recent_num] = 1;
        }
    }
    std::cout << num_dict[recent_num] << recent_num;
    return 0;
}