#ifndef PSALG_PSALG_H
#define PSALG_PSALG_H

// according to the web, this is the best way to pick up
// things like uint16_t in an OS independent way (had trouble
// with RHEL5/RHEL6).  we already have the boost dependency, so
// not much extra pain.
#include <boost/cstdint.hpp>
#include <list>
#include "ndarray/ndarray.h"

class psalg {
 public:
/// @addtogroup psalg

/**
 *  @ingroup psalg
 *
 *  @brief Data manipulation algorithms
 *
 *  @author Matt Weaver
 */

  /**
   * @ingroup finite_impulse_response
   *
   * @brief Finite impulse response filter.
   *
   * Creates the 1-dimensional filtered response array from the
   * sample input array and the impulse response filter array.
   *
   */
  static ndarray<double,1> 
    finite_impulse_response(const ndarray<const double,1>& filter,
                            const ndarray<const double,1>& sample);
                            
  
  /**
   *
   * Fills the 1-dimensional output array with the
   * impulse response filter array applied to the input sample
   * array.
   *
   */

  static void
    finite_impulse_response(const ndarray<const double,1>& filter,
                            const ndarray<const double,1>& input,
                            ndarray<double,1>&             output);
                          

  /**
   * @ingroup Variance
   *
   * @brief Variance
   *
   * The root-mean-square is calculated by first accumulating the
   * first and second moment arrays and then computing from those arrays
   * with the known number of accumulations.  The array shapes must all
   * be equal.
   */
  /*
   * Accumulate the first and second moment arrays.
   */

  static void variance_accumulate(const ndarray<const double,2>& input,
                                  ndarray<double,2>& mom1,
                                  ndarray<double,2>& mom2);
  /*
   * Accumulate the first and second moment arrays with a weight factor
   */
  static void variance_accumulate(double wt,
                                  const ndarray<const double,2>& input,
                                  ndarray<double,2>& mom1,
                                  ndarray<double,2>& mom2);
  /**
   * Accumulate the first and second moment arrays and calculate the root-mean-squares of all array elements
   * from the accumulated n events.
   */
  static void variance_calculate (double wt,
                                  const ndarray<const double,2>& input,
                                  ndarray<double,2>& mom1,
                                  ndarray<double,2>& mom2,
                                  unsigned n,
                                  ndarray<double,2>& rms);

  /*
   * Accumulate the first and second moment arrays from unsigned data.
   */

  static void variance_accumulate(double off,
                                  const ndarray<const unsigned,2>& input,
                                  ndarray<double,2>& mom1,
                                  ndarray<double,2>& mom2);
  /*
   * Accumulate the first and second moment arrays with a weight factor
   */
  static void variance_accumulate(double wt,
                                  double off,
                                  const ndarray<const unsigned,2>& input,
                                  ndarray<double,2>& mom1,
                                  ndarray<double,2>& mom2);
  /**
   * Accumulate the first and second moment arrays and calculate the root-mean-squares of all array elements
   * from the accumulated n events.
   */
  static void variance_calculate (double wt,
                                  double off,
                                  const ndarray<const unsigned,2>& input,
                                  ndarray<double,2>& mom1,
                                  ndarray<double,2>& mom2,
                                  unsigned n,
                                  ndarray<unsigned,2>& rms);

