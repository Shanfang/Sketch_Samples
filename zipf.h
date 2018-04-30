#ifndef _ZIPF
#define _ZIPF

#include <vector>
using namespace std;


class Zipf {
  public:
    unsigned int dom_size;

    unsigned int tuples_no;
    vector<unsigned int> *tuples;


    Zipf(unsigned int dom_size, unsigned int tuples_no);
    virtual ~Zipf();

    void Generate_Data(double data_param, double decor_param);
};

#endif
