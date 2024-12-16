#include <math.h>
#include "psalg/psalg.h"
#include <stdio.h>
#include <iostream>
#include <string.h>

// averages all values in array "data" for length "length"
// that are below "threshold".  If the magniture of the correction
// is greater than "maxCorrection" leave "data" unchanged, otherwise
// subtract the average in place.  
// mask is either a null pointer (in which case nothing is masked)
// or a list of values arranged like the data where non-zero means ignore

template <typename T>
void psalg::commonMode(const T* data, const uint16_t* mask, const unsigned length, const T threshold, const T maxCorrection, T& cm) {
  // do dumbest thing possible to start - switch to median
  // do 2nd dumbest thing possible to start - switch to median
  cm = 0;
  const T* tmp = data;
  double sum = 0;
  int nSummed = 0;
  for (unsigned col=0; col<length; col++) {
    T cval = *tmp++;
    T mval = (mask) ? *mask++ : 0;
    if (mval==0 && cval<threshold) {
      nSummed++;
      sum += cval;
    }
  }
  
  if (nSummed>0) {
    T mean = (T)(sum/nSummed);
    if (fabs(mean)<=maxCorrection) {
      cm = mean;
    }
  }
}


template <typename T>
void psalg::commonMode(T* data, const uint16_t* mask, const unsigned length, const T threshold, const T maxCorrection, T& cm) {
  psalg::commonMode((const T*)data, mask, length, threshold, maxCorrection, cm);
  if (cm != 0) {
    T* tmp = data;
    for (unsigned col=0; col<length; col++) {
      *tmp++ -= cm;
    }
  }
}

// finds median of values in array "data" for length "length"
// that are below "threshold".  If the magniture of the correction
// is greater than "maxCorrection" leave "data" unchanged, otherwise
// subtract the median in place.  
// mask is either a null pointer (in which case nothing is masked)
// or a list of values arranged like the data where non-zero means ignore

template <typename T>
void psalg::commonModeMedian(const T* data, const uint16_t* mask, const unsigned length, const T threshold, const T maxCorrection, T& cm) {
  cm = 0;
  const T* tmp = data;

  const uint32_t lMax = 32768;//2**14*2;  // here I may be assuming data in ADU
  const uint32_t lHalfMax = 16384;//2**14;
  unsigned hist[lMax];
  memset(hist, 0, sizeof(unsigned)*lMax);
  int nSummed = 0;
  for (unsigned col=0; col<length; col++) {
    T cval = *tmp++;
    T mval = (mask) ? *mask++ : 0;
    if (mval==0 && cval<threshold) {
      nSummed++;
      unsigned bin = (int)cval+lHalfMax;
      // unsigned long?  check range or raise?
      hist[bin]++;
    }
  }

  if (nSummed==0) return;

  unsigned medianCount = (unsigned)ceil(nSummed/2.);
  unsigned histSum = 0;
  for (unsigned bin=0; bin<lMax; bin++) {
    histSum += hist[bin];
    if (histSum>=medianCount) {
      T median = (int)bin -  (int)lHalfMax;
      if (fabs(median)<=maxCorrection) {
	cm = median;
      }
      return;
    }
  }
}

template <typename T>
void psalg::commonModeMedian(T* data, const uint16_t* mask, const unsigned length, const T threshold, const T maxCorrection, T& cm) {
  psalg::commonModeMedian((const T*)data, mask, length, threshold, maxCorrection, cm);
  if (cm != 0) {
    T* tmp = data;
    for (unsigned col=0; col<length; col++) {
      *tmp++ -= cm;
    }
  }
}

ndarray<const double,1> psalg::commonModeLROE(const ndarray<const int32_t,1>& a,
                                              const ndarray<const double,1>&  baseline)
{
  const unsigned cols=a.size();
  double q_left_odd=0, q_left_even=0, q_right_odd=0, q_right_even=0;
  {
    unsigned k=0, m=cols/2;
    while(k < cols/2) {
      q_left_even  += double(a[k]) - baseline[k]; k++;
      q_right_even += double(a[m]) - baseline[m]; m++;
      q_left_odd   += double(a[k]) - baseline[k]; k++;
      q_right_odd  += double(a[m]) - baseline[m]; m++;
    }

    { double n = double(cols/4);
      q_left_even  /= n;
      q_left_odd   /= n;
      q_right_even /= n;
      q_right_odd  /= n; }
  }

  ndarray<double,1> b = make_ndarray<double>(cols);
  {
    unsigned k=0, m=cols/2;
    while(k < cols/2) {
      b[k] = baseline[k] + q_left_even; k++;
      b[m] = baseline[m] + q_right_even; m++;
      b[k] = baseline[k] + q_left_odd; k++;
      b[m] = baseline[m] + q_right_odd; m++;
    }
  }
  return b;
}

ndarray<const double,2> psalg::commonModeLROE(const ndarray<const int32_t,2>& a,
                                              const ndarray<const double,2>&  baseline)
{
  const unsigned rows=a.shape()[0];
  const unsigned cols=a.shape()[1];
  double q_left_odd=0, q_left_even=0, q_right_odd=0, q_right_even=0;
  for (unsigned i=0; i<rows; i++)
  {
    unsigned k=0, m=cols/2;
    while(k < cols/2) {
      q_left_even  += double(a(i,k)) - baseline(i,k); k++;
      q_right_even += double(a(i,m)) - baseline(i,m); m++;
      q_left_odd   += double(a(i,k)) - baseline(i,k); k++;
      q_right_odd  += double(a(i,m)) - baseline(i,m); m++;
    }
  }

  { double n = double(rows*cols/4);
      q_left_even  /= n;
      q_left_odd   /= n;
      q_right_even /= n;
      q_right_odd  /= n; }

  ndarray<double,2> b = make_ndarray<double>(rows,cols);
  for (unsigned i=0; i<rows; i++)
  {
    unsigned k=0, m=cols/2;
    while(k < cols/2) {
      b(i,k) = baseline(i,k) + q_left_even; k++;
      b(i,m) = baseline(i,m) + q_right_even; m++;
      b(i,k) = baseline(i,k) + q_left_odd; k++;
      b(i,m) = baseline(i,m) + q_right_odd; m++;
    }
  }
  return b;
}

