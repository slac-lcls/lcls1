#include "psalg/psalg.h"

ndarray<double,1> psalg::moments(const ndarray<const double  ,1>& input,
                                 double x0,
                                 double dx)
{
  unsigned shape[] = {3};
  ndarray<double,1> m(shape);
  m[0] = 0;
  m[1] = 0;
  m[2] = 0;

  double x = x0 + 0.5*dx;
  for(unsigned k=0; k<input.shape()[0]; k++,x+=dx) {
    double v = input[k];
    m[0] += v;
    m[1] += v*x;
    m[2] += v*x*x;
  }

  return m;
}

ndarray<double,1> psalg::moments(const ndarray<const double  ,1>& num,
                                 const ndarray<const double  ,1>& den,
                                 double x0,
                                 double dx)
{
  unsigned shape[] = {3};
  ndarray<double,1> m(shape);
  m[0] = 0;
  m[1] = 0;
  m[2] = 0;

  double x = x0 + 0.5*dx;
  for(unsigned k=0; k<num.shape()[0]; k++,x+=dx) {
    double v = num[k]/den[k];
    m[0] += v;
    m[1] += v*x;
    m[2] += v*x*x;
  }

  return m;
}

ndarray<double,1> psalg::moments(const ndarray<const unsigned,2>& input,
                                 double value_offset)
{
  unsigned bounds[][2] = { {0, input.shape()[0] },
                           {0, input.shape()[1] } };
  return psalg::moments(input, value_offset, bounds);
}

ndarray<double,1> psalg::moments(const ndarray<const unsigned,2>& input,
                                 double value_offset,
                                 unsigned bounds[][2])
{
  unsigned shape[] = {5};
  ndarray<double,1> m(shape);
  m[0] = m[1] = m[2] = m[3] = m[4] = 0;

  for(unsigned j=bounds[0][0]; j<bounds[0][1]; j++)
    for(unsigned k=bounds[1][0]; k<bounds[1][1]; k++) {
      double v = double(input(j,k))-value_offset;
      m[0] += 1;
      m[1] += v;
      m[2] += v*v;
      m[3] += double(k)*v;
      m[4] += double(j)*v;
    }
  return m;
}


ndarray<double,1> psalg::moments(const ndarray<const unsigned,2>& input,
                                 const ndarray<const unsigned,1>& row_mask,
                                 const ndarray<const unsigned,2>& mask,
                                 double value_offset)
{
  unsigned bounds[][2] = { {0, input.shape()[0]},
                           {0, input.shape()[1]} };
  return psalg::moments(input,row_mask,mask,value_offset,bounds);
}

ndarray<double,1> psalg::moments(const ndarray<const unsigned,2>& input,
                                 const ndarray<const unsigned,1>& row_mask,
                                 const ndarray<const unsigned,2>& mask,
                                 double value_offset,
                                 unsigned bounds[][2])
{
  unsigned shape[] = {5};
  ndarray<double,1> m(shape);
  m[0] = m[1] = m[2] = m[3] = m[4] = 0;

  for(unsigned j=bounds[0][0]; j<bounds[0][1]; j++) {
    if (row_mask[j>>5] & (1<<(j&0x1f))) {
      for(unsigned k=bounds[1][0]; k<bounds[1][1]; k++) {
        if (mask(j,k>>5) & (1<<(k&0x1f))) {
          double v = double(input(j,k))-value_offset;
          m[0] += 1;
          m[1] += v;
          m[2] += v*v;
          m[3] += double(k)*v;
          m[4] += double(j)*v;
        }
      }
    }
  }
  return m;
}

ndarray<double,1> psalg::moments(const ndarray<const double,2>& input,
                                 double value_offset)
{
  unsigned bounds[][2] = { {0, input.shape()[0]},
                           {0, input.shape()[1]} };
  return psalg::moments(input,value_offset,bounds);
}

ndarray<double,1> psalg::moments(const ndarray<const double,2>& input,
                                 double value_offset,
                                 unsigned bounds[][2])
{
  unsigned shape[] = {5};
  ndarray<double,1> m(shape);
  m[0] = m[1] = m[2] = m[3] = m[4] = 0;

  for(unsigned j=bounds[0][0]; j<bounds[0][1]; j++)
    for(unsigned k=bounds[1][0]; k<bounds[1][1]; k++) {
      double v = input(j,k)-value_offset;
      m[0] += 1;
      m[1] += v;
      m[2] += v*v;
      m[3] += double(k)*v;
      m[4] += double(j)*v;
    }
  return m;
}

ndarray<double,1> psalg::moments(const ndarray<const double,2>&   input,
                                 const ndarray<const unsigned,1>& row_mask,
                                 const ndarray<const unsigned,2>& mask,
                                 double value_offset)
{
  unsigned bounds[][2] = { {0,input.shape()[0]},
                           {0,input.shape()[1]} };
  return psalg::moments(input,row_mask,mask,value_offset,bounds);
}

ndarray<double,1> psalg::moments(const ndarray<const double,2>&   input,
                                 const ndarray<const unsigned,1>& row_mask,
                                 const ndarray<const unsigned,2>& mask,
                                 double value_offset,
                                 unsigned bounds[][2])
{
  unsigned shape[] = {5};
  ndarray<double,1> m(shape);
  m[0] = m[1] = m[2] = m[3] = m[4] = 0;

  for(unsigned j=bounds[0][0]; j<bounds[0][1]; j++)
    if (row_mask[j>>5] & (1<<(j&0x1f))) {
      for(unsigned k=bounds[1][0]; k<bounds[1][1]; k++) {
        if (mask(j,k>>5) & (1<<(k&0x1f))) {
          double v = input(j,k)-value_offset;
          m[0] += 1;
          m[1] += v;
          m[2] += v*v;
          m[3] += double(k)*v;
          m[4] += double(j)*v;
        }
      }
    }
  return m;
}

template void psalg::rolling_average(const ndarray<const int32_t,1>&,
                                     ndarray<double,1>&,
                                     double);

template void psalg::rolling_average(const ndarray<const double,1>&,
                                     ndarray<double,1>&,
                                     double);

template <typename I>
void psalg::rolling_average(const ndarray<const I,1>& a,
                            ndarray<double,1>&        avg,
                            double                    fraction)
{
  if (avg.size()==0) {
    avg = make_ndarray<double>(a.shape()[0]);
    for(unsigned k=0; k<a.shape()[0]; k++)
      avg[k] = double(a[k]);
  }
  else {
    const double f0 = 1-fraction;
    for(unsigned k=0; k<a.shape()[0]; k++)
      avg[k] = f0*avg[k] + fraction*double(a[k]);
  }
}

template void psalg::rolling_average(const ndarray<const int32_t,2>&,
                                     ndarray<double,2>&,
                                     double);

template void psalg::rolling_average(const ndarray<const double,2>&,
                                     ndarray<double,2>&,
                                     double);

template <typename I>
void psalg::rolling_average(const ndarray<const I,2>& a,
                            ndarray<double,2>&        avg,
                            double                    fraction)
{
  if (avg.size()==0) {
    avg = make_ndarray<double>(a.shape()[0],a.shape()[1]);
    for(unsigned k=0; k<a.shape()[0]; k++)
      for(unsigned l=0; l<a.shape()[1]; l++)
        avg(k,l) = double(a(k,l));
  }
  else {
    const double f0 = 1-fraction;
    for(unsigned k=0; k<a.shape()[0]; k++)
      for(unsigned l=0; l<a.shape()[1]; l++)
        avg(k,l) = f0*avg(k,l) + fraction*double(a(k,l));
  }
}
