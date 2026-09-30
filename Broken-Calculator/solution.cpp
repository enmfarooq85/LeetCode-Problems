// 991. Broken Calculator

// Problem statement:

/*
There is a broken calculator that has the integer startValue on its display initially. In one operation, you can:

multiply the number on display by 2, or
subtract 1 from the number on display.
Given two integers startValue and target, return the minimum number of operations needed to display target on the calculator.
*/

// Understand the problem first:

// Hme aik startValue aur target di hui hy hume aik step me statValue ko 2 se multiply kr ke ya 1 subtract kr ke target tk ponchna hy aur wo bi minimum operations me. 

// Approach and Solution:

// Yaad rakhe ke ye question itna simple nahi hy jitna ap smje ge. Agr ap startValue se target tk ponchne ki koshih kre ge tu it's really hard to recognize the pattern and finding efficient number of operations. Isliye hum log target se startValue tk ponchne ki koshih kre ge. Mazeed approach smjne ke liye is editorial ko follow kre. https://nhutnguyen.hashnode.dev/a-solution-to-leetcode-991-broken-calculator

// class Solution {
// public:
//     int brokenCalc(int startValue, int target) {
//         // if same then nothing to do
//         if (startValue == target) {
//             return 0;
//         }
        
//         // it means we have to subtract
//         // startValue to (startValue - target) times
//         if (startValue >= target) {
//             return startValue - target;
//         }

//         // if even then divide by 2 
//         if (target % 2 == 0) {
//             return 1 + brokenCalc(startValue, target / 2);
//         }

//         // it means odd, then increment by one
//         return 1 + brokenCalc(startValue, target + 1);
//     }
// };
