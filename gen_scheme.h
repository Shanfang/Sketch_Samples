#ifndef _SCHEME_GEN
#define _SCHEME_GEN

#include <stdio.h>
#include <stdlib.h>


#define MOD 2147483647
#define HL 31

/*
  Generating schemes for +-1 random variables
  For details see the papers:
	1) "Fast Range-Summable Random Variables for Efficient Aggregate Estimation" by F. Rusu and A. Dobra
	2) "Pseudo-Random Number Generation for Sketch-Based Estimations" by F. Rusu and A. Dobra

  Assumption: integers are represented on 32 bits
*/



/*
  Computes parity bit of the bits of an integer
*/
inline unsigned int seq_xor(unsigned int x) {
  x ^= (x >> 16);
  x ^= (x >> 8);
  x ^= (x >> 4);
  x ^= (x >> 2);
  x ^= (x >> 1);
  
  return (x & 1U);
}


/*
  Adapted from MassDal: http://www.cs.rutgers.edu/~muthu/massdal-code-index.html
  Computes Carter-Wegman (CW) hash with Mersenne trick
*/
inline unsigned int hash31(unsigned long long a, unsigned long long b, unsigned long long x) {
  unsigned long long result;
  unsigned int lresult;  

  result = (a * x) + b;
  result = ((result >> (unsigned int)HL) + result) & (unsigned long long)MOD;
  lresult = (unsigned int)result;

  return lresult;
}


inline int EH3(unsigned int i0, unsigned int I1, unsigned int j) {
  unsigned int mask = 0xAAAAAAAA;
  unsigned int p_res = (I1&j) ^ (j & (j<<1) & mask);
  
  int res = ((i0 ^ seq_xor(p_res)) & (1U == 1U)) ? 1 : -1;
  return res;
}

/*
  b-valued random variables
  2-wise and 4-wise CW scheme
*/
inline unsigned int CW2B(unsigned long a, unsigned long b, unsigned long x, unsigned int M) {
  unsigned int p_res = hash31(a,b,x);
  
  unsigned int res = p_res % M;
  return res;
}


#endif
