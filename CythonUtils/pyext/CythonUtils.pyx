import numpy as np
cimport numpy as np

# taken for this document:
# http://oceanoptics.com/wp-content/uploads/OOINLCorrect-Linearity-Coeff-Proc.pdf
# where it says:
#
# We correct for the nonlinearity of the detector by running an
# experiment where we vary the amount of light the detector receives; we
# keep the intensity of the light source constant but vary the
# integration time. When we analyze this data, we have a number of
# points that are counts/sec vs. counts. We look at 9 pixels across the
# detector (the nonlinearity of each pixel is identical) and normalize
# each pixel's counts/sec to 1. When we combine the data from all 9
# pixels, they overlap on a plot of normalized counts/sec vs. counts. We
# fit this smooth function to a 7th order polynomial. This polynomial
# produces a correction factor for each intensity. If we observe 2000
# counts, we plug 2000 into the resulting polynomial and get a number
# less than 1 (typically around 0.9). We divide the number of counts by
# this correction factor.

def oceanNonLinCorr(np.ndarray[np.uint16_t] input, np.ndarray[np.float64_t] poly):
    cdef int nelem = input.shape[0]
    cdef np.ndarray[np.float64_t] calib = np.empty_like(input,dtype=np.float64)
    cdef int polyorder = poly.shape[0]
    cdef int i,j
    cdef float polyval
    for i in range(nelem):
        polyval = poly[0]
        for j in range(1,polyorder):
            polyval+=poly[j]*(input[i]**j)
        calib[i]=input[i]/polyval
    return calib
