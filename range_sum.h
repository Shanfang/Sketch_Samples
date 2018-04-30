#ifndef _RANGES
#define _RANGES

#include "gen_scheme.h"

/*
  Fast range-summation algorithm for EH3 scheme
*/

inline double EH3Interval(unsigned int gamma, unsigned int S0, unsigned int s0) {
 int i, s_bits_one = 0;
 double sum = 0;
 int f_A;
 unsigned int t_bits;
 unsigned int s_bits;

 s_bits = S0 & 3U;
 if (s_bits == 3U)
   s_bits_one = 1;

 t_bits = gamma & 3U;

 if (t_bits == 1U) {
   gamma -= 1;

   sum += EH3(s0, S0, gamma);
 } else if (t_bits == 2U) {
   gamma -= 2;

   sum += EH3(s0, S0, gamma);
   sum += EH3(s0, S0, gamma+1);
 } else if (t_bits == 3U) {
   gamma -= 3;

   sum += EH3(s0, S0, gamma);
   sum += EH3(s0, S0, gamma+1);
   sum += EH3(s0, S0, gamma+2);
 }



 for (i = 2; i < 32; i += 2) {
   if (gamma == 0U)
     return sum;

   t_bits = (gamma >> i) & 3U;
   gamma ^= (t_bits << i);
   if (t_bits == 1U) {
     f_A = EH3(s0, S0, gamma);

     if (s_bits_one % 2 == 1U) {
       sum -= (f_A << (i >> 1));
     } else {
       sum += (f_A << (i >> 1));
     }
   } else if (t_bits == 2U) {
     f_A = EH3(s0, S0, gamma);

     if (s_bits_one % 2 == 1U) {
       sum -= (f_A << (i >> 1));
     } else {
       sum += (f_A << (i >> 1));
     }

     f_A = EH3(s0, S0, gamma + (1U << i));

     if (s_bits_one % 2 == 1U) {
       sum -= (f_A << (i >> 1));
     } else {
       sum += (f_A << (i >> 1));
     }
   } else if (t_bits == 3U) {
     f_A = EH3(s0, S0, gamma);

     if (s_bits_one % 2 == 1U) {
       sum -= (f_A << (i >> 1));
     } else {
       sum += (f_A << (i >> 1));
     }

     f_A = EH3(s0, S0, gamma + (1 << i));

     if (s_bits_one % 2 == 1U) {
       sum -= (f_A << (i >> 1));
     } else {
       sum += (f_A << (i >> 1));
     }


     f_A = EH3(s0, S0, gamma + (1U << (i + 1)));

     if (s_bits_one % 2 == 1U) {
       sum -= (f_A << (i >> 1));
     } else {
       sum += (f_A << (i >> 1));
     }
   }

   s_bits = (S0 >> i) & 3U;
   if (s_bits == 3U) {
     s_bits_one += 1;
   }
 }
 return sum;
}


inline double EH3_Range(unsigned int alpha, unsigned int beta, unsigned int S0, unsigned int s0) {
 double sum = EH3Interval(beta+1, S0, s0);
 sum -= EH3Interval(alpha, S0, s0);

 return sum;
}

#endif
