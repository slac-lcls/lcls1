#include "psalg/psalg.h"
#include <math.h>
#include <string.h>

static double poly(const ndarray<const double,1>& p,
                   double x)
{
  unsigned j = p.shape()[0]-1;
  double b = p[j];
  while(j--)
    b = p[j] + x*b;
  return b;
}

ndarray<double,1> psalg::line_fit (const ndarray<const double,1>& input,
                                   const ndarray<const unsigned,1>& pos,
                                   double norm)
{
  double aa, bb;
  double x = 0, xy = 0, x2 = 0, y = 0;
  int n = 0;
  for (unsigned i = 0; i < input.shape()[0]; i++) {
    double yv = input[i]/norm;
    unsigned j = pos[i];
    x += double(j);
    x2 += double(j*j);
    y += yv;
    xy += j*yv;
    n++;
  }
  double dn = double(n);
  bb = (xy - x * y / dn) / (x2 - x * x / dn);
  aa = (y - bb * x) / dn;

  ndarray<double,1> result=make_ndarray<double>(2);
  result[0] = aa;
  result[1] = bb;
  return result;
}

ndarray<double,1> psalg::line_fit (const ndarray<const double,1>& input,
                                   const ndarray<const unsigned,1>& pos,
                                   const ndarray<const double,1>& norm)
{
  double aa, bb;
  double x = 0, xy = 0, x2 = 0, y = 0;
  int n = 0;
  for (unsigned i = 0; i < input.shape()[0]; i++) {
    if (norm[i]>0) {
      double yv = input[i]/norm[i];
      unsigned j = pos[i];
      x += double(j);
      x2 += double(j*j);
      y += yv;
      xy += j*yv;
      n++;
    }
  }
  double dn = double(n);
  bb = (xy - x * y / dn) / (x2 - x * x / dn);
  aa = (y - bb * x) / dn;

  ndarray<double,1> result=make_ndarray<double>(2);
  result[0] = aa;
  result[1] = bb;
  return result;
}

double psalg::dist_rms(const ndarray<const double,1>& input,
                       double norm,
                       const ndarray<const double,1>& baseline)
{
  double y=0;
  double x0=0, x1=0, x2=0;
  for(unsigned i=0; i<input.shape()[0]; i++) {
    double b = poly(baseline, double(i));
    double v  = input[i]/norm - b;
    double vi = v*double(i);
    x0 += v;
    x1 += vi;
    x2 += vi*double(i);
  }
  if (x0>0) {
    x1 /= x0;
    x2 /= x0;
    y = sqrt(x2-x1*x1);
  }
  return y;
}

double psalg::dist_rms(const ndarray<const double,1>& input,
                       const ndarray<const double,1>& norm,
                       const ndarray<const double,1>& baseline)
{
  double y=0;
  double x0=0, x1=0, x2=0;
  for(unsigned i=0; i<input.shape()[0]; i++) {
    if (norm[i]>0) {
      double b = poly(baseline, double(i));
      double v  = input[i]/norm[i] - b;
      double vi = v*double(i);
      x0 += v;
      x1 += vi;
      x2 += vi*double(i);
    }
  }
  if (x0>0) {
    x1 /= x0;
    x2 /= x0;
    y = sqrt(x2-x1*x1);
  }
  return y;
}

double psalg::find_peak(const ndarray<const double,1>& input,
                        double norm,
                        const ndarray<const double,1>& baseline,
                        unsigned& v)
{
  v=0;
  double y= input[0]/norm - poly(baseline,0.);
  for(unsigned i=0; i<input.shape()[0]; i++) {
    double b = poly(baseline, double(i));
    double z = input[i]/norm-b;
    if (z > y) { y=z; v=i; }
  }
  return y;
}

