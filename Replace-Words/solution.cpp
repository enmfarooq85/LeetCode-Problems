// 648. Replace Words

// Problem statement:

/*
In English, we have a concept called root, which can be followed by some other word to form another longer word - let's call this word derivative. For example, when the root "help" is followed by the word "ful", we can form a derivative "helpful".

Given a dictionary consisting of many roots and a sentence consisting of words separated by spaces, replace all the derivatives in the sentence with the root forming it. If a derivative can be replaced by more than one root, replace it with the root that has the shortest length.

Return the sentence after the replacement.
*/

// Understand the problem first:

// Hme aik vector of string dictionary dia hua hy aur aik sentence dia gia hy. Hme sentence dia gaye hy is me kuch ases words jo ke derive hoe hy dictinonary se. Hme simply sentence me un words ke replace krna hy jo ke apne derivatives se nikle hy. Agr koi do word aese mil gaye dictionary me jo ke aik hi word ke derivatives hy tu ap shortest wala chono ge. 

// Approach and Solution:

// Isko hum log trie se solve krne koshih kre ge. Iske liye apko just basics of trie pta hone chahie. Dosri approach ye hy ke hum log set me store me kr le dicotionary ko aur then o(1) time me access kr ke find kr le sentence ke aik aik word ko.

// #include "bits/stdc++.h"
// using namespace std;

// class Solution
// {
// public:
//     struct TrieNode
//     {
//         TrieNode *nodes[26];
//         bool isEndOfWord;
//     };

//     TrieNode *createNode()
//     {
//         TrieNode *newNode = new TrieNode();

//         for (int i = 0; i < 26; i++)
//         {
//             newNode->nodes[i] = NULL;
//         }

//         newNode->isEndOfWord = false;
//         return newNode;
//     };

//     TrieNode *root = createNode();

//     void insert(vector<string> &dictionary)
//     {
//         for (int word = 0; word < dictionary.size(); word++)
//         {
//             TrieNode *crawler = root;
//             for (int ch = 0; ch < dictionary[word].length(); ch++)
//             {
//                 int index = dictionary[word][ch] - 'a';
//                 if (crawler->nodes[index] == NULL)
//                 {
//                     crawler->nodes[index] = createNode();
//                 }
//                 crawler = crawler->nodes[index];
//             }
//             crawler->isEndOfWord = true;
//         }
//     };

//     string replaceWords(vector<string> &dictionary, string sentence)
//     {
//         insert(dictionary);

//         vector<string> splittedSentence;
//         string word = "";

//         for (int i = 0; i < sentence.length(); i++)
//         {
//             if (sentence[i] == ' ')
//             {
//                 splittedSentence.push_back(word);
//                 word = "";
//             }
//             else
//             {
//                 word += sentence[i];
//             }
//         }

//         if (!word.empty())
//         {
//             splittedSentence.push_back(word);
//         }

//         string ans = "";

//         for (int word = 0; word < splittedSentence.size(); word++)
//         {

//             TrieNode *crawler = root;
//             bool replaced = false;
//             for (int ch = 0; ch < splittedSentence[word].length(); ch++)
//             {
//                 int index = splittedSentence[word][ch] - 'a';

//                 // Path doesn't exist
//                 if (crawler->nodes[index] == NULL)
//                 {
//                     break;
//                 }

//                 // Move to next node
//                 crawler = crawler->nodes[index];

//                 // Found root
//                 if (crawler->isEndOfWord)
//                 {
//                     ans += splittedSentence[word].substr(0, ch + 1);
//                     replaced = true;
//                     break;
//                 }
//             }

//             if (!replaced)
//             {
//                 ans += splittedSentence[word];
//             };

//             if (word != splittedSentence.size() - 1)
//             {
//                 ans += " ";
//             }
//         }

//         return ans;
//     }
// };

// class Solution {
// public:
//     string findRoot(string& word, unordered_set<string>& st) {
//         for(int i = 0; i < word.length(); i++) {
//             string root = word.substr(0, i + 1);
//             if(st.count(root)) {
//                 return root;
//             }
//         }

//         return word;
//     }

//     string replaceWords(vector<string>& dictionary, string sentence) {
//         unordered_set<string> st(dictionary.begin(), dictionary.end());

//         stringstream splittedSentence(sentence);
//         string word;
//         string result;

//         while(getline(splittedSentence, word, ' ')) {
//             result += findRoot(word, st) + " ";
//         }

//         result.pop_back();
//         return result;
//     }
// };

// int main()
// {

//     Solution s;

//     vector<string> dictionary = {"cat", "bat", "rat"};
//     string sentence = "the cattle was rattled by the battery";
//     string ans = s.replaceWords(dictionary, sentence);
//     for (int ch = 0; ch < ans.size(); ch++)
//     {

//         cout << ans[ch];
//     }

//     cout << endl;

//     return 0;
// }
