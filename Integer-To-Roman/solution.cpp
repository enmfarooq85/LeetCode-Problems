// 12. Integer to Roman

// Problem statement:

// Given an integer, convert it to a Roman numeral.

// Understand the problem statement:

// hme aik integer dia gia hy hum ne us ko roman numeral me convert krna hy.

// Approach and Solution:

// sb se pehle ye jante hy ke roman numeral kya hota hy. Roman numeral ek aisa system hy jisme numbers ko letters se represent kiya jata hy. Jaise ke:
// I = 1
// V = 5
// X = 10
// L = 50
// C = 100
// D = 500
// M = 1000
// ab hum ne ye bhi janna hy ke kuch special cases bhi hote hy jaise ke:
// IV = 4
// IX = 9
// XL = 40
// XC = 90
// CD = 400
// CM = 900
// ab hum ne ye bhi janna hy ke hum ne integer ko roman numeral me convert krna hy. To hum ne ye socha ke hum ek vector banayenge jisme hum values aur symbols ko store karenge. Phir hum ne ek loop chalaya jisme hum check karenge ke humara integer current value se bada ya barabar hai ya nahi. Agar hai to hum symbol ko result me add karenge aur integer se value ko subtract karenge. Hum ye process tab tak repeat karenge jab tak integer zero nahi ho jata. Is tarah humara result me roman numeral aa jayega.

#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        vector<int> values = {
            1000, 900, 500, 400,
            100, 90, 50, 40,
            10, 9, 5, 4, 1
        };

        vector<string> symbols = {
            "M", "CM", "D", "CD",
            "C", "XC", "L", "XL",
            "X", "IX", "V", "IV", "I"
        };

        string result = "";

        for (int i = 0; i < values.size(); i++) {
            while (num >= values[i]) {
                result += symbols[i];
                num -= values[i];
            }
        }

        return result;
    }
};

int main (){

    Solution sol;
    int num = 1994;
    string romanNumeral = sol.intToRoman(num);
    cout << "The Roman numeral for " << num << " is: " << romanNumeral << endl;
    return 0;

}