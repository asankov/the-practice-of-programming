#include <iostream>
#include <deque>
#include <map>
#include <vector>

enum
{
    NHASH = 4098,
};

std::hash<std::string> hasher;

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

class Prefix
{
public:
    std::string values[2];
    int _size;

    int size()
    {
        return _size;
    }
    std::string at(int index)
    {
        return values[index];
    }
    void push_back(std::string val)
    {
        values[_size++] = val;
    }
    void pop_front()
    {
        if (_size == 2)
        {
            values[0] = values[1];
            values[1] = std::string();
        }
        else if (_size == 1)
        {
            values[0] = std::string();
        }
        else if (_size == 0)
        {
            return;
        }
        _size--;
    }

    int hash()
    {
        unsigned int h = 0;

        for (int i = 0; i < size(); i++)
        {
            h += hasher(at(i));
        }

        return h % NHASH;
    }

    bool operator==(Prefix other)
    {
        if (size() != other.size())
            return false;

        for (int i = 0; i < size(); i++)
            if (at(i).compare(other.at(i)) != 0)
                return false;

        return true;
    }

    Prefix()
    {
        _size = 0;
        values[0] = std::string();
        values[1] = std::string();
    }
};

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
    StateMapEntry *entries[NHASH];

    Suffixes *operator[](Prefix p)
    {
        int hash = p.hash();
        for (StateMapEntry *e = entries[hash]; e != NULL; e = e->next)
        {
            if (p == *e->prefix)
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
