class LRUCache
{
public:
    list<int> q;
    map<int, int> f;
    int size;
    LRUCache(int capacity)
    {
        size = capacity;
    }

    int get(int key)
    {
        if (f[key])
        {
            q.remove(key);
            q.push_back(key);
            return f[key];
        }
        else
            return -1;
    }

    void put(int key, int value)
    {

        if (q.size() == size)
        {
            if (f[key])
            {
                q.remove(key);
                q.push_back(key);
                f[key] = value;
            }
            else
            {
                f.erase(q.front());
                q.pop_front();
                q.push_back(key);
                f[key] = value;
            }
        }

        else
        {
            if (f[key])
            {
                q.remove(key);
                q.push_back(key);
                f[key] = value;
            }
            else
            {
                q.push_back(key);
                f[key] = value;
            }
        }
    }
};