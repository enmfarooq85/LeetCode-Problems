// Range Update Query

// Intuition:

/*
Segment Tree mein humein kuch range ko update karne ke liye diya ja sakta hai. Ye update **point update** bhi ho sakta hai aur range update bhi.

Yahan hum **range update** ki intuition samajhte hain.

Range update karne ke basically two approaches hain.

Pehli approach ye hai ke hum range ke andar **har individual element ko update** karein. Lekin agar range bohat large ho, to ye approach inefficient ho sakti hai.

Doosri approach hai Lazy Propagation.

Lazy Propagation mein hum har child ko immediately update nahi karte.

Instead, agar current node ki range completely query ke andar aa rahi hai, to hum **parent node ki range par hi update perform kar dete hain** aur neeche children tak immediately nahi jaate.

Phir hum us update ki information ko `lazy` tree mein children ke corresponding indexes par store kar dete hain.

Ye basically children ko ye batata hai:

Abhi tumhein update karne ki zaroorat nahi, lekin future mein jab tumhare paas query aaye ya tumhein access kiya jaye, to ye pending update apply karna.

Isi idea ki wajah se hum unnecessary child nodes ko baar baar update karne se bach jaate hain aur range updates ko efficiently handle kar sakte hain.
*/

#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    void buildSTree(vector<int> &sTree, vector<int> &arr, int i, int start, int end)
    {
        if (start == end)
        {
            sTree[i] = arr[start];
            return;
        }

        int mid = start + (end - start) / 2;

        buildSTree(sTree, arr, 2 * i + 1, start, mid);
        buildSTree(sTree, arr, 2 * i + 2, mid + 1, end);

        sTree[i] = sTree[2 * i + 1] + sTree[2 * i + 2];
    };

    void rangeUpdate(vector<int> &sTree, vector<int> &lTree, int val, int i, int start, int end, int queryStart, int queryEnd)
    {
        if (lTree[i] != 0)
        {
            sTree[i] += ((end - start) + 1) * val;

            if (start != end)
            {

                sTree[2 * i + 1] += val;
                sTree[2 * i + 2] += val;
            }

            lTree[i] = 0;
        }

        if (queryStart > end || queryEnd < start)
        {
            return;
        }

        if (start >= queryStart && end <= queryEnd)
        {
            sTree[i] += ((end - start) + 1) * val;
            if (start != end)
            {
                lTree[2 * i + 1] += val;
                lTree[2 * i + 2] = val;
            }
            return;
        }

        int mid = start + (end - start) / 2;

        rangeUpdate(sTree, lTree, val, 2 * i + 1, start, mid, queryStart, queryEnd);
        rangeUpdate(sTree, lTree, val, 2 * i + 2, mid + 1, end, queryStart, queryEnd);

        sTree[i] = sTree[2 * i + 1] + sTree[2 * i + 2];
    }
};

int main()
{
    Solution s;
    vector<int> arr = {1, 2, 3, 4, 5};
    int n = arr.size();
    vector<int> sTree(4 * n);
    s.buildSTree(sTree, arr, 0, 0, n - 1);
    vector<int> lTree(4 * n);
    int val = 3;
    vector<vector<int>> queries = {{1, 2}, {3, 3}};

    for (int i = 0; i < queries.size(); i++)
    {
        s.rangeUpdate(sTree, lTree, val, 0, 0, n - 1, queries[i][0], queries[i][1]);

        cout << "After query [" << queries[i][0] << ", " << queries[i][1] << "]: ";
        cout << "Total Sum = " << sTree[0] << endl;
    }

    // query1: 1 + 5 + 6 + 4 + 5 => 21
    // query2: 1 + 5 + 6 + 7 + 5 => 24 

    cout << "\nFinal total sum: " << sTree[0] << endl; // 24

    return 0;
}