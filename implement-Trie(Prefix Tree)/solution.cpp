// 208. Implement Trie (Prefix Tree)

// Problem statement:

/*
A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

Trie() Initializes the trie object.
void insert(String word) Inserts the string word into the trie.
boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.

*/ 

// Understand the problem first:

// Hme trie data structur ko implement krna hy aur khud se kuch operation bi likhne like searchin, insertion, and startsWith.

// Approach and Solution:

// Iske liye approach nahi hy bs apko pta hona chahie ke trie data structure kia hy aur is ke kia operations hy aur kis trah kaam krte hy. It's not a difficult problem. Just make sure to grab theory of this topic trie/prefix trees.

// class Trie {
// public:
//     struct TrieNode {
//         TrieNode* nodes[26];
//         bool isEndOfWord;
//     };

//     TrieNode* createNode() {
//         TrieNode* newNode = new TrieNode();

//         for (int i = 0; i < 26; i++) {
//             newNode->nodes[i] = NULL;
//         }

//         newNode->isEndOfWord = false;
//         return newNode;
//     };

//     TrieNode* root;

//     Trie() { root = createNode(); }

//     void insert(string word) {
//         TrieNode* crawler = root;

//         for (int i = 0; i < word.length(); i++) {
//             int index = word[i] - 'a';
//             // if not found then insert index otherwise don't add again
//             // Note:- We are not inserting a character just index of that char
//             if (crawler->nodes[index] == NULL) {
//                 crawler->nodes[index] = createNode();
//             }
//             // move crawler
//             crawler = crawler->nodes[index];
//         }
//         // mark the word as completed
//         crawler->isEndOfWord = true;
//     }

//     bool search(string word) {
//         TrieNode* crawler = root;

//         for (int i = 0; i < word.length(); i++) {
//             int index = word[i] - 'a';
//             if (crawler->nodes[index] == NULL) {
//                 return false;
//             }
//             // move crawler
//             crawler = crawler->nodes[index];
//         }

//         if (crawler != NULL && crawler->isEndOfWord == true) {
//             return true;
//         }

//         return false;
//     }

//     bool startsWith(string prefix) {
//         TrieNode* crawler = root;

//         int i = 0;
//         for (i = 0; i < prefix.length(); i++) {
//             int index = prefix[i] - 'a';
//             if (crawler->nodes[index] == NULL) {
//                 return false;
//             }
//             // move crawler
//             crawler = crawler->nodes[index];
//         }

//         if (i == prefix.length()) {
//             return true;
//         }

//         return false;
//     }
// };

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