  /**
   * @ingroup Moments
   *
   * @brief Calculate moments of 1-D array
   *
   *  The moments are { sum of bin_values,
   *                    sum of bin_value*bin_position,
   *                    sum of bin_value*bin_position**2 }
   *
   *  The bin_position is calculate as bin_offset + bin_index*bin_scale
   *
   */
  static ndarray<double,1> moments(const ndarray<const double  ,1>& input,
                                   double bin_offset,
                                   double bin_scale);
  static ndarray<double,1> moments(const ndarray<const double  ,1>& num,
                                   const ndarray<const double  ,1>& den,
                                   double bin_offset,
                                   double bin_scale);
  /*
   * @brief Calculate moments of 2-D array
   *
   *  The moments are { sum of bins,
   *                    sum of bin_values,
   *                    sum of bin_values**2,
   *                    sum of bin_value*bin_xposition,
   *                    sum of bin_value*bin_yposition }
   *
   *  The bin_value is calculated as the array element value minus the
   *  value_offset.  The bin_xposition(yposition) is simply the array index 
   *  for dimension 1(0).
   *
   *  Integral = moments[1]
   *  Mean     = moments[1]/moments[0]
   *  RMS      = sqrt((moments[2]/moments[0] - (moments[1]/moments[0])**2)
   *  Contrast = sqrt(moments[0]*moments[2]/moments[1]**2 - 1)
   *  X-center-of-mass = moments[3]/moments[1]
   *  Y-center-of-mass = moments[4]/moments[1]
   */
  static ndarray<double,1> moments(const ndarray<const unsigned,2>& input,
                                   double value_offset);
  static ndarray<double,1> moments(const ndarray<const unsigned,2>& input,
                                   double value_offset,
                                   unsigned bounds[][2]);
  static ndarray<double,1> moments(const ndarray<const double,2>&   input,
                                   double value_offset);
  static ndarray<double,1> moments(const ndarray<const double,2>&   input,
                                   double value_offset,
                                   unsigned bounds[][2]);


  /*
   *  Only calculate moments for elements that have a mask bit set.
   *  input[i][j] is used if:
   *    row_mask[i>>5] & (1<<(i&0x1f)), and
   *    mask[i][j>>5] & (1<<(j&0x1f))
   */
  static ndarray<double,1> moments(const ndarray<const unsigned,2>& input,
                                   const ndarray<const unsigned,1>& row_mask,
                                   const ndarray<const unsigned,2>& mask,
                                   double value_offset);
  static ndarray<double,1> moments(const ndarray<const unsigned,2>& input,
                                   const ndarray<const unsigned,1>& row_mask,
                                   const ndarray<const unsigned,2>& mask,
                                   double value_offset,
                                   unsigned bounds[][2]);
  static ndarray<double,1> moments(const ndarray<const double,2>&   input,
                                   const ndarray<const unsigned,1>& row_mask,
                                   const ndarray<const unsigned,2>& mask,
                                   double value_offset);
  static ndarray<double,1> moments(const ndarray<const double,2>&   input,
                                   const ndarray<const unsigned,1>& row_mask,
                                   const ndarray<const unsigned,2>& mask,
                                   double value_offset,
                                   unsigned bounds[][2]);


  /*
   * @brief Find extremes of 2-D array
   *
   *  The extremes are { minimum bin value,
   *                     maximum bin value }
   */
  static ndarray<unsigned,1> extremes(const ndarray<const unsigned,2>& input);
  static ndarray<unsigned,1> extremes(const ndarray<const unsigned,2>& input,
                                      unsigned bounds[][2]);
  static ndarray<double,1>   extremes(const ndarray<const double,2>&   input);
  static ndarray<double,1>   extremes(const ndarray<const double,2>&   input,
                                      unsigned bounds[][2]);

  /*
   *  Only find extremes for elements that have a mask bit set.
   *  input[i][j] is used if:
   *    row_mask[i>>5] & (1<<(i&0x1f)), and
   *    mask[i][j>>5] & (1<<(j&0x1f))
   */
  static ndarray<unsigned,1> extremes(const ndarray<const unsigned,2>& input,
                                      const ndarray<const unsigned,1>& row_mask,
                                      const ndarray<const unsigned,2>& mask);
  static ndarray<unsigned,1> extremes(const ndarray<const unsigned,2>& input,
                                      const ndarray<const unsigned,1>& row_mask,
                                      const ndarray<const unsigned,2>& mask,
                                      unsigned bounds[][2]);
  static ndarray<double,1>   extremes(const ndarray<const double,2>&   input,
                                      const ndarray<const unsigned,1>& row_mask,
                                      const ndarray<const unsigned,2>& mask);
  static ndarray<double,1>   extremes(const ndarray<const double,2>&   input,
                                      const ndarray<const unsigned,1>& row_mask,
                                      const ndarray<const unsigned,2>& mask,
                                      unsigned bounds[][2]);


