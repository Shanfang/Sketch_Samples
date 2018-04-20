#include "gen_scheme.h"
#include "xis.h"


using namespace std;


/*
The seed of pseudo-random variable is generated randomly from a pair of master seeds (I1, I2)
that are also randomly generated.
*/


Xi::~Xi()
{
}


Xi_CW4::Xi_CW4(unsigned int I1, unsigned int I2)
{
  const unsigned int k_mask = 0xffffffff;

  seeds[0] = ((I1 << 16)^(I2 & 0177777)) & k_mask;

  I1 = 36969*(I1 & 0177777) + (I1>>16);
  I2 = 18000*(I2 & 0177777) + (I2>>16);

  seeds[1] = ((I1 << 16)^(I2 & 0177777)) & k_mask;

  I1 = 36969*(I1 & 0177777) + (I1>>16);
  I2 = 18000*(I2 & 0177777) + (I2>>16);

  seeds[2] = ((I1 << 16)^(I2 & 0177777)) & k_mask;

  I1 = 36969*(I1 & 0177777) + (I1>>16);
  I2 = 18000*(I2 & 0177777) + (I2>>16);

  seeds[3] = ((I1 << 16)^(I2 & 0177777)) & k_mask;
}


Xi_CW4::~Xi_CW4()
{
}


double Xi_CW4::element(unsigned int j)
{
  unsigned long a = seeds[0];
  unsigned long b = seeds[1];
  unsigned long c = seeds[2];
  unsigned long d = seeds[3];

  double res = CW4(a, b, c, d, j);
  return res;
}


double Xi_CW4::interval_sum(unsigned int alpha, unsigned int beta)
{
  unsigned long a = seeds[0];
  unsigned long b = seeds[1];
  unsigned long c = seeds[2];
  unsigned long d = seeds[3];

  double res = 0;

  for (unsigned int k = alpha; k <= beta; k++)
    res += CW4(a, b, c, d, k);

  return res;
}
