libnames := psalg
libsrcs_psalg := src/finite_impulse_response.cc
libsrcs_psalg += src/variance.cc
libsrcs_psalg += src/edge_finder.cc
libsrcs_psalg += src/moment.cc
libsrcs_psalg += src/extremes.cc
libsrcs_psalg += src/hit_finder.cc
libsrcs_psalg += src/parab_fit.cc
libsrcs_psalg += src/common_mode.cc
libsrcs_psalg += src/project.cc

libincs_psalg := boost/include