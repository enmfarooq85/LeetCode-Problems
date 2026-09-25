// 3477. Fruits Into Baskets II

// Problem statement:

/*
You are given two arrays of integers, fruits and baskets, each of length n, where fruits[i] represents the quantity of the ith type of fruit, and baskets[j] represents the capacity of the jth basket.

From left to right, place the fruits according to these rules:

Each fruit type must be placed in the leftmost available basket with a capacity greater than or equal to the quantity of that fruit type.
Each basket can hold only one type of fruit.
If a fruit type cannot be placed in any basket, it remains unplaced.
Return the number of fruit types that remain unplaced after all possible allocations are made.
*/ 

// Understand the problem statement:

// hme aik fruits aur baskets arrays diye gaye hy hum ne hr fruit ko leftmost valid basket me dalna hy aur jis basket me aik dafa fruit dal dia dobara nahi dal skte aur sirf aik fruit aik hi tokri me dal skte hy.

// Approach and Solution:

// Simple approach ye hy ke hum nested loop lga ke dekh le aur pir aik array maintain kr le jis me usage ka track rakhe. Is trah se hum isko asani se hal kr skte hy. Iska doosra variant hy jis me hum log segment tree pe baat kre ge.

// class Solution {
// public:
//     int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
//         int ans = 0;
//         int n = baskets.size();
//         vector<bool> used(n, false);

//         for (int i = 0; i < n; i++) {
//             int found = false;
//             for (int j = 0; j < n; j++) {
//                 if (used[j] == false && baskets[j] >= fruits[i]) {
//                     used[j] = true;
//                     found = true;
//                     break;
//                 }
//             }

//             if (found == false) {
//                 ans += 1;
//             }
//         }

//         return ans;
//     }
// };
