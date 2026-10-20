// 1318. Minimum Flips to Make a OR b Equal to c

// Problem statement:

// Given 3 positives numbers a, b and c. Return the minimum flips required in some bits of a and b to make ( a OR b == c ). (bitwise OR operation). Flip operation consists of change any single bit 1 to 0 or change the bit 0 to 1 in their binary representation.


// Understnad the problem first:

//  Hme teen integer positive numbers diye  gaye hy a, b and c. Hme a aur b ka OR bitwise operation krna hy aur dekhna hy ke kitne flips required to make it equal to c.

// Approach and Solution:

// Approach ye hy ke hum log simple bit by bit calculate kr le aur then pir compare krte jaye. Doosri approach ke code share kr raha ho neeche mje abhi buht neend a rahi hy isliye kbhi pir sahi.

// class Solution {
// public:
//     int countNumberOfOneBits(int bits) {
//         int count = 0;

//         while (bits != 0) {
//             if ((bits & 1) == 1) {
//                 count++;
//             }

//             bits >>= 1;
//         }

//         return count;
//     }

//     int minFlips(int a, int b, int c) {
//         int xorOpt = ((a | b) ^ c);
//         int andOpt = (a & b);

//         int xorOptAndOpt = (andOpt & xorOpt);

//         return countNumberOfOneBits(xorOptAndOpt) +
//                countNumberOfOneBits(xorOpt);
//     }
// };

// class Solution {
// public:
//     int countNumberOfOneBits(int bits) {
//         int count = 0;

//         while (bits != 0) {
//             if ((bits & 1) == 1) {
//                 count++;
//             }

//             bits >>= 1;
//         }

//         return count;
//     }

//     int minFlips(int a, int b, int c) {
//         int xorOpt = ((a | b) ^ c);
//         int andOpt = (a & b);

//         int xorOptAndOpt = (andOpt & xorOpt);

//         return countNumberOfOneBits(xorOptAndOpt) +
//                countNumberOfOneBits(xorOpt);
//     }
// };

// class Solution {
// public:
//     int minFlips(int a, int b, int c) {
//         int flips = 0;

//         while (a != 0 || b != 0 || c != 0) {
//             if ((c & 1) == 1) {
//                  // if one then i need to check that a or b should be
//                 // either a or b should be one because in OR bitwise operation 
//                 // to get one one of operand must be operand must be 1
//                 if ((a & 1) == 0 && (b & 1) == 0) {
//                     flips++;
//                 }
//             } else {
//                 // if zero then i need to check that a and b should be
//                 // both zero because in OR bitwise operation 
//                 // to get zero both operand must be 0
//                 if ((a & 1) == 1) {
//                     flips++;
//                 }

//                 if ((b & 1) == 1) {
//                     flips++;
//                 }
//             }

//             // shifting to right:
//             a >>= 1;
//             b >>= 1;
//             c >>= 1;
//         }

//         return flips;
//     }
// };
