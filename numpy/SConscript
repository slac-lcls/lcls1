#--------------------------------------------------------------------------
# File and Version Information:
#  $Id$
#
# Description:
#  SConscript file for package numpy
#------------------------------------------------------------------------

# Do not delete following line, it must be present in 
# SConscript file for any SIT project
Import('*')

import os
from SConsTools.CondaMeta import CondaMeta
from SConsTools.standardExternalPackage import standardExternalPackage

pkg = 'numpy'

numpyConda = CondaMeta(pkg)
PREFIX = numpyConda.prefix()
INCDIR = os.path.join(numpyConda.python_site_packages(), pkg, 'core', 'include', pkg)

standardExternalPackage(pkg, **locals())
