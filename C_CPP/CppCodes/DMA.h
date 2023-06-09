//DMA -> dynamic memeory allocation.
// inheritance + dma

#ifndef DMA_H_
#define DMA_H_
#include<iostream>

class baseDMA
{
private:
    char * label;
    int rating;

public:
    baseDMA(const char* l = "null",int r = 0);
    baseDMA(const baseDMA & rs);
    virtual ~baseDMA();
    baseDMA & operator=(const baseDMA & rs);
    friend std::ostream & operator<<(std::ostream & os,const baseDMA & rs);
};

// derived class without DMA;
// no destructor needed
// uses implicit copy constructor
// uses implicit assignment op
class lacksDMA : public baseDMA
{
private:
    static const int COL_LEN = 40;
    char color[COL_LEN];
public:
    lacksDMA(const char * c = "black",const char * l = "null",
                int r = 0);
    lacksDMA(const char * c,const baseDMA & rs);
    friend std::ostream & operator<<(std::ostream & os,const lacksDMA & ls); 
};

//derived class with DMA
//needed copy constructor
//destructor
//assignment opertor;
class hasDMA : public baseDMA
{
private:
    char * style;
public:
    hasDMA(const char * s = "none",const char * l = "null",
            int r = 0);
    hasDMA(const char * s,const baseDMA & rs);
    hasDMA(const hasDMA & rs);      //copy constructor
    ~hasDMA();      // destructor
    hasDMA & operator=(const hasDMA & hs);     //assignment operator
    friend std::ostream & operator<<(std::ostream & os,const hasDMA & hs);
};
#endif

