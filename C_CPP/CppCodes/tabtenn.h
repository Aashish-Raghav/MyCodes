#ifndef TABTENN_H_
#define TABTENN_H_
#include<string>
using std::string;

// typedef class TableTennisPlayer ttp;
class ttp
{
private:
    string firstname;
    string lastname;
    bool hasTable;
public:
    ttp(const string & fn = "none",const string & ln = "none",bool ht = false);
    void Name() const;
    bool HasTable() const { return hasTable;}
    void ResetTable(bool v) { hasTable = v;}
};

// typedef class RatedPlayer rp;

class rp : public ttp
{
private:
    unsigned int rating;
public:
    rp (unsigned int r = 0,const string & fn = "none",
        const string & ln = "none",bool ht = false);
    rp (unsigned int r,const ttp & tp);
    unsigned int Rating() const { return rating;}
    void ResetRating (unsigned int r) { rating = r;}
};
#endif