  /**
   * @ingroup EdgeFinder
   *
   * @brief Waveform pulse edge finder
   *
   * Generates an array of hit times and amplitudes for waveform
   * leading (trailing) edges using a constant fraction discriminator
   * algorithm.  The baseline and minimum amplitude threshold are used
   * for discriminating hits.  The pulse height fraction at which the hit
   * time is derived is also required as input.  Note that if the threshold
   * is less than the baseline value, then leading edges are "falling" and 
   * trailing edges are "rising".  In order for two pulses to be discriminated,
   * the waveform samples below the two pulses must fall below (or above for
   * negative pulses) the fractional value of the threshold; i.e. 
   * waveform[i] < fraction*(threshold+baseline).
   *
   * The results are stored in a 2D array such that result[i][0] is the time 
   * (waveform sample) of the i'th hit and result[i][1] is the maximum amplitude 
   * of the i'th hit.
   *
   */
  static ndarray<double,2>
    find_edges(const ndarray<const double,1>& waveform,
               double baseline,
               double threshold,
               double fraction=0.5,
               double deadtime=0,
               bool   leading_edges=true);

  /**
   * @ingroup HitFinder
   *
   * @brief Image hit finder
   *
   * Generates a 2D map of hits, where a hit is defined as a local maximum above
   * some threshold.  The threshold can be a single value or a map of values.
   *
   * The results are stored in a 2D array with the same dimensions as the input image.
   *
   */
  /*
   *  Increment an output element when the input element is a local maximum and is
   *  above threshold.  Threshold is either a constant or a map of threshold values.
   */
  static void count_hits(const ndarray<const unsigned,2>& input,
                         unsigned threshold,
                         ndarray<unsigned,2>& output);

  static void count_hits(const ndarray<const unsigned,2>& input,
                         const ndarray<const unsigned,2>& threshold,
                         ndarray<unsigned,2>& output);

  /*
   *  Sum the input element's value into the output element when the input is a local
   *  maximum and is above threshold.  The value of offset is subtracted from the
   *  input value before adding to the output.
   */
  static void sum_hits(const ndarray<const unsigned,2>& input,
                       unsigned threshold,
                       unsigned offset,
                       ndarray<unsigned,2>& output);
  static void sum_hits(const ndarray<const unsigned,2>& input,
                       const ndarray<const unsigned,2>& threshold,
                       unsigned offset,
                       ndarray<unsigned,2>& output);
  
  /*
   *  Increment output elements for all input elements above threshold.
   *  The threshold can be a single value or a map of values.
   */
  static void count_excess(const ndarray<const unsigned,2>& input,
                           unsigned threshold,
                           ndarray<unsigned,2>& output);
  
  static void count_excess(const ndarray<const unsigned,2>& input,
                           const ndarray<const unsigned,2>& threshold,
                           ndarray<unsigned,2>& output);

  /*
   *  Sum the input element's value into the output element when the input is
   *  above threshold.  The value of offset is subtracted from the input value 
   *  before adding to the output.
   */
  static void sum_excess(const ndarray<const unsigned,2>& input,
                         unsigned threshold,
                         unsigned offset,
                         ndarray<unsigned,2>& output);
  static void sum_excess(const ndarray<const unsigned,2>& input,
                         const ndarray<const unsigned,2>& threshold,
                         unsigned offset,
                         ndarray<unsigned,2>& output);


