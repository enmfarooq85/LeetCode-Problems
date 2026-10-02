// 705. Design HashSet

// Problem statement:

/*
Design a HashSet without using any built-in hash table libraries.

Implement MyHashSet class:

void add(key) Inserts the value key into the HashSet.
bool contains(key) Returns whether the value key exists in the HashSet or not.
void remove(key) Removes the value key in the HashSet. If key does not exist in the HashSet, do nothing.
*/

// Understand the problem first:

// Hme hashset implement krna hy with out using any inbuilt hashset library. Problem simply ye hy ke teen function hy aik add ke name se jo ke key le ga aur hme us ko as value treat kr ke hmare bnae hoe hashset me dalni hy. Isi trah contains ka function hme key de ga aur hme dekhna hy ke aya ye key as value hmare hashset me exist krti hy ya nahi. Isi trah aik remove ka function hy jo key de ga aur hme us key ko remove krna hy.

// Approach and Solution:

// Iske liye simple approach ye hy ke hum log vector boolean le ge jis me key ko as index le ge aur then pir us ki value ki jagah kuch bi dal de ge us key index pe. Aur then pir simply compare krwa de hy tu true warna false aur isi trah remove me false mark kr de instead of removing that key from vector.

// class MyHashSet {
// public:
//     vector<int> hashSet;

//     MyHashSet() {
//         hashSet.resize(1000001, -1);
//     }

//     void add(int key) { hashSet[key] = 1; }

//     void remove(int key) { hashSet[key] = -1; }

//     bool contains(int key) {return  hashSet[key] == 1; }
// };
