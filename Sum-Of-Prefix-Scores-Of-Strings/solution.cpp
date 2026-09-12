// 2416. Sum of Prefix Scores of Strings

// Problem statement:

/* 
You are given an array words of size n consisting of non-empty strings.

We define the score of a string term as the number of strings words[i] such that term is a prefix of words[i].

For example, if words = ["a", "ab", "abc", "cab"], then the score of "ab" is 2, since "ab" is a prefix of both "ab" and "abc".
Return an array answer of size n where answer[i] is the sum of scores of every non-empty prefix of words[i].

Note that a string is considered as a prefix of itself.
*/

// Understand the problem first:

// hme aik words of string array dia hui hy hum logo ne hr word ke possible prefixes nikalne hy aur then pir un prefixes ko find krna hy ke kaha kaha hy aur agr aik bar words array me aik mrtaba as a prefix mila tu aik score othewiwse jitni mrtaba mila utna score. aur then pir us word ke total prefixes ka score us word ka score ho ga. Ye thoda sa confusing part hy question but agr thoda ghor se question ko read kre tu i think mushkil nahi hy.

// Approach and solution:

// Sb se pehle brute force se solve krte hy tu ye TLE de ga. Ab ye buht detail baat ho jaye gi ke kyu trie approach hi. But in short hme prefixes ke count asal me dekhne hy tu isliye trieNode me sath sath preifxes count bi maintain kre ge.

// class Solution {
// public:
//     vector<int> sumPrefixScores(vector<string>& words) {
//         vector<string> terms;
//         vector<int> ans;

//         for (int word = 0; word < words.size(); word++) {
//             for (int ch = 0; ch < words[word].size(); ch++) {
//                 terms.push_back(words[word].substr(0, ch + 1));
//             }

//             int score = 0;
//             for (int term = 0; term < terms.size(); term++) {
//                 for (int word = 0; word < words.size(); word++) {
//                     for (int ch = 0; ch < words[word].size(); ch++) {
//                         if (terms[term] == words[word].substr(0, ch + 1)) {
//                             score += 1;
//                         }
//                     }
//                 }
//             }

//             ans.push_back(score);
//             terms.clear();
//         }

//         return ans;
//     }
// };

// class Solution {
// public:
//     struct TrieNode {
//         TrieNode* children[26];
//         int countP = 0;
//     };

//     TrieNode* createTrieNode() {
//         TrieNode* newNode = new TrieNode();
//         for (int i = 0; i < 26; i++) {
//             newNode->children[i] = nullptr;
//         }
    
//         newNode->countP = 0;
//         return newNode;
//     }

//     void insert(string& word, TrieNode* root) {
//         TrieNode* crawl = root;

//         for (char& ch : word) {
//             int idx = ch - 'a';

//             if (!crawl->children[idx]) {
//                 crawl->children[idx] = createTrieNode();
//             }

//             crawl->children[idx]->countP += 1;
//             crawl = crawl->children[idx];
//         }
//     }

//     int getScore(string& word, TrieNode* root) {
//         TrieNode* crawl = root; //"abc"
//         int score = 0;

//         for (char& ch : word) {
//             int idx = ch - 'a';
//             score += crawl->children[idx]->countP;

//             crawl = crawl->children[idx];
//         }

//         return score;
//     }

//     vector<int> sumPrefixScores(vector<string>& words) {
//         int n = words.size();

//         TrieNode* root = createTrieNode();
//         for (string& word : words) {
//             insert(word, root);
//         }

//         vector<int> result(n);
//         for (int i = 0; i < n; i++) {
//             result[i] = getScore(words[i], root);
//         }

//         return result;
//     }
// };
