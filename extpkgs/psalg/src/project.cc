#include "psalg/psalg.h"

ndarray<const int,1> psalg::project(const ndarray<const uint16_t,2>& input,
                                    const unsigned* roi_lo,
                                    const unsigned* roi_hi,
                                    unsigned pedestal,
                                    unsigned pdim)
{
  ndarray<int,1> a = make_ndarray<int>(roi_hi[pdim]-roi_lo[pdim]+1);
  int nped = -int(pedestal)*int(roi_hi[1-pdim]-roi_lo[1-pdim]+1);
  if (pdim==1) {
    for(int* p=a.begin(); p!=a.end(); p++) *p=nped;
    for(unsigned i=roi_lo[0]; i<=roi_hi[0]; i++)
      for(unsigned j=roi_lo[1],k=0; j<=roi_hi[1]; j++,k++)
        a[k] += int(input(i,j));
  }
  else {
    for(unsigned i=roi_lo[0],k=0; i<=roi_hi[0]; i++,k++) {
      int v=nped;
      for(unsigned j=roi_lo[1]; j<=roi_hi[1]; j++)
        v += int(input(i,j));
      a[k] = v;
    }
  }
  return a;
}

ndarray<double,1> psalg::project(const ndarray<const double,2>& input,
                                 const unsigned* roi_lo,
                                 const unsigned* roi_hi,
                                 double pedestal,
                                 unsigned pdim)
{
  ndarray<double,1> a = make_ndarray<double>(roi_hi[pdim]-roi_lo[pdim]+1);
  double nped = -pedestal*(roi_hi[1-pdim]-roi_lo[1-pdim]+1);
  if (pdim==1) {
    for(double* p=a.begin(); p!=a.end(); p++) *p=nped;
    for(unsigned i=roi_lo[0]; i<=roi_hi[0]; i++)
      for(unsigned j=roi_lo[1],k=0; j<=roi_hi[1]; j++,k++)
        a[k] += input(i,j);
  }
  else {
    for(unsigned i=roi_lo[0],k=0; i<=roi_hi[0]; i++,k++) {
      double v=nped;
      for(unsigned j=roi_lo[1]; j<=roi_hi[1]; j++)
        v += input(i,j);
      a[k] = v;
    }
  }
  return a;
}

ndarray<const int,1> psalg::project(const ndarray<const uint16_t,2>& input,
                                    unsigned pedestal,
                                    unsigned pdim)
{
  unsigned roi_lo[] = {0, 0};
  unsigned roi_hi[] = {input.shape()[0]-1,input.shape()[1]-1};
  return project(input, roi_lo, roi_hi, pedestal, pdim);
}

ndarray<double,1> psalg::project(const ndarray<const double,2>& input,
                                 double pedestal,
                                 unsigned pdim)
{
  unsigned roi_lo[] = {0, 0};
  unsigned roi_hi[] = {input.shape()[0]-1,input.shape()[1]-1};
  return project(input, roi_lo, roi_hi, pedestal, pdim);
}

ndarray<const int,2> psalg::roi(const ndarray<const uint16_t,2>& input,
                                const unsigned* roi_lo,
                                const unsigned* roi_hi,
                                unsigned pedestal)
{
  ndarray<int,2> a = make_ndarray<int>(roi_hi[0]-roi_lo[0]+1,roi_hi[1]-roi_lo[1]+1);
  for(unsigned i=roi_lo[0],k=0; i<=roi_hi[0]; i++,k++)
    for(unsigned j=roi_lo[1],l=0; j<=roi_hi[1]; j++,l++)
      a(k,l) = int(input(i,j)) - int(pedestal);
  return a;
}
