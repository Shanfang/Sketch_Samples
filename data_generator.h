#ifndef _DATA_GENERATOR
#define _DATA_GENERATOR


#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <vector>


using namespace std;

/*
Generate data for zipf's distribution
*/

unsigned int generate_uniform(unsigned int sizedom, double totalmass, vector<unsigned int> &f) {
  unsigned int tuples_no = 0;

  totalmass = (sizedom > totalmass) ? sizedom : totalmass;

  for (unsigned int i = 0; i < sizedom; i++) {
    f[i] = (unsigned int)rint(totalmass / sizedom);
    tuples_no += f[i];
  }

  return tuples_no;
}

unsigned int generate_zipf(unsigned int sizedom, double totalmass, double zipf_param, vector<unsigned int> &f) {
  if (zipf_param == 0.0) {
    return generate_uniform(sizedom, totalmass, f);
  }

  unsigned int tuples_no = 0;

  // compute the normalization coefficient
  double normcoef = 0.0;
  for (unsigned int i = 0; i < sizedom; i++) {
    normcoef += 1 / pow(i + 1, zipf_param);
  }

  // put the frequency table in f by computing the frequency and round it to integer
  for (unsigned int i = 0; i < sizedom; i++) {
    f[i] = (unsigned int)rint(totalmass / (pow(i + 1, zipf_param) * normcoef));
    tuples_no += f[i];
  }

  return tuples_no;
}

void random_shuffling(vector<unsigned int> &f) {
  unsigned int sizedom = f.size();

  for (unsigned int i = 0; i < sizedom; i++) {
    unsigned int ip = rand() % sizedom;
    unsigned int tmp = f[i];
    f[i] = f[ip];
    f[ip] = tmp;
  }
}


void random_shuffling(vector<unsigned int> &f, vector<unsigned int> &g) {
  unsigned int sizedom = f.size();

  for (unsigned int i = 0; i < sizedom; i++) {
    unsigned int ip = rand() % sizedom;
    unsigned int tmp = f[i];
    f[i] = f[ip];
    f[ip] = tmp;

    tmp = g[i];
    g[i] = g[ip];
    g[ip] = tmp;
  }
}

// decorelate according to the frequency and decor_param 
void decorelate(vector<unsigned int> &f, double p_decor) {
  unsigned int sizedom = f.size();

  if (p_decor < 0) {
    for (int i = 0 ; i < (sizedom/2); i++) {
      int temp = f[sizedom - 1 - i];
      f[sizedom - 1 - i] = f[i];
      f[i] = temp;
    }
  }

  for(int i = 0 ; i < sizedom * (1.0 - fabs(p_decor)); i++) {
    int ind1, ind2;
    ind1 = int(sizedom * drand48());
    ind2 = int(sizedom * drand48());

    int temp = f[ind2];
    f[ind2] = f[ind1];
    f[ind1] = temp;
  }
}


void print_freq_table(vector<unsigned int> &f) {
  for (unsigned int i = 0; i < f.size(); i++) {
    cout << i << "\t" << f[i] << endl;
  }
}

#endif
