#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int i, j;
        for (i = 0, j = s.size()-1; i < s.size(), i < j; i++, j--)
        {
            // cout << s[i] << " ";
            // cout << s[i] << " / isalnum: " << isalnum(s[i]) << endl;
            while (isalnum(s[i]) == false && i < j) {
                i++;
            }
            while (isalnum(s[j]) == false && i < j) {
                j--;
            }

            if (tolower(s[i]) != tolower(s[j])){
                return false;
            }
        }
        return true;
    }
};


int main(){

    // string str = "hello";
    string str = "A man, a plan, a canal: Panama";
    Solution s;
    cout << s.isPalindrome(str) << endl;

}