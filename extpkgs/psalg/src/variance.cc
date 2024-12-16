#include "psalg/psalg.h"
#include <math.h>

void psalg::variance_accumulate(const ndarray<const double,2>& input,
                                ndarray<double,2>& mom1,
                                ndarray<double,2>& mom2)
{
  unsigned ny = input.shape()[0];
  unsigned nx = input.shape()[1];
  for(unsigned j=0; j<ny; j++) {
    double* m1 = &mom1(j,0);
    double* m2 = &mom2(j,0);
    const double* i = &input(j,0);
    for(unsigned k=0; k<nx; k++) {
      const double v = i[k];
      m1[k] += v;
      m2[k] += v*v;
    }
  }
}

void psalg::variance_accumulate(double wt,
                                const ndarray<const double,2>& input,
                                ndarray<double,2>& mom1,
                                ndarray<double,2>& mom2)
{
  unsigned ny = input.shape()[0];
  unsigned nx = input.shape()[1];
  for(unsigned j=0; j<ny; j++) {
    double* m1 = &mom1(j,0);
    double* m2 = &mom2(j,0);
    const double* i = &input(j,0);
    for(unsigned k=0; k<nx; k++) {
      const double v = i[k]*wt;
      m1[k] += v;
      m2[k] += v*v;
    }
  }
}

void psalg::variance_calculate (double wt,
                                const ndarray<const double,2>& input,
                                ndarray<double,2>& mom1,
                                ndarray<double,2>& mom2,
                                unsigned n,
                                ndarray<double,2>& result)
{
  double s = 1./double(n);
  unsigned ny = input.shape()[0];
  unsigned nx = input.shape()[1];
  for(unsigned j=0; j<ny; j++) {
    double* m1 = &mom1(j,0);
    double* m2 = &mom2(j,0);
    double* r  = &result(j,0);
    const double* i = &input(j,0);
    for(unsigned k=0; k<nx; k++) {
      const double v = i[k]*wt;
      m1[k] += v;
      m2[k] += v*v;
      double m = s*m1[k];
      r[k] = sqrt(s*m2[k]-m*m);
    }
  }
}

void psalg::variance_accumulate(double off,
                                const ndarray<const unsigned,2>& input,
                                ndarray<double,2>& mom1,
                                ndarray<double,2>& mom2)
{
  unsigned ny = input.shape()[0];
  unsigned nx = input.shape()[1];
  for(unsigned j=0; j<ny; j++) {
    double* m1 = &mom1(j,0);
    double* m2 = &mom2(j,0);
    const unsigned* i = &input(j,0);
    for(unsigned k=0; k<nx; k++) {
      const double v = double(i[k])-off;
      m1[k] += v;
      m2[k] += v*v;
    }
  }
}

void psalg::variance_accumulate(double wt,
                                double off,
                                const ndarray<const unsigned,2>& input,
                                ndarray<double,2>& mom1,
                                ndarray<double,2>& mom2)
{
  unsigned ny = input.shape()[0];
  unsigned nx = input.shape()[1];
  for(unsigned j=0; j<ny; j++) {
    double* m1 = &mom1(j,0);
    double* m2 = &mom2(j,0);
    const unsigned* i = &input(j,0);
    for(unsigned k=0; k<nx; k++) {
      const double v = (double(i[k])-off)*wt;
      m1[k] += v;
      m2[k] += v*v;
    }
  }
}

void psalg::variance_calculate (double wt,
                                double off,
                                const ndarray<const unsigned,2>& input,
                                ndarray<double,2>& mom1,
                                ndarray<double,2>& mom2,
                                unsigned n,
                                ndarray<unsigned,2>& result)
{
  double s = 1./double(n);
  unsigned ny = input.shape()[0];
  unsigned nx = input.shape()[1];
  for(unsigned j=0; j<ny; j++) {
    double* m1 = &mom1(j,0);
    double* m2 = &mom2(j,0);
    unsigned* r  = &result(j,0);
    const unsigned* i = &input(j,0);
    for(unsigned k=0; k<nx; k++) {
      const double v = (double(i[k])-off)*wt;
      m1[k] += v;
      m2[k] += v*v;
      double m = s*m1[k];
      r[k] = unsigned(sqrt(s*m2[k]-m*m)+0.5);
    }
  }
}

