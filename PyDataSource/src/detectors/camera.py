import PyDataSource
import os

from pylab import *

class Camera(PyDataSource.Detector):
    """Camera Detector Class.
    """

    def __init__(self,*args,**kwargs):

        PyDataSource.Detector.__init__(self,*args,**kwargs)
       
        #self._update_xarray_info()
        if 'roi' in kwargs:
            self.make_roi(kwargs['roi'])    

    def make_roi(self, roi, xaxis=None, yaxis=None, **kwargs):       
        self.add.parameter(roi=roi)
        if not xaxis or len(xaxis) != roi[0][1]-roi[0][0]:
            xaxis = np.arange(roi[0][0],roi[0][1])    
        
        if not yaxis or len(yaxis) != roi[1][1]-roi[1][0]:
            yaxis = np.arange(roi[1][0],roi[1][1])    
        
        self.add.parameter(ximg=xaxis)
        self.add.parameter(yimg=yaxis)

        self._xarray_info['coords'].update({'ximg': self.ximg, 'yimg': self.yimg})
        self._xarray_info['dims'].update({'img': (['ximg', 'yimg'], (self.ximg.size, self.yimg.size))})

    @property
    def img(self, roi=None):
        if not roi and hasattr(self, 'roi'):
            roi = self.roi

        if not self._xarray_info: 
            self._update_xarray_info()

        try:
            if False and self.detector is not None:
                if self.detector.image is not None:
                    img = self.detector.image
                elif self.detector.calib is not None:
                    img = self.detector.calib
                else:
                    img = self.detector.raw

            elif self.evtData:
                if len(self.evtData.data16):
                    img = self.evtData.data16
                else:
                    img =  self.evtData.data8

            else:
                return 

            if roi:
                img = img[roi[0][0]:roi[0][1],roi[1][0]:roi[1][1]]
            
            return img

        except:
            return None


