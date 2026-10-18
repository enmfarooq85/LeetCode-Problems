// 135. Candy

// Problem statement:

/*
There are n children standing in a line.

Each child is assigned a rating value given in the integer array ratings.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
Return the minimum number of candies you need to have to distribute the candies to the children.
*/

// Understand the problem first:

// Kuch n number of children row me kade hy aur un ko kuch rating assign hy. Aur hme ratings integer of array dia gia hy. Hme insaaf se un ke darmian candies ko divide krna hy ke hr aik ke pas at least aik candy ho aur jis ke pas max rating hy usko ziada candies de ge us ke neighbors se

// Approach and Solution:

// Sb se pehle jo mind me cheez ati hy greedy approach ke hum log left to right jaye aur left aur right ke hisaab se candies assign kr de lekin is me unfair ho skta hy isliye normal greedy approach work nahi kre ge aur hme apni approach ko modify krna ho ga ke hum log pehle tu sb aik candies assign kr de aur then pir pehle left ke hisaab se candies find kr le aur then pir right ke hisaab se aur then pir max le le left aur right ka aur ans me add krte chle jaye.

// class Solution {
// public:
//     int candy(vector<int>& ratings) {
//         int n = ratings.size();
//         vector<int> l2R(n, 1);

//         for (int i = 1; i < n; i++) {
//             if (ratings[i] > ratings[i - 1]) {
//                 l2R[i] = l2R[i - 1] + 1;
//             }
//         }

//         vector<int> r2L(n, 1);
//         for (int i = n - 2; i >= 0; i--) {
//             if (ratings[i] > ratings[i + 1]) {
//                 r2L[i] = r2L[i + 1] + 1;
//             }
//         }

//         int ans = 0;
//         for (int i = 0; i < n; i++) {
//             ans += max(l2R[i], r2L[i]);
//         }

//         return ans;
//     }
// };
