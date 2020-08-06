class MyHashSet
{
public:
    /** Initialize your data structure here. */
    int maps[1000005];
    MyHashSet()
    {
        for (int i = 0; i < 1000005; i++)
        {
            maps[i] = 0;
        }
    }

    void add(int key)
    {
        maps[key] = 1;
    }

    void remove(int key)
    {
        maps[key] = 0;
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key)
    {
        return maps[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */