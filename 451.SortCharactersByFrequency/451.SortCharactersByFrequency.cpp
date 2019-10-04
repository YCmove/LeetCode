#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// leetcode solution
class Solution {
public:
    string frequencySort(string s) {

        // 用unordered_map紀錄每個char出現的次數
        unordered_map<char,int> freq;

        // 建立一個儲存string的vector, 初始化為
        // Constructs a vector with s.size()+1 elements with the empty string.
        // 用vector的index來代表char出現的次數，並把char一個個append上empty string
        // 長度為5的input string, 同一個字母最多出現5次, index = 5時此vector長度為6
        // , 故vector建立時長度須為 size() + 1 
        vector<string> bucket(s.size()+1, ""); // frequency bucket
        string res;
        
        //count frequency of each character
        for(char c:s) freq[c]++;


        //put character into frequency bucket
        for(auto& it:freq) {
            int n = it.second;
            char c = it.first;
            bucket[n].append(n, c);
        }

        //form descending sorted string
        for(int i=s.size(); i>0; i--) {
            if(!bucket[i].empty())
                res.append(bucket[i]);
        }
        return res;
    }
};


class mySolution {
public:
    string frequencySort(string s)
    {
        unordered_map<char, int> unorder_map;
        vector<string> freq_index_bucket(s.size() + 1 ,"");

        for (auto &it : s)
        {
            unorder_map[it]++;
        }

        for (auto const & pair: unorder_map){
            // cout << "key: " << pair.first << " / value: " << pair.second << endl;
            // char 出現頻率當作key
            // 因為 vector的 mamber 已經初始過(empty string)
            // 所以這一步可以直接append
            char c = pair.first;
            char count = pair.second;
            // Notice: append的用法，在此為append上n個char
            freq_index_bucket[pair.second].append(count, c);
        }

        string result;
        vector<string>::reverse_iterator rit;
        for (rit = freq_index_bucket.rbegin(); rit != freq_index_bucket.rend(); rit++)
        {
            if (!(*rit).empty())
            {
                result.append(*rit);
            }
        }

        return result;
    }
};

int main(){

    // string s = "qcbkrbolomdwttlhqbldbuscinrsjrvmhjltvplkilimtfpkllobenptthmxfpfdiqrqjfbowklsnqvgfqaitsavhgraicmnvfklodarkcdikfocgxkrotwdubpuadbmerhlsrxdslrnamkwokedviqksjhtpsvpplxioxwsivnjrfiknxvwjqxmroawtxpxuntldepqlhwmmaahdxosiecqjqdmorqdvfklhkhukcvoqmdeajoqmndglphvpchtbmnadpjhhxrixdbcepwpdbxhfkfcgqvqqsmdqelijlksqtrhqpfxpqakadvrsmcrkpwtvanpibscdnufkcurgegxvigvvovwhdmabvqnmqxsqacueiddsdqxksrtgvhxhnftgrmanhrjhokcejbqchxjrbffftpncgsllnqktxbqanmbufonowkfamdckoghagdaqjudgaxvtoritlmmoasejeclgxdwbnxlnnscokkdirrqamiujphfdclghwpindgkjqxpmndxxolanjngrkaageffgtsxnpraxuwcgijtanqarhrjwawwclratfldpcasuhvufmngunxjmjunwcqopwxvpvkdvuccjsemcrwqbpbboghskihqfpogitihffqpwnusupfkjlvlxvkrcscmeexlqxfpbfbrlhnxkwjdkbmuhpejoxctugbknratxmwbjsgsovdlwjggougcxjounvvvbjsujjxwgeidhollucsifehvtopphjlelglswflqeosdmhicdvbkcoqjehnvljrnljclgacajifaxrdanskfwuaoathnxossakxjjsgnxkrvhddnrrgqceanjmwquqmkebltpkuxulnhmxbsxcedmpafoarmtpqggggcikpxkfraglfghvvhwnxgwbbtllvnwihuuifmiooxfiwkjjblhvnjlfnutemxeqhmdvwgwpuubgunfhphorlfuvoqvremqonxfjdgepk";
    string s = "VVBVNKKKNN";
    mySolution sol;
    cout << sol.frequencySort(s) << endl;
    ;

    return 0;
}