  /**
   * @ingroup PeakFit
   *
   * @brief 1D Peak find
   *
   *  Find the peak value in the array.
   *  Variable norm is number of entries summed into each bin.
   *
   */
  static double find_peak(const ndarray<const double,1>& input,
                          double norm,
                          const ndarray<const double,1>& baseline,
                          unsigned& index_peak);
  static double find_peak(const ndarray<const double,1>& input,
                          const ndarray<const double,1>& norm,
                          const ndarray<const double,1>& baseline,
                          unsigned& index_peak);

  /*
   *  Find up to <max_peaks> peaks in the array where each
   *  neighboring peak settles to <frac> of its amplitude before the 
   *  another peak is allowed.
   */
  static std::list<unsigned> find_peaks(const ndarray<const double,1>&,
					double frac,
					unsigned max_peaks);

  /*
   * @brief 1D Linear fit
   *
   *  Variable norm is number of entries summed into each bin.
   *
   */
  static ndarray<double,1> line_fit(const ndarray<const double,1>& input,
                                    const ndarray<const unsigned,1>& pos,
                                    double norm);
  static ndarray<double,1> line_fit(const ndarray<const double,1>& input,
                                    const ndarray<const unsigned,1>& pos,
                                    const ndarray<const double,1>& norm);
  /*
   * @brief Distribution Root-mean-square
   *
   *  Width of distribution is estimated by the root-mean-square.
   *  A baseline polynomial { f(i) = b[0] + i*b[1] + i*i*b[2] + ... }
   *  is subtracted from each point prior to the rms calculation.
   *  Points below the baseline contribute negatively to the rms.
   */
  static double dist_rms(const ndarray<const double,1>& input,
                         double norm,
                         const ndarray<const double,1>& baseline);
  static double dist_rms(const ndarray<const double,1>& input,
                         const ndarray<const double,1>& norm,
                         const ndarray<const double,1>& baseline);
  /*
   * @brief Distribution Full-width-half-maximum
   *
   *  Width of distribution is estimated by the minimum full-width
   *  half-maximum around the peak value.
   */
  static double dist_fwhm(const ndarray<const double,1>& input,
                          double norm,
                          const ndarray<const double,1>& baseline);
  static double dist_fwhm(const ndarray<const double,1>& input,
                          const ndarray<const double,1>& norm,
                          const ndarray<const double,1>& baseline);
  /*
   * @brief Parabolic interpolation
   *
   *  Perform a quadratic interpolation around the peak of the distribution.
   *  A baseline polynomial { f(i) = b[0] + i*b[1] + i*i*b[2] + ... }
   *  is subtracted from each point prior to the calculation.
   *  Return value is an array of [ amplitude, position ]
   */
  static ndarray<double,1> parab_interp(const ndarray<const double,1>& input,
                                        double norm,
                                        const ndarray<const double,1>& baseline);
  static ndarray<double,1> parab_interp(const ndarray<const double,1>& input,
                                        const ndarray<const double,1>& norm,
                                        const ndarray<const double,1>& baseline);
  /*
   *  Perform a least squares fit of the waveform to a 2nd-order polynomial.
   *  Assumes all points have equal uncertainty.
   *  Return value is an array of polynomial coefficients, such that 
   *  y(x) = a[0] + a[1]*x + a[2]*x**2
   *  Maximum/minimum value is a[0]-a[1]*a[1]/(4*a[2]) at x=-a[1]/(2*a[2]).
   *  Return array is [0,0,0] when fit fails.
   */
  static ndarray<double,1> parab_fit(const ndarray<const double,1>& input);
  /*
   *  Fits the upper <frac> portion of the peak at location <x0> with
   *  the above routine.
   */
  static ndarray<double,1> parab_fit(const ndarray<const double,1>& input,
                                     unsigned x0,
                                     double frac);

