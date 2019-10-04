#include <iostream>
#include <limits.h>

using namespace std;

class Solution {
public:
    long long reverse(long long x) {
        int reminder = 0;
        long long reverse_num = 0;

        bool flag = false;
        if (x < 0)
        {
            x = abs(x);
            flag = true;
        }

        while (x != 0){
            // cout << "1. x: " << x << endl;
            reminder = x % 10;
            reverse_num = reverse_num * 10 + reminder;
            x /= 10;
            // cout << "INT_MAX/10: " << INT_MAX/10 << endl;
            // cout << "2. x: "<< x << endl;
            // cout << "2. reverse_num: "<< reverse_num << "\n=========" << endl;
        }

        if (reverse_num > INT_MAX) {
            cout << "reverse_num: " << reverse_num << endl;
            cout << "INT_MAX: " << INT_MAX << endl;
            return 0;
        }
        if (flag)
            return -reverse_num;
        return reverse_num;
    }
};

int main(){

    // long long num = 1534236469;
    long long num = -2147483648;
    // long long num = -123;
    // long long num = 123;
    Solution s;
    cout << s.reverse(num) << endl;

    return 0;
}