// Range Maximum Index Query

// Intuition:

/*
Is Range Maximum Index Query ka basic idea yeh hai ke hum Segment Tree mein maximum value store karne ke bajaye us maximum value ka index store karte hain. Tree banate waqt har leaf node ek element ko represent karti hai, is liye leaf node mein us element ka index store hota hai. Phir har parent node ke liye hum left aur right child se maximum element ke indexes lete hain aur arr mein un indexes par mojood values ko compare karte hain. Jo value maximum hoti hai, uska index parent node mein store kar dete hain. Is tarah har node humein yeh batati hai ke uske corresponding range mein maximum element kis index par mojood hai.

Jab humein kisi range [queryStart, queryEnd] ka maximum index find karna ho, to hum Segment Tree ko recursively traverse karte hain. Agar current range query ke bahar hai to hum -1 return karte hain, kyun ke us range ka query mein koi contribution nahi hai. Agar current range poori tarah query ke andar hai to hum directly us node mein stored maximum index return kar dete hain. Agar range partially overlap kar rahi ho to hum left aur right dono children ko query karte hain. Agar kisi ek side se -1 aaye to doosri side ka index return kar dete hain. Agar dono sides se valid indexes milen, to arr[leftMaxIndex] aur arr[rightMaxIndex] ki values compare karte hain aur jis index par maximum value ho, us index ko return kar dete hain. Is tarah poori range ko scan karne ke bajaye Segment Tree efficiently range ke andar maximum element ka index find kar leti hai.
*/

#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    void buildMaxIndexSegmentTree(vector<int> &sTree, vector<int> &arr, int i, int start, int end)
    {
        if (start == end)
        {
            sTree[i] = start;
            return;
        }

        int mid = start + (end - start) / 2;

        buildMaxIndexSegmentTree(sTree, arr, 2 * i + 1, start, mid);
        buildMaxIndexSegmentTree(sTree, arr, 2 * i + 2, mid + 1, end);

        int leftIndex = sTree[2 * i + 1];
        int rightIndex = sTree[2 * i + 2];

        if (leftIndex >= rightIndex)
        {
            sTree[i] = leftIndex;
        }

        sTree[i] = rightIndex;
    }

    int findMaxIndex(vector<int> &sTree, vector<int> &arr, int i, int start, int end, int queryStart, int queryEnd)
    {

        if (queryStart > end || queryEnd < start)
        {
            return -1;
        }

        if (start >= queryStart && end <= queryEnd)
        {
            return sTree[i];
        }

        int mid = start + (end - start) / 2;

        int leftMaxIndex = findMaxIndex(sTree, arr, 2 * i + 1, start, mid, queryStart, queryEnd);
        int rightMaxIndex = findMaxIndex(sTree, arr, 2 * i + 2, mid + 1, end, queryStart, queryEnd);

        if (leftMaxIndex == -1)
            return rightMaxIndex;
        if (rightMaxIndex == -1)
            return leftMaxIndex;

        if (arr[leftMaxIndex] >= arr[rightMaxIndex])
        {
            return leftMaxIndex;
        }

        return rightMaxIndex;
    };
};

int main()
{

    Solution s;
    vector<int> arr = {1, 14, 12, 4};
    int n = arr.size();
    vector<int> sTree(4 * n);
    s.buildMaxIndexSegmentTree(sTree, arr, 0, 0, n - 1);
    vector<vector<int>> queries = {{0, 1}, {0, 3}};

    for (int query = 0; query < queries.size(); query++)
    {
        int maxIndex = s.findMaxIndex(sTree, arr, 0, 0, n - 1, queries[query][0], queries[query][1]);
        cout << "After query [" << queries[query][0] << ", " << queries[query][1] << "]: ";
        cout << "Max Index: " << maxIndex << endl;
    }

    return 0;
}