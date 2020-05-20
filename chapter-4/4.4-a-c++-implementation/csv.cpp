
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <istream>
#include <iostream>
#include <vector>

// read and parse comma-separated values
// sample input: "LU",86.25,"11/4/1998","2:19PM",+4.0625
class Csv
{
public:
    Csv(std::istream &fin = std::cin, std::string sep = ",") : fin(fin), fieldsep(sep) {}

    int getline(std::string &);
    int getnfield() const { return nfield; }
    std::string operator[](int n);

private:
    std::istream &fin;              // input file pointer
    std::string line;               // input line
    std::vector<std::string> field; // field strings
    int nfield;                     // number of fields
    std::string fieldsep;           // separator characters

    int split();
    int endofline(char);
    int advplain(const std::string &line, std::string &fld, int);
    int advquoted(const std::string &line, std::string &fld, int);
};

std::string Csv::operator[](int n)
{
    if (n < 0 || n >= nfield)
        return "";
    return field[n];
};

// getline: get one line, grow as needed
int Csv::getline(std::string &str)
{
    char c;

    for (line = ""; fin.get(c) && !endofline(c);)
        line += c;
    split();
    str = line;
    return !fin.eof();
}

// endofline: check for and consume \r, \n, \r\n, or EOF
int Csv::endofline(char c)
{
    int eol = (c == '\r' || c == '\n');
    if (c == '\r')
    {
        fin.get(c);
        if (!fin.eof() && c != '\n')
            fin.putback(c); // read too far
    }
    return eol;
}

// split: split line into fields
int Csv::split()
{
    std::string fld;
    int i = 0, j;

    nfield = 0;
    if (line.length() == 0)
        return 0;

    do
    {
        if (i < line.length() && line[i] == '"')
            j = advquoted(line, fld, ++i); // skip quote
        else
            j = advplain(line, fld, i);

        if (nfield >= field.size())
            field.push_back(fld);
        else
            field[nfield] = fld;
        nfield++;
        i = j + 1;
    } while (j < line.length());

    return nfield;
}

// advquoted: quoted field: return index of next separator
int Csv::advquoted(const std::string &s, std::string &fld, int i)
{
    int j;

    fld = "";
    for (j = i; j < s.length(); j++)
    {
        if (s[j] == '"' && s[++j] != '"')
        {
            int k = s.find_first_of(fieldsep, j);
            if (k > s.length()) // no separator found
                k = s.length();
            for (k -= j; k-- > 0;)
                fld += s[j++];
            break;
        }
        fld += s[j];
    }
    return j;
}

// advplain: unquoted filed; return index of next separator
int Csv::advplain(const std::string &s, std::string &fld, int i)
{
    int j = s.find_first_of(fieldsep, i); // look for separator
    if (j > s.length())                   // none found
        j = s.length();
    fld = std::string(s, i, j - i);
    return j;
}

// Csvtest main: test Csv class
int main(void)
{
    std::string line;
    Csv csv;

    while (csv.getline(line) != 0)
    {
        std::cout << "line = " << line << "\n";
        for (int i = 0; i < csv.getnfield(); i++)
            std::cout << "field[" << i << "] = '" << csv[i] << "'\n";
    }
    return 0;
}