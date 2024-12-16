#include <psalg/psalg.h>

ndarray<double,1>
psalg::finite_impulse_response(const ndarray<const double,1>& filter,
                               const ndarray<const double,1>& sample)
{
  unsigned no_shape[] = {0};
  if (sample.shape()[0]<filter.shape()[0])
    return ndarray<double,1>(no_shape);
  else {
    unsigned len = sample.shape()[0]-filter.shape()[0];
    ndarray<double,1> result = ndarray<double,1>(&len);
    for(unsigned i=0; i<len; i++) {
      double v = 0;
      for(unsigned j=0; j<filter.shape()[0]; j++)
        v += sample[i+j]*filter[j];
      result[i] = v;
    }
    return result;
  }
}

void 
psalg::finite_impulse_response(const ndarray<const double,1>& filter,
                               const ndarray<const double,1>& input,
                               ndarray<double,1>&             output)
{
  int len = int(input.shape()[0])-int(filter.shape()[0])+1;
  if (len > int(output.shape()[0])) 
    len = output.shape()[0];

  unsigned i=0;
  while(i<unsigned(len)) {
    double v = 0;
    for(unsigned j=0; j<filter.shape()[0]; j++)
      v += input[i+j]*filter[j];
    output[i++] = v;
  }
  while(i<output.shape()[0])
    output[i++] = 0;
}
