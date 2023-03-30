#include "studenti.h"
using std::ostream;
using std::istream;
using std::string;
using std::endl;

//public methods
double Student::Average() const
{
    if (ArrayDb::size() > 0)
        return ArrayDb::sum() / ArrayDb::size();
    else
        return 0;
}

const string & Student::Name() const
{
    return (const string & ) *this;
}