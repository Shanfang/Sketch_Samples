#ifndef _XIS
#define _XIS

/*
  Generating schemes for +/-1 random variables
*/


using namespace std;


class Xi
{
  public:
    virtual double element(unsigned int j) = 0;
    virtual double interval_sum(unsigned int alpha, unsigned int beta) = 0;

    virtual ~Xi();
};


/*
+/-1 random variables that are 4-wise independent
*/

class Xi_CW4 : public Xi
{
  protected:
    unsigned int seeds[4];

  public:
    Xi_CW4(unsigned int I1, unsigned int I2);
    virtual ~Xi_CW4();

    virtual double element(unsigned int j);
    virtual double interval_sum(unsigned int alpha, unsigned int beta);
};


#endif
