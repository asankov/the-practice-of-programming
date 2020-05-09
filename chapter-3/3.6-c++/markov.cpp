#include <stdio.h>
#include <time.h>
#include <iostream>
#include <deque>
#include <map>
#include <vector>

typedef std::deque<std::string> Prefix;
std::map<Prefix, std::vector<std::string> > statetab;

enum
{
    NPREF = 2,
    MAXGEN = 10000,
};
const char *NONWORD = "\n";

void generate(int nwords);
void build(Prefix &prefix, std::istream &in);
void add(Prefix &prefix, const std::string &s);

int main(void)
{
    Prefix prefix;

    for (int i = 0; i < NPREF; i++)
        add(prefix, NONWORD);
    build(prefix, std::cin);
    add(prefix, NONWORD);
    generate(MAXGEN);

    return 0;
}

void build(Prefix &prefix, std::istream &in)
{
    std::string buf;

    while (in >> buf)
        add(prefix, buf);
}

void add(Prefix &prefix, const std::string &s)
{
    if (prefix.size() == NPREF)
    {
        statetab[prefix].push_back(s);
        prefix.pop_front();
    }
    prefix.push_back(s);
}

void generate(int nwords)
{
    Prefix prefix;
    for (int i = 0; i < NPREF; i++)
        add(prefix, NONWORD);

    srand(time(NULL));
    for (int i = 0; i < nwords; i++)
    {
        std::vector<std::string> &suf = statetab[prefix];
        const std::string &w = suf[rand() % suf.size()];
        if (w == NONWORD)
            break;
        std::cout << w << " ";
        prefix.pop_front();
        prefix.push_back(w);
    }
}