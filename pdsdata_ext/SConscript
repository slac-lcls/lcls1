#------------------------------------------------------------------------
# File and Version Information:
#  $Id$
#
# Description:
#  SConscript file for package pdsdata
#------------------------------------------------------------------------

# Do not delete following line, it must be present in 
# SConscript file for any SIT project
Import('*')
from os.path import join as pjoin
from SConsTools.buildExternalPackage import buildExternalPackage
from SConsTools.buildExternalPackage import prefixForBuildExternal
from SConsTools.standardExternalPackage import standardExternalPackage

#
# For the standard external packages which contain includes, libraries, 
# and applications it is usually sufficient to call standardExternalPackage()
# giving few keyword arguments. Here is a complete list of arguments:
#
#    PREFIX   - top directory of the external package
#    INCDIR   - include directory, absolute or relative to PREFIX
#    INCLUDES - include files to copy (space-separated list of patterns)
#    PYDIR    - Python src directory, absolute or relative to PREFIX
#    LINKPY   - Python files to link (patterns), or all files if not present
#    PYDIRSEP - if present and evaluates to True installs python code to a 
#               separate directory arch/$SIT_ARCH/python/<package>
#    LIBDIR   - libraries directory, absolute or relative to PREFIX
#    COPYLIBS - library names to copy
#    LINKLIBS - library names to link, or all libs if LINKLIBS and COPYLIBS are empty
#    BINDIR   - binaries directory, absolute or relative to PREFIX
#    LINKBINS - binary names to link, or all binaries if not present
#    PKGLIBS  - names of libraries that have to be linked for this package
#    DEPS     - names of other packages that we depend upon
#    PKGINFO  - package information, such as RPM package name


# here is an example setting up a fictional package

assert env.get('CONDA',False), "not conda build"

pkg = "pdsdata"
PREFIX = prefixForBuildExternal(pkg)

# HACK: shouldl have proper dependencies setup within SCons, then we could get
# ndarray and boost from geninc. For now, we are assuming ndarray is checked out in the
# proper place, and that boost is in the conda environent. Note - put ndarray first in the
# make line, if an old version of ndarray is the conda env, problems.
ndarrinc = pjoin(env['CONDA_ENV_PATH'], 'include')
boostinc = pjoin(env['CONDA_ENV_PATH'], 'include')
buildcmds = [ 
    "make -C %s CFLAGS='-I%s -I%s' x86_64-linux-opt" % (pkg, ndarrinc, boostinc),
    "make -C %s INSTALLDIR=%s install" % (pkg, PREFIX),
]

buildExternalPackage(pkg=pkg,
                     buildcmds=buildcmds,
                     PREFIX=PREFIX,
                     ONE_TARGET='lib/libpsddl_pdsdata.so',
                     startdir='parent')

# pdsdata package will link all the stuff, but only includes one
# library into the build
BINDIR = 'bin'
LIBDIR = 'lib'
INCDIR = 'pdsdata'
PKGLIBS = 'xtcdata'
standardExternalPackage('pdsdata', **locals())

del LIBDIR
del INCDIR
del BINDIR

# map package names to libraries
packages = {
    'app'           : 'appdata',
    'compress'      : 'compressdata',
    'index'         : 'indexdata',
    'psddl'         : 'psddl_pdsdata',
}

for pkg, lib in packages.items():
    PKGLIBS = lib
    PKGINFO = None
    DEPS = 'pdsdata'
    standardExternalPackage('pdsdata_'+pkg, **locals())
