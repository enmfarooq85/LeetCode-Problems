// 201. Bitwise AND of Numbers Range

// Problem statement:

// Given two integers left and right that represent the range [left, right], return the bitwise AND of all numbers in this range, inclusive.

// Understand the problem first:

// Hme two integers left aur right diye gaye hy hme left se le kr right tk ke integers ka AND bitwise operation krna hy. Yaad rahe ranges inclusive hy.

// Approach and Solution:

// Sb se pehle aik baat bta do ke bit manipulation ke questions ko sovle krte hue ap logo ko bitwise operations ka pta hona chahie otherwise buht mushkil hy ke hum log solve kr paye. Agr knowledge bi hy tu pattern observation krna buht hard hy. Sb se pehli approach tu brute force hi mind me ati hy lekin yaad rahe ke hum brute force approach me ans me 0 store nahi kr skte kyu ke 0 ke sath jb bi AND krte ho tu wo 0 hi ata hy. Baqi approaches ke liye recommend kro ga ke MIK ke solutions dekho. Thanks!

// class Solution {
// public:
//     int rangeBitwiseAnd(int left, int right) {
//         int ans = left;
        
//         for (int i = left + 1; i <= right; i++) {
//             ans = ans & i;
//         }

//         return ans;
//     }
// };

// class Solution {
// public:
//     int rangeBitwiseAnd(int left, int right) {
//         int shifts = 0;

//         while (left != right){
//             left = left >> 1;
//             right = right >> 1;

//             shifts++;
//         }

//         return right << shifts;
//     }
// };

// class Solution {
// public:
//     int rangeBitwiseAnd(int left, int right) {
//         while (right > left) {
//             right = right & (right - 1);
//         }

//         return right;
//     }
// };
