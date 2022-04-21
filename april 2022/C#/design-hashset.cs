// Design a HashSet without using any built-in hash table libraries.

// Implement MyHashSet class:

// void add(key) Inserts the value key into the HashSet.
// bool contains(key) Returns whether the value key exists in the HashSet or not.
// void remove(key) Removes the value key in the HashSet. If key does not exist in the HashSet, do nothing.

// Example 1:
// Input
// ["MyHashSet", "add", "add", "contains", "contains", "add", "contains", "remove", "contains"]
// [[], [1], [2], [1], [3], [2], [2], [2], [2]]
// Output
// [null, null, null, true, false, null, true, null, false]

// Explanation
// MyHashSet myHashSet = new MyHashSet();
// myHashSet.add(1);      // set = [1]
// myHashSet.add(2);      // set = [1, 2]
// myHashSet.contains(1); // return True
// myHashSet.contains(3); // return False, (not found)
// myHashSet.add(2);      // set = [1, 2]
// myHashSet.contains(2); // return True
// myHashSet.remove(2);   // set = [1]
// myHashSet.contains(2); // return False, (already removed)
 
// Constraints:
// 0 <= key <= 10^6
// At most 10^4 calls will be made to add, remove, and contains.

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.Add(key);
 * obj.Remove(key);
 * bool param_3 = obj.Contains(key);
 */

public class MyHashSet {
    private HashSet<int> set;
    public MyHashSet() {
        set = new HashSet<int>();
    }

    public void Add(int key) {
        set.Add(key);
    }

    public void Remove(int key) {
        set.Remove(key);
    }

    /** returns true if this set contains the specified element */
    public bool Contains(int key) {
        return set.Contains(key);
    }

    public void Clear() {
        set.Clear();
    }

    public int Count() {
        return set.Count;
    }

    public void Print(string msg) {
        Console.WriteLine(msg);
        foreach (var item in set) {
            Console.WriteLine(item);
        }
    }
}