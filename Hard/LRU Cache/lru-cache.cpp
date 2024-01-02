//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way

class LRUCache {
private:
    int capacity;
    std::list<std::pair<int, int>> dll;  // Doubly linked list to maintain order
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> mp;  // Hash map for fast access

public:
    LRUCache(int cap) {
        capacity = cap;
    }

    int GET(int key) {
        if (mp.find(key) != mp.end()) {
            // Move the accessed item to the front of the list
            dll.splice(dll.begin(), dll, mp[key]);
            return mp[key]->second;
        }
        return -1;
    }

    void SET(int key, int value) {
        if (mp.find(key) != mp.end()) {
            // Update the existing entry
            mp[key]->second = value;
            // Move the updated item to the front of the list
            dll.splice(dll.begin(), dll, mp[key]);
        } else {
            if (dll.size() >= capacity) {
                // Remove the least recently used item (back of the list)
                int oldKey = dll.back().first;
                mp.erase(oldKey);
                dll.pop_back();
            }
            // Insert the new item at the front of the list
            dll.push_front({key, value});
            mp[key] = dll.begin();
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->SET(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->GET(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends