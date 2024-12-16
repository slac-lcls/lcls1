from __future__ import print_function
import psana

ds = psana.DataSource('/reg/g/psdm/detector/data_test/types/0019-XppGon.0-Epix100a.0.xtc')
env = ds.env()
src = psana.Source('XppGon.0:Epix100a.0')

cs      = env.configStore()
clbs    = env.calibStore()
epics   = env.epicsStore()

cdir    = env.calibDir()
exp     = env.experiment()
ins     = env.instrument()

cfgkeys = list(cs.keys())
clbkeys = list(clbs.keys())

co = cs.get(psana.Epix.Config100aV2, src)
vn = co.version()

evt = next(ds.events())
ekeys  = list(evt.keys())
runnum = evt.run()
  
eo = evt.get(psana.Epix.ElementV3, src)

evid = ds.env().configStore().get(psana.EventId)
time = ds.env().configStore().get(psana.EventId).time()
rnum = ds.env().configStore().get(psana.EventId).run()  # returns 0 for moved xtc files

#------------------------------
# Epix detector id
# ----------------
import psana
src = psana.Source('XppGon.0:Epix100a.0')
ds = psana.DataSource('/reg/g/psdm/detector/data_test/types/0019-XppGon.0-Epix100a.0.xtc')
co = ds.env().configStore().get(psana.Epix.Config100aV2, src)
print('Epix detector Id: %d' % co.version())

#------------------------------

import psana

dsn = '/reg/g/psdm/detector/data_test/types/0007-NoDetector.0-Epix100a.0.xtc'
str_src = ':Epix100a.0'

src = psana.Source(str_src)
ds  = psana.DataSource(dsn)
env = ds.env()
amap = env.aliasMap()

asrcs = amap.srcs()

ssrc = str_src # or Epix or alias 'cs140_0'

pdssrc=amap.src(str_src) # returns pdssrc for string source like ProcInfo(255.255.255.255, pid=16777215)

strsrc=amap.src('cs140_0') # string source for alias like DetInfo(XppGon.0:Cspad2x2.0)

evt = next(ds.events())
runnum = evt.run()

#pda = PyDetectorAccess(src, env, pbits=0)

cs = env.configStore()
list(cs.keys())

co = cs.get(psana.Epix.Config100aV1, src)     # (704, 768)

detid = co.version()
#------------------------------
# get time from :Evr.

import psana
ds  = psana.DataSource('/reg/g/psdm/detector/data_test/types/0014-MfxEndstation.0-Rayonix.0.xtc')

env = ds.env()
#co = env.getConfig(psana.ControlData.ConfigV3)
co = env.getConfig(psana.EvrData.ConfigV7)

#run= ds.runs().next()
#lst=run.times() # in idx mode



#env = ds.env()

#cs = env.configStore()
#cs.keys()
#co1 = cs.get(psana.EvrData.ConfigV7, psana.Source(':Evr'))

#------------------------------
# get time from psana.EventId

import psana
ds  = psana.DataSource('/reg/g/psdm/detector/data_test/types/0014-MfxEndstation.0-Rayonix.0.xtc')
env = ds.env()

evt = next(ds.events())
list(evt.keys())
evid = evt.get(psana.EventId)
evid.time()

#------------------------------
#------------------------------

src=psana.Source(':Evr.')

for i, evt in enumerate(ds.events()):
        o = evt.get(psana.EvrData.DataV4, src)
        if   o is None : o = evt.get(psana.EvrData.DataV3, src)
        elif o is None : print('EvrData.DataV4,3 is not found in event %d' % i)
        lst_ts  = [(eco.timestampHigh(), eco.timestampLow()) for eco in o.fifoEvents()]
        print('Event %3d timestampHigh(), eco.timestampLow():' % i, lst_ts)
        if i>10 : break

#------------------------------
# get time from psana.Env
import psana
ds = psana.DataSource('/reg/g/psdm/detector/data_test/types/0007-NoDetector.0-Epix100a.0.xtc')
ds = psana.DataSource('/reg/d/psdm/cxi/cxif5315/xtc/e545-r0169-s00-c00.xtc')
ds = psana.DataSource('exp=cxif5315:run=169')
ds = psana.DataSource('exp=cxif5315:run=169:smd')
ds = psana.DataSource('exp=xpptut15:run=54:smd')
evid = ds.env().configStore().get(psana.EventId)
time = ds.env().configStore().get(psana.EventId).time()
rnum = ds.env().configStore().get(psana.EventId).run()

#------------------------------

