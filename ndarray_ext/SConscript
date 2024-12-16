#-----------------------------------------
# Description:
#  SConscript file for package ndarray_ext
#-----------------------------------------

# Do not delete following line, it must be present in
# SConscript file for any SIT project
Import('*')

from SConsTools.standardCondaPackage import standardCondaPackage
from SConsTools.standardExternalPackage import standardExternalPackage
from SConsTools.scons_functions import info

ndarrayNodeList=Glob('#/ndarray')
if len(Glob('#/ndarray'))==1:
    node = ndarrayNodeList[0]
    info("Detected locally checked out ndarray package. "
         "Will not link ndarray from conda environment, using local")
    standardExternalPackage('ndarray', PREFIX=node.abspath,
                            LOCAL=True, INCDIR='include')
else:
    standardCondaPackage('ndarray-psana', INCDIR='include/ndarray', LINKLIBS=None)
    #standardCondaPackage('ndarray', INCDIR='include/ndarray', LINKLIBS=None)

