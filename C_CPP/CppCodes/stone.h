#ifndef STONEWT_H_
#define STONEWT_H_

class Stonewt
{
private:
    enum {Lbs_per_stn = 14};        //OR static const int Lps = 14;
    int stone;
    double pds_left;
    double pounds;
public:
    Stonewt(double lbs);
    Stonewt(int stn,double lbs);
    Stonewt();
    ~Stonewt();
    void show_lbs() const;
    void show_stn() const;
    
    Stonewt operator*(double n);
    friend Stonewt operator*(double n,const Stonewt & st);

    explicit operator int() const;
    explicit operator double() const;
};

#endif