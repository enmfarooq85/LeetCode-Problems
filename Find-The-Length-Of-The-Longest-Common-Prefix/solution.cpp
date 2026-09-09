// 3043. Find the Length of the Longest Common Prefix

// Problem statement:

/*
You are given two arrays with positive integers arr1 and arr2. A prefix of a positive integer is an integer formed by one or more of its digits, starting from its leftmost digit. For example, 123 is a prefix of the integer 12345, while 234 is not. A common prefix of two integers a and b is an integer c, such that c is a prefix of both a and b. For example, 5655359 and 56554 have common prefixes 565 and 5655 while 1223 and 43456 do not have a common prefix. You need to find the length of the longest common prefix between all pairs of integers (x, y) such that x belongs to arr1 and y belongs to arr2. Return the length of the longest common prefix among all pairs. If no common prefix exists among them, return 0.
*/

// Understand the problem first:

// hme do arrays of integer dia gaye hy arr1 aur arr2 ke name se. Hume ne longest prefix dondna hy arr1 se.

// Approach and Solution:

// sb se pehle problem ki smaje aur hme kaha gia hy ke hr possible pair ka prefix dondna hy tu hum log simply nested loop lga ke possible pair uta le ge aur then pir aik helper function me two pointer approach lga ge dekh le ge ke longest common prefix kia hy. Lekin ye approach TLE de ge. Dosri ye hy ke hum log set me arr1 ke possible prefix dal de aur then arr2 ke possible prefix nikal ke length calculate kr le aur last pe return kr de max length. Teesri approach ye hy ke hum log trie se solve kre simply trie me arr1 ko dal de ge aur then pir search kr le ge arr2 ko trie me. Trie approach ke liye apko Trie ke basics operations ka pta hona chahie.

// class Solution {
// public:
//     int findCommonPrefix(int a1, int a2) {
//         string str1 = to_string(a1);
//         string str2 = to_string(a2);

//         int i = 0;
//         int j = 0;
//         int count = 0;

//         while (i < str1.length() && j < str2.length()) {
//             if (str1[i] != str2[j]) {
//                 return count;
//             };

//             if (str1[i] == str2[j]) {
//                 count += 1;
//             }

//             i++;
//             j++;
//         }

//         return count;
//     };

//     int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
//         int maxPrefix = INT_MIN;
//         for (int i = 0; i < arr1.size(); i++) {
//             for (int j = 0; j < arr2.size(); j++) {
//                 int prefix = findCommonPrefix(arr1[i], arr2[j]);
//                 if (prefix > maxPrefix) {
//                     maxPrefix = prefix;
//                 }
//             }
//         }

//         return maxPrefix;
//     }
// };

// class Solution {
// public:
//     int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
//         unordered_set<int> st;

//         for (int num1 : arr1) {
//             while (!st.count(num1) && num1 > 0) {
//                 st.insert(num1);
//                 num1 /= 10;
//             }
//         };

//         int result = 0;
//         for (int num2 : arr2) {
//             while (!st.count(num2) && num2 > 0) {
//                 num2 /= 10;
//             }

//             if (num2 > 0) {
//                 result = max(result, static_cast<int>(log10(num2) + 1));
//             }
//         }

//         return result;
//     }
// };

// class Solution {
// public:
//     // we don't need here traditional isEndOfWord property of TrieNode
//     // we are dealing with the numbers that are from 0 to 9
//     struct TrieNode {
//         TrieNode* children[10];
//     };

//     TrieNode* createTrieNode() {
//         TrieNode* node = new TrieNode();

//         for (int i = 0; i < 10; i++) {
//             node->children[i] = NULL;
//         }

//         return node;
//     }

//     void insert(int num, TrieNode* root) {
//         TrieNode* crawl = root;
//         string numStr = to_string(num);

//         for (char ch : numStr) {
//             int idx = ch - '0';
//             if (!crawl->children[idx]) {
//                 crawl->children[idx] = createTrieNode();
//             }

//             crawl = crawl->children[idx];
//         }
//     }

//     int search(int num, TrieNode* root) {
//         TrieNode* crawl = root;
//         string numStr = to_string(num);
//         int length = 0;

//         for (char ch : numStr) {
//             int idx = ch - '0';
//             if (!crawl->children[idx]) {
//                 break;
//             }

//             if (crawl->children[idx]) {
//                 length++;
//                 crawl = crawl->children[idx];
//             }
//         }

//         return length;
//     }

//     int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
//         TrieNode* root = createTrieNode();

//         for (int num : arr1) {
//             insert(num, root);
//         }

//         int result = 0;
//         for (int num : arr2) {
//             result = max(result, search(num, root));
//         }

//         return result;
//     }
// };
