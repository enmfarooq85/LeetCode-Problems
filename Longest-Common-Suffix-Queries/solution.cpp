// 3093. Longest Common Suffix Queries

/*
You are given two arrays of strings wordsContainer and wordsQuery.

For each wordsQuery[i], you need to find a string from wordsContainer that has the longest common suffix with wordsQuery[i]. If there are two or more strings in wordsContainer that share the longest common suffix, find the string that is the smallest in length. If there are two or more such strings that have the same smallest length, find the one that occurred earlier in wordsContainer.

Return an array of integers ans, where ans[i] is the index of the string in wordsContainer that has the longest common suffix with wordsQuery[i].
*/

// Understand the problem first:

// hme do array of string dia hue hy aur hme longest common suffix nikalna hy wordscontainer se.

// Approach and Solution:

// First of all ye tough nahi hy blke iski implementation tough hy. Inshallah, baqi ap khud pade ge tu apko problem ki smjh lg jaye gi. Trie approach me apko memory ka bada khyal rakhna pade ga.

// class Solution {
// public:
//     vector<int> stringIndices(vector<string>& wordsContainer,
//                               vector<string>& wordsQuery) {

//         int wordsCL = wordsContainer.size();
//         int wordsQL = wordsQuery.size();
//         vector<int> ans;

//         for (int wordQ = 0; wordQ < wordsQL; wordQ++) {
//             string query = wordsQuery[wordQ];
//             int bestSuffixLength = 0;
//             int bestIndex = 0;
//             int bestContainerLength = INT_MAX;

//             for (int wordC = 0; wordC < wordsCL; wordC++) {
//                 string container = wordsContainer[wordC];

//                 int qIndex = query.length() - 1;
//                 int cIndex = container.length() - 1;
//                 int suffixLength = 0;

//                 while (qIndex >= 0 && cIndex >= 0 &&
//                        query[qIndex] == container[cIndex]) {

//                     suffixLength++;

//                     qIndex--;
//                     cIndex--;
//                 }

//                 if (suffixLength > bestSuffixLength) {
//                     bestSuffixLength = suffixLength;
//                     bestContainerLength = container.length();
//                     bestIndex = wordC;
//                 } else if (suffixLength == bestSuffixLength) {
//                     if (container.length() < bestContainerLength) {
//                         bestContainerLength = container.length();
//                         bestIndex = wordC;
//                     }
//                 }
//             }

//             ans.push_back(bestIndex);
//         }

//         return ans;
//     }
// };

// class Solution {
// public:

//     struct TrieNode {
//         int idx;
//         TrieNode* children[26];

//         TrieNode(int index) {
//             idx = index;

//             for (int i = 0; i < 26; i++) {
//                 children[i] = nullptr;
//             }
//         }

//         ~TrieNode() {
//             for (int i = 0; i < 26; i++) {
//                 delete children[i];
//             }
//         }
//     };

//     void insert(TrieNode* root, int index, vector<string>& words) {
//         TrieNode* crawl = root;
//         int len = words[index].size();

//         for (int i = len - 1; i >= 0; i--) {

//             int ch = words[index][i] - 'a';

//             if (crawl->children[ch] == nullptr) {
//                 crawl->children[ch] = new TrieNode(index);
//             }

//             crawl = crawl->children[ch];

//             // Keep shortest word index
//             if (words[crawl->idx].size() > len) {
//                 crawl->idx = index;
//             }
//         }
//     }

//     int search(TrieNode* root, string& word) {
//         TrieNode* crawl = root;

//         // Best answer if no suffix matches
//         int result = root->idx;

//         for (int i = word.size() - 1; i >= 0; i--) {

//             int ch = word[i] - 'a';

//             if (crawl->children[ch] == nullptr) {
//                 break;
//             }

//             crawl = crawl->children[ch];

//             result = crawl->idx;
//         }

//         return result;
//     }

//     vector<int> stringIndices(
//         vector<string>& wordsContainer,
//         vector<string>& wordsQuery
//     ) {
//         TrieNode* root = new TrieNode(0);

//         // Find shortest container word.
//         // This is the default answer when no suffix matches.
//         for (int i = 1; i < wordsContainer.size(); i++) {

//             if (wordsContainer[i].size() <
//                 wordsContainer[root->idx].size()) {

//                 root->idx = i;
//             }
//         }

//         // Build reverse Trie
//         for (int i = 0; i < wordsContainer.size(); i++) {
//             insert(root, i, wordsContainer);
//         }

//         // Answer queries
//         vector<int> result;

//         for (string& query : wordsQuery) {
//             result.push_back(search(root, query));
//         }

//         delete root;

//         return result;
//     }
// };