double psalg::find_peak(const ndarray<const double,1>& input,
                        const ndarray<const double,1>& norm,
                        const ndarray<const double,1>& baseline,
                        unsigned& v)
{
  v=0;
  double y= norm[0]>0 ? input[0]/norm[0] - poly(baseline,0.) : -1;
  for(unsigned i=0; i<input.shape()[0]; i++) {
    if (norm[i]>0) {
      double b = poly(baseline, double(i));
      double z = input[i]/norm[i]-b;
      if (z > y) { y=z; v=i; }
    }
  }
  return y;
}

double psalg::dist_fwhm(const ndarray<const double,1>& input,
                        const ndarray<const double,1>& norm,
                        const ndarray<const double,1>& baseline)
{
  double result = 0;

  unsigned v;
  double y = psalg::find_peak(input,norm,baseline,v);
  
  bool valid = v>0 || y>0;
  if (valid) {
    double y2 = 0.5*y;
    if (y2 > 0) {
      //
      //  iterate left of the peak 
      //    
      double x0=0;      // location of half-maximum left of the peak
      { double   x =y;  // value of last valid point
	unsigned xi=v;  // index of last valid point
	int       i=v-1;// test index
	valid      =false;
	while(i>0) {
          if (norm[i]>0) {
            double z = input[i]/norm[i]-poly(baseline,double(i));
	    if (z < y2) {  // found it. interpolate
	      x0 = (double(i)*(x-y2) + double(xi)*(y2-z)) / (x-z);
	      valid = true;
	      break;
	    }
	    x  = z;
	    xi = i;
	  }
	  i--;
	}
	if (valid) {
          //
          //  iterate right of the peak
          //
          double x1=input.shape()[0]; // location of half-maximum right of the peak
          { double   x =y;            // value of last valid point
            unsigned xi=v;            // index of last valid point 
            unsigned i=v+1;           // test index
            valid     =false;
            while(i<input.shape()[0]) {
              if (norm[i]>0) {
                double z = input[i]/norm[i]-poly(baseline,double(i));
                if (z < y2) {  // found it. interpolate
                  x1 = (double(i)*(x-y2) + double(xi)*(y2-z)) / (x-z);
                  valid = true;
                  break;
                }
                x  = z;
                xi = i;
              }
              i++;
            }
            if (valid)
              result = (x1-x0);
          }
        }
      }
    }
  }

  return result;
}

double psalg::dist_fwhm(const ndarray<const double,1>& input,
                        double norm,
                        const ndarray<const double,1>& baseline)
{
  double result = 0;

  unsigned v;
  double y = psalg::find_peak(input,norm,baseline,v);
  
  bool valid = v>0 || y>0;
  if (valid) {
    double y2 = 0.5*y;
    if (y2 > 0) {
      //
      //  iterate left of the peak 
      //    
      double x0=0;      // location of half-maximum left of the peak
      { double   x =y;  // value of last valid point
	unsigned xi=v;  // index of last valid point
	int       i=v-1;// test index
	valid      =false;
	while(i>0) {
          double z = input[i]/norm-poly(baseline,double(i));
          if (z < y2) {  // found it. interpolate
            x0 = (double(i)*(x-y2) + double(xi)*(y2-z)) / (x-z);
            valid = true;
            break;
          }
          x  = z;
          xi = i;
	  i--;
	}
	if (valid) {
          //
          //  iterate right of the peak
          //
          double x1=input.shape()[0]; // location of half-maximum right of the peak
          { double   x =y;            // value of last valid point
            unsigned xi=v;            // index of last valid point 
            unsigned i=v+1;           // test index
            valid     =false;
            while(i<input.shape()[0]) {
              double z = input[i]/norm-poly(baseline,double(i));
              if (z < y2) {  // found it. interpolate
                x1 = (double(i)*(x-y2) + double(xi)*(y2-z)) / (x-z);
                valid = true;
                break;
              }
              x  = z;
              xi = i;
              i++;
            }
            if (valid)
              result = (x1-x0);
          }
        }
      }
    }
  }

  return result;
}

ndarray<double,1> psalg::parab_interp(const ndarray<const double,1>& input,
                                      double norm,
                                      const ndarray<const double,1>& baseline)
{
  ndarray<double,1> result = make_ndarray<double>(2);

  unsigned v;
  double y = psalg::find_peak(input,norm,baseline,v);

  if (y<0 || v==0) {  // maximum is at the left edge (or below baseline)
    result[0] = 0;
    result[1] = 0;
  }
  else if (v >= input.shape()[0]-1) {  // maximum is at the right edge
    result[0] = 0;
    result[1] = input.shape()[0];
  }
  else {
    //
    //  Find the first valid points left and right of the peak
    //
    int il=v-1; // test index
    if (il > 0) {
      double yl = input[il]/norm - poly(baseline,double(il));
      unsigned ir=v+1; // test index
      if (ir < input.shape()[0]) {
        double yr = input[ir]/norm - poly(baseline,double(ir));
      	double di  = double(ir-il);
        double  a  = (yl-y)/double(il-v) - (yr-y)/double(ir-v);
        if (a==0) {  // flat at the maximum
          result[0] = y;
          result[1] = v;
        }
        else {       // success
          a /= di;
          double  b  = 0.5*(il+ir-(yl-yr)/(a*di));
          result[0] = y + a*pow(v-b,2);
          result[1] = b;
        }
      }
      else {  // no valid points to the right of maximum
        result[0] = y;
        result[1] = input.shape()[0];
      }
    }
    else {  // no valid points to the left of maximum
      result[0] = y;
      result[1] = 0;
    }
  }
  return result;
}

std::list<unsigned> psalg::find_peaks(const ndarray<const double,1>& a,
                                      double afrac,
                                      unsigned max_peaks)
{
  std::list<unsigned> peaks;

  double amax    = a[0];
  double aleft   = amax;
  double aright  = 0;
  unsigned imax  = 0;

  bool lpeak = false;

  for(unsigned i=1; i<a.shape()[0]; i++) {
    if (a[i] > amax) {
      amax = a[i];
      double af = afrac*amax;
      if (af > aleft) {
        imax = i;
        lpeak  = true;
        aright = af;
      }
    }
    else if (lpeak && a[i] < aright) {
      if (peaks.size()==max_peaks && a[peaks.back()]>amax)
        ;
      else {
        if (peaks.size()==max_peaks)
          peaks.pop_back();

        int sz = peaks.size();
        for(std::list<unsigned>::iterator it=peaks.begin(); it!=peaks.end(); it++)
          if (a[*it]<amax) {
            peaks.insert(it,imax);
            break;
          }
        if (sz == int(peaks.size()))
          peaks.push_back(imax);
      }

      lpeak = false;
      amax  = aleft = (a[i]>0 ? a[i] : 0);
    }
    else if (!lpeak && a[i] < aleft) {
      amax = aleft = (a[i] > 0 ? a[i] : 0);
    }
  }
  return peaks;
}

ndarray<double,1> psalg::parab_interp(const ndarray<const double,1>& input,
                                      const ndarray<const double,1>& norm,
                                      const ndarray<const double,1>& baseline)
{
  ndarray<double,1> result = make_ndarray<double>(2);

  unsigned v;
  double y = psalg::find_peak(input,norm,baseline,v);

  if (y<0 || v==0) {  // maximum is at the left edge (or below baseline)
    result[0] = 0;
    result[1] = 0;
  }
  else if (v >= input.shape()[0]-1) {  // maximum is at the right edge
    result[0] = 0;
    result[1] = input.shape()[0];
  }
  else {
    //
    //  Find the first valid points left and right of the peak
    //
    int il=v-1; // test index
    double yl;
    while(il>0) {
      if (norm[il]>0) {
        yl = input[il]/norm[il] - poly(baseline,double(il));
        break;
      }
      il--;
    }

    if (il > 0) {
      unsigned ir=v+1; // test index
      double yr;
      while(ir<input.shape()[0]) {
        if (norm[ir]>0) {
          yr = input[ir]/norm[ir] - poly(baseline,double(ir));
          break;
        }
        ir++;
      }
      if (ir < input.shape()[0]) {
      	double di  = double(ir-il);
        double  a  = (yl-y)/double(il-v) - (yr-y)/double(ir-v);
        if (a==0) {  // flat at the maximum
          result[0] = y;
          result[1] = v;
        }
        else {       // success
          a /= di;
          double  b  = 0.5*(il+ir-(yl-yr)/(a*di));
          result[0] = y + a*pow(v-b,2);
          result[1] = b;
        }
      }
      else {  // no valid points to the right of maximum
        result[0] = 0;
        result[1] = input.shape()[0];
      }
    }
    else {  // no valid points to the left of maximum
      result[0] = 0;
      result[1] = 0;
    }
  }
  return result;
}

