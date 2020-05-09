#include <iostream>

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