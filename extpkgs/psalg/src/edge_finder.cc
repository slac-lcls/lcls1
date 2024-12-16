#include "psalg/psalg.h"
#include <iostream>
#include <list>

static void _add_edge(ndarray<const double,1> v,
                      bool                    rising,   // leading positive edge, or trailing negative edge
                      double                  fraction_value,
                      double                  deadtime,
                      double                  peak, 
                      unsigned                start, 
                      double&                 last,
                      std::list< ndarray<double,1> >& result);

/*
 * Find leading or trailing edges
 */
ndarray<double,2>
psalg::find_edges(const ndarray<const double,1>& wf,
                  double baseline_value,
                  double threshold_value,
                  double fraction,
                  double deadtime,
                  bool   leading_edge)
{
  std::list< ndarray<double,1> > result;

  double   peak   = threshold_value;
  unsigned start  = 0;
  double   last   = -deadtime-1.0;
  bool     rising = threshold_value > baseline_value; // M.D.: odd definition which does not allow to use baseline...
  bool     crossed=false;

  /*
  std::cout << "XXX:baseline_value: " << baseline_value
            << " threshold_value: " << threshold_value
            << " fraction: " << fraction
            << " deadtime: " << deadtime
            << " leading_edge: " << leading_edge
            << " wf.shape()[0]: " << wf.shape()[0]
            << " rising: " << rising
            << " crossed: " << crossed
            << " last: " << last
            << '\n';
  */

  for(unsigned k=0; k<wf.shape()[0]; k++) {
    double y = wf[k];
    bool over = 
      ( rising && y>threshold_value) ||
      (!rising && y<threshold_value);
    if (!crossed && over) {
      crossed = true;
      start   = k;
      peak    = y;
    }
    else if (crossed && !over) {
      crossed = false;
      int width = k-start;
      if (width>deadtime)
          _add_edge(wf, rising==leading_edge,
                    fraction*(peak-baseline_value),
                    deadtime, peak, start, last, result);
    }
    else if (( rising && y>peak) ||
             (!rising && y<peak)) {
      peak = y;
      if (!leading_edge)  // For a trailing edge, start at the peak!
        start = k;
    }
  }
    
  //  The last edge may not have fallen back below threshold
  if (crossed) {
    _add_edge(wf, rising==leading_edge,
              fraction*(peak-baseline_value),
              deadtime, peak, start, last, result);
  }

  unsigned shape[] = {(unsigned) result.size(),2};
  ndarray<double,2> edges(shape);

  unsigned k=0;
  for(std::list< ndarray<double,1> >::iterator it=result.begin();
      it!=result.end(); it++,k++) {
    edges(k,0) = (*it)[0];
    edges(k,1) = (*it)[1];
  }
  return edges;
}

void _add_edge(ndarray<const double,1> v,
               bool                    rising,   // leading positive edge, or trailing negative edge
	       double                  fraction_value,
               double                  deadtime,
	       double                  peak, 
	       unsigned                start, 
	       double&                 last,
	       std::list< ndarray<double,1> >& result)
{
  //  find the edge
  double edge_v = fraction_value;
  unsigned i=start;
  if (rising) {
    while(v[i] < edge_v)
      i++;
  }
  else {                           // trailing positive edge, or leading negative edge
    while(v[i] > edge_v)
      i++;
  }
  double edge = i>0 ? 
    (edge_v-v[i])/(v[i]-v[i-1])
    + double(i) : 0;

  if (last < 0 || edge > last + deadtime) {
    ndarray<double,1> a = make_ndarray<double>(2);
    a[0] = peak;
    a[1] = edge;
    result.push_back(a);
    last = edge;
  }
}
