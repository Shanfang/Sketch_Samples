#ifndef _RANGES
#define _RANGES

#include "gen_scheme.h"


inline double Dyadic_Range_CW4(unsigned int aa, unsigned int bb, unsigned long a, unsigned long b, unsigned long c, unsigned long d, int dom_size)
{
  double sum = 0;

  unsigned int pw = 0;
  unsigned int front_mask = 0;

  unsigned int map;

  int alpha = aa;
  int beta = bb;

  while (alpha <= beta)
  {
    if (((alpha >> pw) & 1U) == 1U)
    {
      map = front_mask ^ (alpha >> pw);
      sum += CW4(a, b, c, d, map);

      alpha += (1 << pw);

    }

    if (alpha > beta)
      return sum;

    if (((beta >> pw) & 1U) == 0U)
    {
      map = front_mask ^ ((beta - (1 << pw) + 1) >> pw);
      sum += CW4(a, b, c, d, map);

      beta -= (1 << pw);

    }

    front_mask = (front_mask >> 1) ^ (1U << dom_size);
    pw += 1;
  }

  return sum;
}

#endif
