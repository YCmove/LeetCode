#include <iostream>
#include <vector>
#include <string>

using namespace std;

// reference: https://leetcode.com/problems/letter-combinations-of-a-phone-number/discuss/8479/0ms-(less-than-1ms)-C%2B%2B-Solution


void print_vec(vector<string> vec){
    for (auto it = vec.begin(); it != vec.end(); it++){
        cout << *it << ", ";
    }
    cout << endl;
}


class Solution {
public:
    string letter[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void letterCombinations(string digits) {
    // vector<string> letterCombinations(string digits) {
        for (auto it = digits.begin(); it != digits.end(); it++){
            cout << *it << " ";
        }
    }

};


int main(){

    string input_str;
    vector<string> output;
    Solution s;

    input_str = "23";
    s.letterCombinations(input_str);
    // output = s.letterCombinations(input_str);
    // output.push_back(input_str);
    // output.push_back(input_str);
    // output.push_back(input_str);
    // output.push_back(input_str);
    // print_vec(output);
    // cout <<  << endl;

    return 0;
}