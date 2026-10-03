// 2131. Longest Palindrome by Concatenating Two Letter Words

// Problem statement:

/*
You are given an array of strings words. Each element of words consists of two lowercase English letters. Create the longest possible palindrome by selecting some elements from words and concatenating them in any order. Each element can be selected at most once. Return the length of the longest palindrome that you can create. If it is impossible to create any palindrome, return 0. A palindrome is a string that reads the same forward and backward.
*/

// Understand the problem first:

// Hme aik array of string words dia gia hy jo ke lowercase english letters pe mustamil ho ge aur hr word ki lenght hamesha two hi ho gi. Ap ne in words ko mila ke kisi trah bi longest palindrome bnana hy. Agr impossible hu bnana tu zero return krna hy.

// Approach and Solution:

// Approach ye ho gi ke hum log aik hashmap bna ge jis me hum word ke corresponding uska count rakhe ge. Aur then pir har word ke corresponding reverse word dondne ki koshih kre ge kyu ke palindrome me yahi tu hota hy ke first half is reverse of second half. 
// even => ab bb ba
// odd => ab cc ba
// baqi ap log code me likhe gaye comments padh le aur aik mrtaba dry run kre.

// class Solution {
// public:
//     int longestPalindrome(vector<string>& words) {
//         // {word:count}
//         unordered_map<string, int> mp;

//         for (string& word : words) {
//             mp[word]++;
//         };

//         int ans = 0;
//         // Palindrome ki length even ho ya odd ho
//         // beech wali cheeze aik mrtaba hi exist kr skti hy
//         // mtlb agr dono character same hy ya just aik character hi hy
//         // agr same nahi tu nahi dal skte beech wali position pe
//         // even => abbbba
//         // odd => mom
//         bool isCenterUsed = false;

//         for (string& word : words) {
//             string reverseWord = word;
//             reverse(reverseWord.begin(), reverseWord.end());

//             // agr currentWord aur isi ka currentReverse word same nahi hy
//             // tu ap map me dekho ke ye km-z-km 1 1 mrtaba mujood ho
//             // agr mujood hy tu result me 4 plus kro
//             // sath sath is word ka map me count bi decrement krte jao
//             // like word = "ab", reverseWord = "ba"
//             // palindrome = "ab ba", totalLength = 4
//             if (word != reverseWord) {
//                 if (mp[reverseWord] > 0 && mp[word] > 0) {
//                     ans += 4;
//                     mp[word] -= 1;
//                     mp[reverseWord] -= 1;
//                 }
//             } else {
//                 // agr currentWord aur isi ka currentReverse word same hy
//                 // tu ap map me dekho ke ye at least 2 ya 2 se ziada mrtaba
//                 // mujood ho agr mujood hy tu result me 4 plus kro sath sath is
//                 // word ka map me count bi decrement krte jao
//                 // like word = "cc", reverseWord = "cc"
//                 // palindrome = "cc cc", totalLength = 4
//                 if (mp[word] >= 2) {
//                     ans += 4;
//                     mp[word] -= 2;
//                 } else {
//                     // yaha pe ye dekho ke agr ye word aik mrtaba hy
//                     // tu ab iski position beech me hi bnti hy
//                     // lekin sath me ye bi dekho ke wo use na hoa hu
//                     // tbhi tu add kr skte hy palindrom me
//                     // yaha pe aik bdi interesting story hy ke
//                     // agr word = "c", reverseWord = "c" hoa tu
//                     // tu hum log one dale ge
//                     // lekin trick ye hy ke hme question me ye dia hi nahi hoa
//                     // ke apka word aik length ka ho ga
//                     if (mp[word] == 1 && isCenterUsed == false) {
//                         ans += 2;
//                         mp[word] -= 1;
//                         isCenterUsed = true;
//                     }
//                 }
//             }
//         }

//         return ans;
//     }
// };
