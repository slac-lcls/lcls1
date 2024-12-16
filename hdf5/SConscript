#--------------------------------------------------------------------------
# File and Version Information:
#  $Id$
#
# Description:
#  SConscript file for package hdf5
#------------------------------------------------------------------------

# Do not delete following line, it must be present in 
# SConscript file for any SIT project
Import('*')

from SConsTools.CondaMeta import condaPackageExists
from SConsTools.standardCondaPackage import standardCondaPackage

hdf5_required_pkglibs = 'hdf5'
hdf5_expected_pkglibs = "hdf5_cpp hdf5_hl hdf5_hl_cpp"

standardCondaPackage('hdf5', 
                     REQUIRED_PKGLIBS=hdf5_required_pkglibs,
                     EXPECTED_PKGLIBS=hdf5_expected_pkglibs)
