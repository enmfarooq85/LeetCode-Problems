// 3612. Process String with Special Operations I

// Problem statement:

/*
You are given a string s consisting of lowercase English letters and the special characters: *, #, and %.

Build a new string result by processing s according to the following rules from left to right:

If the letter is a lowercase English letter append it to result.
A '*' removes the last character from result, if it exists.
A '#' duplicates the current result and appends it to itself.
A '%' reverses the current result.
Return the final string result after processing all characters in s.
*/

// Understand the problem first:

// hme aik string dia gia hy jo ke lowercase english letters aur kuch special characters pe mushtamil hy hme is string pe processing kr ke result modified string krna hy.

// Approach and Solution:

// Simple linear way me jaye ge aur condition match kr ke modification kr de ge there is no fancy thing here.

#include "iostream"
#include "string"
#include "algorithm"
using namespace std;

class Solution
{
public:
    string processStr(string s)
    {
        string result;

        for (char ch : s)
        {
            if (ch != '*' && ch != '#' && ch != '%')
            {
                result.push_back(ch);
            }
            else if (ch == '*')
            {
                if (!result.empty())
                {
                    result.pop_back();
                }
            }
            else if (ch == '#')
            {
                result += result;
            }
            else if (ch == '%')
            {
                reverse(result.begin(), result.end());
            }
        }

        return result;
    }
};

int main()
{

    Solution s1;

    s1.processStr("a*34##");
    return 0;
}