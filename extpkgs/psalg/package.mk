# Package level makefile
# ----------------------
#Makefile:;

# Symbols
# -------
SHELL := /bin/bash
RM    := rm -f
MV    := mv -f
empty :=
space := $(empty) $(empty)

quiet := @

RELEASE_DIR := $(PWD)
build_dir := ${RELEASE_DIR}/build/psalg

# Defines which directories are being created by this makefile
incdir  := $(INSTALLDIR)/psalg
libdir  := $(build_dir)/lib
objdir  := $(build_dir)/obj

prod_dirs := $(strip $(INSTALLDIR)/lib $(incdir))

LIBEXTNS := so
DEFINES  := -fPIC -D_REENTRANT -D__pentium__ -Wall
CC  := gcc
CXX := g++
LD  := g++
LX  := g++

ifneq ($(findstring i386-linux,$(tgt_arch)),)
CXXFLAGS   := -m32
CPPFLAGS   := $(CFLAGS) -m32
USRLIBDIR  := /usr/lib
endif

ifneq ($(findstring x86_64,$(tgt_arch)),)
CPPFLAGS   := $(CFLAGS)
USRLIBDIR  := /usr/lib64
endif

ifneq ($(findstring -dbg,$(tgt_arch)),)
CPPFLAGS   += -g
endif

ifneq ($(findstring -opt,$(tgt_arch)),)
CPPFLAGS   += -O4
endif

override CPPFLAGS += -I$(RELEASE_DIR)

# Procedures
# ----------

# Define some procedures and create (different!) rules for libraries
# and targets. Note that 'eval' needs gmake >= 3.80.
incfiles  := $(wildcard *.h *.hh *.hpp)
libraries :=
targets   :=
objects   := 
getobjects = $(strip \
	$(patsubst %.cc,$(1)/%.o,$(filter %.cc,$(2))) \
	$(patsubst %.cpp,$(1)/%.o,$(filter %.cpp,$(2))) \
	$(patsubst %.c,$(1)/%.o, $(filter %.c,$(2))) \
	$(patsubst %.s,$(1)/%.o, $(filter %.s,$(2))))

define library_template
  library_$(1) := $$(libdir)/lib$(1).$(LIBEXTNS)
  libobjs_$(1) := $$(call getobjects,$$(objdir),$$(libsrcs_$(1)))
  libraries    += $$(library_$(1))
  objects      += $$(libobjs_$(1))
ifeq ($$(LIBEXTNS),so)
ifneq ($$(ifversn_$(1)),)
  ifversnflags_$(1) := -Wl,--version-script=$$(ifversn_$(1))
endif
endif
$$(library_$(1)): $$(libobjs_$(1))
endef

$(foreach lib,$(libnames),$(eval $(call library_template,$(lib))))

temp_dirs := $(strip $(sort $(foreach o,$(objects),$(dir $(o))))) $(libdir)

# Rules
# -----
rules := all dir obj lib bin clean cleanall userall userclean install print

.PHONY: $(rules) $(libnames) $(tgtnames)

.SUFFIXES:  # Kills all implicit rules

all: $(temp_dirs) lib

obj: $(objects);

lib: $(libraries);

install: $(prod_dirs)
	cp ${incfiles} $(incdir)
	cp -rf ${libdir} $(INSTALLDIR)/.

print:
	@echo	"libdir    = $(libdir)"
	@echo	"objdir    = $(objdir)"
	@echo	"prod_dirs = $(prod_dirs)"
	@echo	"temp_dirs = $(temp_dirs)"
	@echo	"libraries = $(libraries)"
	@echo	"objects   = $(objects)"
	@echo	"CXXFLAGS  = $(CXXFLAGS)"
	@echo	"CPPFLAGS  = $(CPPFLAGS)"

clean: userclean
	$(quiet)$(RM) $(objects) $(libraries)

cleanall: clean userclean


# Directory structure
$(prod_dirs) $(temp_dirs):
	mkdir -p $@


# Libraries
$(libdir)/lib%.$(LIBEXTNS):
	@echo "[LD] Build library $*"
	$(quiet)$(LD) $(CXXFLAGS) -shared $(ifversnflags_$*) $(linkflags_$*) $^ -o $@


# Objects for C++ assembly files
$(objdir)/%.o: %.cc
	@echo "[CX] Compiling $<"
	$(quiet)$(CXX) $(CPPFLAGS) $(DEFINES) $(CXXFLAGS) -c $< -o $@

$(objdir)/%.o: %.cpp
	@echo "[CX] Compiling $<"
	$(quiet)$(CXX) $(CPPFLAGS) $(DEFINES) $(CXXFLAGS) -c $< -o $@
