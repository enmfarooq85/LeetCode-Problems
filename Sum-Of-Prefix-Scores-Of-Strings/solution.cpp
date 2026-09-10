// 2416. Sum of Prefix Scores of Strings

// Problem statement:

// 

// Understand the problem first:

// 

// Approach and solution:

// kl subh


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
