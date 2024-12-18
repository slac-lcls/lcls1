# Needee by JuoyterLab
export JUPYTERLAB_WORKSPACES_DIR=${HOME}
export JUPYTERLAB_SETTINGS_DIR=${HOME}/.jupyter/lab/user-settings

# needed to avoid file locking crash in mpi splitscan tests
export HDF5_USE_FILE_LOCKING=FALSE
export SIT_ARCH=x86_64-rhel7-gcc48-opt

if [ -d "/sdf/group/lcls/" ]
then
    # s3df
    export SIT_ROOT=/sdf/group/lcls/ds/ana
    export SIT_PSDM_DATA=/sdf/data/lcls/ds
    export CONDA_ENVS_DIRS=/sdf/group/lcls/ds/ana/sw/conda1/inst/envs
    eval "$(/sdf/group/lcls/ds/ana/sw/conda1-v4/inst/bin/conda shell.bash hook)"
else
    # psana
    export SIT_ROOT=/cds/group/psdm
    export SIT_PSDM_DATA=/cds/data/psdm
    export CONDA_ENVS_DIRS=/sdf/group/lcls/ds/ana/sw/conda1/inst/envs
    eval "$(/cds/sw/ds/ana/conda1-v4/inst/bin/conda shell.bash hook)"
fi

# needed for SRCF
export OPENBLAS_NUM_THREADS=1

conda activate ana_20241215

RELDIR="$( cd "$( dirname $(readlink -f "${BASH_SOURCE[0]:-${(%):-%x}}") )" && pwd )"
export SIT_DATA=$RELDIR/install/data:$SIT_ROOT/data/
export PATH=$RELDIR/install/bin:${PATH}
pyver=$(python -c "import sys; print(str(sys.version_info.major)+'.'+str(sys.version_info.minor))")
export PYTHONPATH=$RELDIR/install/lib/python$pyver/site-packages
export TESTRELDIR=$RELDIR/install