template void psalg::commonMode<double>(const double* data, const uint16_t* mask, const unsigned length, const double threshold, const double maxCorrection, double& cm);
template void psalg::commonMode<float>(const float* data, const uint16_t* mask, const unsigned length, const float threshold, const float maxCorrection, float& cm);
template void psalg::commonMode<int32_t>(const int32_t* data, const uint16_t* mask, const unsigned length, const int32_t threshold, const int32_t maxCorrection, int32_t& cm);
template void psalg::commonMode<int16_t>(const int16_t* data, const uint16_t* mask, const unsigned length, const int16_t threshold, const int16_t maxCorrection, int16_t& cm);

template void psalg::commonMode<double>(double* data, const uint16_t* mask, const unsigned length, const double threshold, const double maxCorrection, double& cm);
template void psalg::commonMode<float>(float* data, const uint16_t* mask, const unsigned length, const float threshold, const float maxCorrection, float& cm);
template void psalg::commonMode<int32_t>(int32_t* data, const uint16_t* mask, const unsigned length, const int32_t threshold, const int32_t maxCorrection, int32_t& cm);
template void psalg::commonMode<int16_t>(int16_t* data, const uint16_t* mask, const unsigned length, const int16_t threshold, const int16_t maxCorrection, int16_t& cm);

template void psalg::commonModeMedian<double>(const double* data, const uint16_t* mask, const unsigned length, const double threshold, const double maxCorrection, double& cm);
template void psalg::commonModeMedian<float>(const float* data, const uint16_t* mask, const unsigned length, const float threshold, const float maxCorrection, float& cm);
template void psalg::commonModeMedian<int32_t>(const int32_t* data, const uint16_t* mask, const unsigned length, const int32_t threshold, const int32_t maxCorrection, int32_t& cm);
template void psalg::commonModeMedian<int16_t>(const int16_t* data, const uint16_t* mask, const unsigned length, const int16_t threshold, const int16_t maxCorrection, int16_t& cm);

template void psalg::commonModeMedian<double>(double* data, const uint16_t* mask, const unsigned length, const double threshold, const double maxCorrection, double& cm);
template void psalg::commonModeMedian<float>(float* data, const uint16_t* mask, const unsigned length, const float threshold, const float maxCorrection, float& cm);
template void psalg::commonModeMedian<int32_t>(int32_t* data, const uint16_t* mask, const unsigned length, const int32_t threshold, const int32_t maxCorrection, int32_t& cm);
template void psalg::commonModeMedian<int16_t>(int16_t* data, const uint16_t* mask, const unsigned length, const int16_t threshold, const int16_t maxCorrection, int16_t& cm);

/*
int main() {
  float a0[7] = {0., 1., 2., -1., -2., 10., 11.};
  float a1[7] = {0., 1., 2., -1., -2., 10., 11.};
  int16_t ai0[7] = {0, 1, 2, -1, -2, 10, 11};
  float ams0[7] = {0., 1., 2., -1., -2., 10., 11.};
  float ams1[7] = {0., 1., 2., -1., -2., 10., 11.};
  int16_t amsi0[7] = {0, 1, 2, -1, -2, 10, 11};
  uint16_t b[7] = {0, 1, 0, 0, 0, 0, 0};
  uint16_t *b0 = 0;

  float cm = -666.;
  int16_t icm = -666;
  unsigned length = 7;
  float thresh = 5.;
  float max = 5.;
  int16_t ithresh = 5;
  int16_t imax = 5;

  //  psalg::commonMode(a0, b, length, thresh, max, cm);
  psalg::commonMode(a0, b, length, (float)100., (float)100., cm);
  printf("cm %f, a0,1: %f, %f\n", cm, a0[0], a0[1]); 
  psalg::commonMode(a1, b0, 7, thresh, max, cm);
  printf("cm %f, a1,1: %f, %f\n", cm, a1[0], a1[1]);
  psalg::commonMode(ai0, b, 7, ithresh, imax, icm);
  printf("cm %d, ai1,1: %d, %d\n", icm, ai0[0], ai0[1]);

  psalg::commonModeMedian(ams0, b, length, (float)100., (float)100., cm);
  printf("cm median standard %f, a0,1: %f, %f\n", cm, ams0[0], ams0[1]); 
  psalg::commonModeMedian(ams1, b0, 7, thresh, max, cm);
  printf("cm median standard %f, a1,1: %f, %f\n", cm, ams1[0], ams1[1]);
  psalg::commonModeMedian(amsi0, b, 7, ithresh, imax, icm);
  printf("cm median standard %d, ai1,1: %d, %d\n", icm, amsi0[0], amsi0[1]);
  

  // expect
//cm 3.333333, a0,1: -3.333333, -2.333333
//cm 0.000000, a1,1: 0.000000, 1.000000
//cm 0, ai1,1: 0, 1
//cm median standard 0.000000, a0,1: 0.000000, 1.000000
//cm median standard 0.000000, a1,1: 0.000000, 1.000000
//cm median standard -1, ai1,1: 1, 2

  return 0;
}
*/
