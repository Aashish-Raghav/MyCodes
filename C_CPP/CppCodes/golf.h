class Golf
{
private:
    static const int LEN = 40;
    char name_[LEN];
    int handicap_;
public:
    Golf(const char * name = "",int hc = 0);
    int setGolf();
    void handicap(int hc);
    void showGolf() const;
};
