#!/usr/bin/env python
#------------------------------

from __future__ import print_function
import psana
import PSCalib.GlobalUtils as gu

def init_psana(tname) :
    """initialize psana
    """
    dsname, src = None, None
    
    if   tname == '1' :
        #dsname = '/reg/g/psdm/detector/data_test/types/0018-MfxEndstation.0-Epix100a.0.xtc' # 'exp=mfxm5116:run=20'
        dsname = 'exp=mfxm5116:run=20'
        src = 'MfxEndstation.0:Epix100a.0' # or 'VonHamos'

    elif tname == '2' :
        dsname = '/reg/g/psdm/detector/data_test/types/0019-XppGon.0-Epix100a.0.xtc' # 'exp=xppl1316:run=193'
        src = 'XppGon.0:Epix100a.0'

    elif tname == '3' :
        dsname = '/reg/g/psdm/detector/data_test/types/0007-NoDetector.0-Epix100a.0.xtc' # 'exp=xppi0614:run=74'
        src = 'NoDetector.0:Epix100a.0'
 
    elif tname == '4' :
        dsname = 'exp=xcs06016:run=52'
        src = 'XcsEndstation.0:Epix100a.1'
 
    elif tname == '5' :
        dsname = 'exp=xcs06016:run=52'
        src = 'XcsEndstation.0:Epix100a.2'
 
    elif tname == '6' :
        dsname = 'exp=xcs06016:run=52'
        src = 'XcsEndstation.0:Epix100a.3'
 
    elif tname == '7' :
        dsname = 'exp=xcs06016:run=52'
        src = 'XcsEndstation.0:Epix100a.4'
 
    elif tname == '8' :
        dsname = 'exp=xcs11116:run=2'
        src = 'XcsEndstation.0:Epix100a.4'
 
    return init_psana_for_dsname_src(dsname, src)


def init_psana_for_dsname_src(dsname='exp=xcs11116:run=2', source='XcsEndstation.0:Epix100a.4') :
    """initialize psana for dsname and (str) source
    """

    src = psana.Source(source)
    ds  = psana.DataSource(dsname)
    evt = next(ds.events())
    env = ds.env()

    print('calib_dir: %s' % gu.calib_dir(env))
    print('exp_name : %s' % gu.exp_name(env))
    print('alias_for_src_name : %s' % gu.alias_for_src_name(env))

    #print 'src_name_from_alias:\n'
    #gu.src_name_from_alias(env)

    #for i, evt in enumerate(ds.events()) :
    #    print 'event %d' % i
    #    o = evt.get(psana.CsPad.DataV2, src)
    #    if o is not None : 
    #        print o.data()
    #        break
    #runnum = evt.run()

    print(80*'_', '\nenv.configStore().keys():\n')
    for k in env.configStore().keys() : print(k)

    print(80*'_', '\nevt.keys():\n')
    for k in evt.keys() : print(k)

    print(80*'_')

    return ds, src, evt, env

#------------------------------

def get_epix_config_object(e, s) :
    """get epix config object
    """
    cs = e.configStore()
    o = cs.get(psana.Epix.Config100aV2, s)
    if o is not None : return o

    o = cs.get(psana.Epix.Config100aV1, s)
    if o is not None : return o

    return None

#------------------------------

def print_epix100_id(tname) :

    ds, src, evt, env = init_psana(tname)

    o = get_epix_config_object(env, src)
    
    if o is None :
        print('get_epix_config_object returns None')
        return

    print('version         :', o.version())   
    print('Version         :', o.Version)
    print('numberOfColumns :', o.numberOfColumns())
    print('numberOfRows    :', o.numberOfRows())
    print('TypeId          :', o.TypeId)
    print('carrierId0/1    :', o.carrierId0(), '/', o.carrierId1())
    print('digitalCardId0/1:', o.digitalCardId0(), '/', o.digitalCardId1())
    print('analogCardId0/1 :', o.analogCardId0(), '/', o.analogCardId1())

    print('exp=%s:run=%d %s' % (env.experiment(), evt.run(), gu.string_from_source(src)))
    print('epix100a-%010d-%010d-%010d-%010d-%010d-%010d-%010d' % (\
           o.version(),\
           o.carrierId0(), o.carrierId1(),\
           o.digitalCardId0(), o.digitalCardId1(),\
           o.analogCardId0(), o.analogCardId1()))

#------------------------------

def print_epix100_id_for_dsname_src(dsname='exp=xcs11116:run=2', source='XcsEndstation.0:Epix100a.4') :

    ds, src, evt, env = init_psana_for_dsname_src(dsname, source)

    o = get_epix_config_object(env, src)
    
    if o is None :
        print('get_epix_config_object returns None')
        return

    print('exp=%s:run=%d %s' % (env.experiment(), evt.run(), gu.string_from_source(src)))
    print('epix100a-%010d-%010d-%010d-%010d-%010d-%010d-%010d' % (\
           o.version(),\
           o.carrierId0(), o.carrierId1(),\
           o.digitalCardId0(), o.digitalCardId1(),\
           o.analogCardId0(), o.analogCardId1()))

#------------------------------

def usage() :
    #import os
    #proc_name = os.path.basename(sys.argv[0])
    proc_name = sys.argv[0]
    return 'python %s <dataset> <source>\n  example: python %s exp=xcs11116:run=2 XcsEndstation.0:Epix100a.4'%\
           (proc_name, proc_name)
#------------------------------

if __name__ == "__main__" :
    import sys

    tname = '1' if len(sys.argv) < 2 else sys.argv[1]
    if tname in ('1', '2', '3', '4', '5', '6', '7', '8') : 
         print_epix100_id(tname)
         print('Usage:\n%s'% usage())
    elif len(sys.argv)>2 : print_epix100_id_for_dsname_src(sys.argv[1], sys.argv[2])
    else : sys.exit ('Not recognized test name: "%s"' % tname)

    sys.exit ('End of %s' % sys.argv[0])

#------------------------------
