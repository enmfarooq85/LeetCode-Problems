// 1323. Maximum 69 Number

// Understand the problem first:

// You are given a positive integer num consisting only of digits 6 and 9. Return the maximum number you can get by changing at most one digit (6 becomes 9, and 9 becomes 6).

// Problem statement:

// Hme aik positive integer number dia gia hy jo ke sirf 9 aur 6 pe mushtamil ho ga. Hme just aik digit tabdeel krna hy aur usko maximum bnana hy chahe wo 6 ho ya 9

// Approach and Solution:

// Simple approach ye hy ke sb se pehla wala number dekhe ge jo ke 9 na ho aur usi ko change kr de ge 9 se aur sb se bada number mil jaye ga. Ap aik do example khud se dry run kre tu ap logo ko idea ho jaye ga me kia kehna cha raha ho. Aik aur approach ye hy ke hum log us sb se pehle wale non 9 number ki place position nikale aur us number me plus 3 * (pow(10, placePosition)) kr de tu wahi hasil ho jaye gi. Lekin hme iske liye left se right jana pade ga aur us non 9 ki place nikalni pade ge. See second block of code and dry run it

// class Solution {
// public:
//     int maximum69Number(int num) {
//         string numInStr = to_string(num);
//         int isChanged = false;
//         for (int i = 0; i < numInStr.size(); i++) {
//             if (numInStr[i] != '9') {
//                 isChanged = true;
//                 numInStr[i] = '9';
//                 break;
//             }
//         }

//         if(isChanged){
//             return stoi(numInStr);
//         } else {
//             return num;
//         }
//     }
// };

// class Solution {
// public:
//     int maximum69Number(int num) {
//         int numm = num;
//         int count = 0;
//         int placedValue = -1;

//         while (numm > 0) {
//             int remainder = numm % 10;

//             if (remainder == 6) {
//                 placedValue = count;
//             }

//             count += 1;
//             numm = numm / 10;
//         }

//         if (placedValue == -1) {
//             return num;
//         } else {
//             return (num + (3 * pow(10, placedValue)));
//         }
//     }
// };