//
//  Fit a quadratic f(x) = c[2]x**2 + c[1]x + c[0] 
//  via least squares.
//
ndarray<double,1> psalg::parab_fit(const ndarray<const double,1>& input)
{
  ndarray<double,1> result = make_ndarray<double>(3);
  
  double xx[5], xy[3];
  memset(xx,0,5*sizeof(double));
  memset(xy,0,3*sizeof(double));
        
  for(unsigned ix=0; ix<input.shape()[0]; ix++) {
    double x = double(ix);
    double qx=x;
    double y = input[ix];
    xx[0] += 1;
    xy[0] += y;
    xx[1] += x;
    xy[1] += (y*=x);
    xx[2] += (qx*=x);
    xy[2] += y*x;
    xx[3] += (qx*=x);
    xx[4] += qx*x;
  }

  double a11 = xx[0];
  double a21 = xx[1];
  double a31 = xx[2];
  double a22 = xx[2];
  double a32 = xx[3];
  double a33 = xx[4];

  double b11 = a22*a33-a32*a32;
  double b21 = a21*a33-a32*a31;
  double b31 = a21*a32-a31*a22;
  double b22 = a11*a33-a31*a31;
  double b32 = a11*a32-a21*a31;
  double b33 = a11*a22-a21*a21;

  double det = a11*b11 - a21*b21 + a31*b31;

  if (det==0) {
    result[0] = 0;
    result[1] = 0;
    result[2] = 0;
  }
  else {
    result[0] = ( b11*xy[0] - b21*xy[1] + b31*xy[2])/det;
    result[1] = (-b21*xy[0] + b22*xy[1] - b32*xy[2])/det;
    result[2] = ( b31*xy[0] - b32*xy[1] + b33*xy[2])/det;
  }
  return result;
}

ndarray<double,1> psalg::parab_fit(const ndarray<const double,1>& input,
                                   unsigned ix,
                                   double afrac)
{
  enum { Amplitude, Position, FWHM, NParms };
  ndarray<double,1> _p = make_ndarray<double>(NParms);

  const double trf = afrac*input[ix];
  int ix_left(ix);
  while(--ix_left > 0) {
    if (input[ix_left] < trf)
      break;
  }

  int ix_right(ix);
  while(++ix_right < int(input.shape()[0])) {
    if (input[ix_right] < trf)
      break;
  }

  ndarray<double,1> a = psalg::parab_fit(make_ndarray(&input[ix_left],
                                                      ix_right-ix_left+1));

  if (a[2] < 0) {  // a maximum
    _p[Amplitude] = a[0] - 0.25*a[1]*a[1]/a[2];
    _p[Position ] = double(ix_left)-0.5*a[1]/a[2];

    const double hm = 0.5*input[ix];
    while(input[ix_left]>hm && ix_left>0)
      ix_left--;
    while(input[ix_right]>hm && ix_right<int(input.shape()[0]-1))
      ix_right++;

    _p[FWHM] = sqrt(-2*_p[Amplitude]/a[2]);
  }
  else {
    _p[Amplitude] = -1;
    _p[Position ] = -1;
    _p[FWHM] = -1;
  }
  return _p;
}
