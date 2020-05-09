#include <iostream>
#include <deque>
#include <map>
#include <vector>

class Suffixes
{
private:
    class Suffix
    {
    public:
        std::string val;
        Suffix *next;
    };

    Suffix *suffixes;
    int _size;

public:
    int size()
    {
        return _size;
    }
    std::string operator[](int index)
    {
        int c = 0;
        for (Suffix *s = suffixes; s != NULL; s = s->next)
            if (index == c++)
                return s->val;

        return NULL;
    }
    void push(std::string val)
    {
        _size++;
        Suffix *s = new Suffix();
        s->val = val;
        s->next = suffixes;
        suffixes = s;
    }
};

typedef std::deque<std::string> Prefix;
std::hash<std::string> hasher;

// todo: make instance methods of Prefix
int hash_prefix(Prefix p)
{
    unsigned int h = 0;

    for (int i = 0; i < p.size(); i++)
    {
        h += hasher(p.at(i));
    }

    return h % 4098;
}

bool prefix_equals(Prefix first, Prefix second)
{
    if (first.size() != second.size())
        return false;

    for (int i = 0; i < first.size(); i++)
    {
        if (first.at(i).compare(second.at(i)) != 0)
            return false;
    }

    return true;
}
class StateMap
{
private:
    class StateMapEntry
    {
    public:
        Prefix *prefix;
        Suffixes *suffixes;
        StateMapEntry *next;
    };

public:
    std::map<Prefix, Suffixes> _map;
    StateMapEntry *entries[4098];

    Suffixes *operator[](Prefix p)
    {
        int hash = hash_prefix(p);
        for (StateMapEntry *e = entries[hash]; e != NULL; e = e->next)
        {
            if (prefix_equals(p, *e->prefix))
            {
                return e->suffixes;
            }
        }

        //create
        StateMapEntry *new_entry = new StateMapEntry();
        new_entry->prefix = new Prefix();
        for (int i = 0; i < p.size(); i++)
            new_entry->prefix->push_back(p.at(i));
        new_entry->suffixes = new Suffixes();
        new_entry->next = entries[hash];
        entries[hash] = new_entry;

        return entries[hash]->suffixes;
    }
};
