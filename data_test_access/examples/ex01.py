#!/usr/bin/env python

#import os
#DIR_DATA_TEST = os.path.abspath(os.path.dirname(__file__)).strip('examples')
#DIR_XTC_TEST = os.path.join(DIR_DATA_TEST, 'xtc')
#path = os.path.join(DIR_XTC_TEST, 'xppn4116_run137_3events.xtc')

#import CalibManager.AppDataPath as adp
#path_xtc = 'data_test/xtc'
#path = adp.AppDataPath('%s/xppn4116_run137_3events.xtc' % path_xtc).path()
#path = adp.AppDataPath(path_xtc).path()

import data_test_access.absolute_path as ap
path = ap.path_to_xtc_test_file(fname='data-xppn4116-r0137-3events-epix100a.xtc')

print('path: %s' % path)

if not path:
    import sys
    sys.exit('PATH TO XTC FILE IS EMPTY')

from psana import Detector, DataSource

from Detector.GlobalUtils import info_ndarr
ds = DataSource(path)
det = Detector('XppEndstation.0:Opal1000.1') # 'XppGon.0:Epix100a.1'
for i, evt in enumerate(ds.events()):
    if i<1:
      print('\nevt.keys():')
      for k in evt.keys():
        print(str(k))
      print('\ndet.raw(evt) for %s:' % det.name) # det.source
    print(info_ndarr(det.raw(evt),'Ev#%d:' % i))
    #print(dir(det))

# EOF
