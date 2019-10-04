#include <iostream>
#include <limits.h>

using namespace std;


class Solution {
public:
    bool isPalindrome(int x) {

        if (x < 0){
            // -1 is not 1-
            return false;
        }

        int origin = x;

        long long reversed = 0;
        int reminder = 0;
        while (x > 0){
            reminder = x % 10;
            reversed = reversed * 10 + reminder;
            x /= 10;
            // cout << "reversed: " << reversed << endl;
        }
        // cout << "reversed: " << reversed << endl;

        if (origin == reversed && x < INT_MAX){
            return true;
        }
        return false;
    }
};

int main(){

    int num = 121;
    Solution s;
    cout << s.isPalindrome(num) << endl;

}