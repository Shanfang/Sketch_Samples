#ifndef _XIS
#define _XIS

class Xi {
  public:
    virtual double element(unsigned int j) = 0;
    virtual double interval_sum(unsigned int alpha, unsigned int beta) = 0;

    virtual ~Xi();
};

class Xi_EH3 : public Xi {
  protected:
    unsigned int seeds[2];

  public:
    Xi_EH3(unsigned int I1, unsigned int I2);
    virtual ~Xi_EH3();

    virtual double element(unsigned int j);
    virtual double interval_sum(unsigned int alpha, unsigned int beta);
};


/*
B-valued random variables that are 2-wise independent
*/

class Xi_CW2B : public Xi {
  protected:
    unsigned int seeds[2];
    unsigned int buckets_no;

  public:
    Xi_CW2B(unsigned int I1, unsigned int I2, unsigned int B);
    virtual ~Xi_CW2B();

    virtual double element(unsigned int j);
    virtual double interval_sum(unsigned int alpha, unsigned int beta);
};

#endif
