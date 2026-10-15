// 1647. Minimum Deletions to Make Character Frequencies Unique

// Problem statement:

// A string s is called good if there are no two different characters in s that have the same frequency. Given a string s, return the minimum number of characters you need to delete to make s good. The frequency of a character in a string is the number of times it appears in the string. For example, in the string "aab", the frequency of 'a' is 2, while the frequency of 'b' is 1.

// Understand the problem first:

// Hme aik string s dia gia jaye ga aur hme usko good string bnana hy aik good string ki defination ye y ke us tmam characters ki frequency unique ho gi. Aur hme string ko minimum operations lga ke aik acha string bnana hy.

// Approach and Solution:

// Approach simple hy ke ap log iska hashtable bnae aur then pir sort kr le descending order me ta ke hum log sb se pehle bade walo ko thode ta ke minimum operations lge. Ye aik greedy approach hy.

// class Solution {
// public:
//     int minDeletions(string s) {
//         unordered_map<char, int> mp;

//         for (char& ch : s) {
//             mp[ch]++;
//         }

//         vector<pair<int, char>> freqChar;

//         for (const auto& [key, val] : mp) {
//             freqChar.push_back({val, key});
//         };

//         sort(begin(freqChar), end(freqChar), greater<>());

//         int n = freqChar.size();
//         int opts = 0;

//         for (int i = 0; i < n; i++) {
//             int firstI = freqChar[i].first;

//             if(firstI == 0){
//                 continue;
//             }

//             for (int j = i + 1; j < n; j++) {
//                 int firstJ = freqChar[j].first;

//                 if (firstI == firstJ){
//                     freqChar[j].first -=1;
//                     opts++;
//                 }
//             }
//         }

//         return opts;
//     }
// };
