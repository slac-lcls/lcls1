#include "psalg/psalg.h"

#include <climits>
#include <cfloat>

ndarray<unsigned,1> psalg::extremes(const ndarray<const unsigned,2>& input)
{
  unsigned bounds[][2] = { {0, input.shape()[0] },
                           {0, input.shape()[1] } };
  return psalg::extremes(input, bounds);
}

ndarray<unsigned,1> psalg::extremes(const ndarray<const unsigned,2>& input,
                                    unsigned bounds[][2])
{
  unsigned shape[] = {2};
  ndarray<unsigned,1> m(shape);
  m[0] = UINT_MAX; 
  m[1] = 0;

  for(unsigned j=bounds[0][0]; j<bounds[0][1]; j++)
    for(unsigned k=bounds[1][0]; k<bounds[1][1]; k++) {
      unsigned v = input(j,k);
      if (v<m[0]) m[0]=v;
      if (v>m[1]) m[1]=v;
    }
  return m;
}


ndarray<unsigned,1> psalg::extremes(const ndarray<const unsigned,2>& input,
                                    const ndarray<const unsigned,1>& row_mask,
                                    const ndarray<const unsigned,2>& mask)
{
  unsigned bounds[][2] = { {0, input.shape()[0]},
                           {0, input.shape()[1]} };
  return psalg::extremes(input,row_mask,mask,bounds);
}

ndarray<unsigned,1> psalg::extremes(const ndarray<const unsigned,2>& input,
                                    const ndarray<const unsigned,1>& row_mask,
                                    const ndarray<const unsigned,2>& mask,
                                    unsigned bounds[][2])
{
  unsigned shape[] = {2};
  ndarray<unsigned,1> m(shape);
  m[0] = UINT_MAX; 
  m[1] = 0;

  for(unsigned j=bounds[0][0]; j<bounds[0][1]; j++) {
    if (row_mask[j>>5] & (1<<(j&0x1f))) {
      for(unsigned k=bounds[1][0]; k<bounds[1][1]; k++) {
        if (mask(j,k>>5) & (1<<(k&0x1f))) {
          unsigned v = input(j,k);
          if (v<m[0]) m[0]=v;
          if (v>m[1]) m[1]=v;
        }
      }
    }
  }
  return m;
}

ndarray<double,1> psalg::extremes(const ndarray<const double,2>& input)
{
  unsigned bounds[][2] = { {0, input.shape()[0]},
                           {0, input.shape()[1]} };
  return psalg::extremes(input,bounds);
}

ndarray<double,1> psalg::extremes(const ndarray<const double,2>& input,
                                  unsigned bounds[][2])
{
  unsigned shape[] = {2};
  ndarray<double,1> m(shape);
  m[0] = m[1] = input(bounds[0][0],bounds[1][0]);

  for(unsigned j=bounds[0][0]; j<bounds[0][1]; j++)
    for(unsigned k=bounds[1][0]; k<bounds[1][1]; k++) {
      double v = input(j,k);
      if (v<m[0]) m[0]=v;
      if (v>m[1]) m[1]=v;
    }
  return m;
}

ndarray<double,1> psalg::extremes(const ndarray<const double,2>&   input,
                                  const ndarray<const unsigned,1>& row_mask,
                                  const ndarray<const unsigned,2>& mask)
{
  unsigned bounds[][2] = { {0,input.shape()[0]},
                           {0,input.shape()[1]} };
  return psalg::extremes(input,row_mask,mask,bounds);
}

ndarray<double,1> psalg::extremes(const ndarray<const double,2>&   input,
                                  const ndarray<const unsigned,1>& row_mask,
                                  const ndarray<const unsigned,2>& mask,
                                  unsigned bounds[][2])
{
  unsigned shape[] = {2};
  ndarray<double,1> m(shape);
  m[0] = DBL_MAX;
  m[1] = DBL_MIN;

  for(unsigned j=bounds[0][0]; j<bounds[0][1]; j++)
    if (row_mask[j>>5] & (1<<(j&0x1f))) {
      for(unsigned k=bounds[1][0]; k<bounds[1][1]; k++) {
        if (mask(j,k>>5) & (1<<(k&0x1f))) {
          double v = input(j,k);
          if (v<m[0]) m[0]=v;
          if (v>m[1]) m[1]=v;
        }
      }
    }
  return m;
}