  template <typename T>
    static void commonMode(const T* data, const uint16_t* mask, const unsigned length, const T threshold, const T maxCorrection, T& cm);  
  template <typename T>
    static void commonMode(T* data, const uint16_t* mask, const unsigned length, const T threshold, const T maxCorrection, T& cm);  
  template <typename T>
    static void commonModeMedian(const T* data, const uint16_t* mask, const unsigned length, const T threshold, const T maxCorrection, T& cm);  
  template <typename T>
    static void commonModeMedian(T* data, const uint16_t* mask, const unsigned length, const T threshold, const T maxCorrection, T& cm);  
  

  /**
   *
   *  Calculate a common-mode in left-right halves for odd-even pixels
   *
   */
  static ndarray<const double,1> commonModeLROE(const ndarray<const int32_t,1>& a,
						const ndarray<const double,1>&   baseline);

  /**
   *
   *  Calculate a common-mode in left-right halves for odd-even pixels
   *
   */
  static ndarray<const double,2> commonModeLROE(const ndarray<const int32_t,2>& a,
						const ndarray<const double,2>&   baseline);

  /**
   * @ingroup ndarray manipulation
   *
   * @brief Project ndarray
   *
   * Creates a 1-dimensional response array from the
   * projection of an N-dimensional ndarray over a region of interest (inclusive).
   * 
   *  pdim is the dimension to project onto.
   *  All other dimensions are integrated over the ROI
   */
  static ndarray<const int,1> 
    project(const ndarray<const uint16_t,2>& input,
	          const unsigned* roi_lo,
	          const unsigned* roi_hi,
            unsigned pedestal,
	          unsigned pdim);

  /**
   * @ingroup ndarray manipulation
   *
   * @brief Project ndarray
   *
   * Creates a 1-dimensional response array from the
   * projection of an N-dimensional ndarray over a region of interest (inclusive).
   * 
   *  pdim is the dimension to project onto.
   *  All other dimensions are integrated over the ROI
   */
  static ndarray<double,1> 
    project(const ndarray<const double,2>& input,
	          const unsigned* roi_lo,
	          const unsigned* roi_hi,
            double pedestal,
	          unsigned pdim);

  /**
   * @ingroup ndarray manipulation
   *
   * @brief Project ndarray
   *
   * Creates a 1-dimensional response array from the
   * projection of an N-dimensional ndarray over the full array.
   * 
   *  pdim is the dimension to project onto.
   *  All other dimensions are integrated
   */
  static ndarray<const int,1> 
    project(const ndarray<const uint16_t,2>& input,
            unsigned pedestal,
	          unsigned pdim);

  /**
   * @ingroup ndarray manipulation
   *
   * @brief Project ndarray
   *
   * Creates a 1-dimensional response array from the
   * projection of an N-dimensional ndarray over the full array.
   * 
   *  pdim is the dimension to project onto.
   *  All other dimensions are integrated
   */
  static ndarray<double,1> 
    project(const ndarray<const double,2>& input,
            double pedestal,
	          unsigned pdim);

  /**
   * @ingroup ndarray manipulation
   *
   * @brief Roi ndarray
   *
   * Creates a 2-dimensional array from a 2-dimensional ndarray
   * usin a region of interest (inclusive).
   * 
   */
  static ndarray<const int,2> 
    roi(const ndarray<const uint16_t,2>& input,
	    const unsigned* roi_lo,
	    const unsigned* roi_hi,
            unsigned pedestal);


  /**
   *
   *  Accumulate a rolling average where each accumulation contributes
   *  a fixed fraction to the average.
   *
   */
  template <typename I>
  static void rolling_average(const ndarray<const I,1>& a,
			      ndarray<double,1>&        avg,
			      double                    fraction);

  /**
   *
   *  Accumulate a rolling average where each accumulation contributes
   *  a fixed fraction to the average.
   *
   */
  template <typename I>
  static void rolling_average(const ndarray<const I,2>& a,
			      ndarray<double,2>&        avg,
			      double                    fraction);
};

#endif // PSALG_PSALG_H
