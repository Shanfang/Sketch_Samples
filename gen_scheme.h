#ifndef _SCHEME_GEN
#define _SCHEME_GEN

#include <stdio.h>
#include <stdlib.h>


#define MOD 2147483647
#define HL 31

/*
Generating scheme for +/- 1random variables
*/
inline int CW4(unsigned long a, unsigned long b, unsigned long c, unsigned long d, unsigned long x)
{
  unsigned int p_res = hash31(hash31(hash31(a,b,x),c,x),d,x);

  int res = (p_res & 1U == 1U) ? 1 : -1;
  return res;
}
