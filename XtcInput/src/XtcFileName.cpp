//--------------------------------------------------------------------------
// File and Version Information:
// 	$Id$
//
// Description:
//	Class XtcFileName...
//
// Author List:
//      Andrei Salnikov
//
//------------------------------------------------------------------------

//-----------------------
// This Class's Header --
//-----------------------
#include "XtcInput/XtcFileName.h"

//-----------------
// C/C++ Headers --
//-----------------
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include "boost/algorithm/string/predicate.hpp"
#include <stdexcept>

//-------------------------------
// Collaborating Class Headers --
//-------------------------------
#include "MsgLogger/MsgLogger.h"

//-----------------------------------------------------------------------
// Local Macros, Typedefs, Structures, Unions and Forward Declarations --
//-----------------------------------------------------------------------

namespace {

  const char sep = '-' ;

  const char *logger = "XtcInput.XtcFileName";

  const std::string smallDataFromFirstDot = ".smd.xtc";

  // convert string to integer
  unsigned _cvt ( const char* ptr, bool& stat )
  {
    char *eptr = 0 ;
    int val = strtol ( ptr, &eptr, 10 ) ;
    stat = ( *eptr == 0 ) and val >= 0 ;
    return unsigned(val) ;
  }

  void splitOnFirstDot(const std::string &path, std::string &beforeDot, std::string &dotAndAfter) {
    static const std::string dot(".");
    size_t dotPos = path.find(dot);
    if (dotPos == std::string::npos) {
      beforeDot = std::string(path);
      dotAndAfter = std::string();
    } else {
      beforeDot = std::string(path.substr(0,dotPos));
      dotAndAfter = std::string(path.substr(dotPos));
    }
  }


}

//		----------------------------------------
// 		-- Public Function Member Definitions --
//		----------------------------------------

namespace XtcInput {

XtcFileName::XtcFileName()
  : m_path()
  , m_expName()
  , m_run(0)
  , m_stream(0)
  , m_chunk(0)
{
}

XtcFileName::XtcFileName ( const std::string& path )
  : m_path(path)
  , m_expName()
  , m_run(0)
  , m_stream(0)
  , m_chunk(0)
  , m_small(false)
{

  std::string name = basename() ;

  // file name expected to be eNNN_rNNN_sNNN_chNNN.xtc or
  // file name expected to be eNNN_rNNN_sNNN_chNNN.smd.xtc or
  // file name expected to be eNNN_rNNN_sNNN_chNNN.xtc.inprogress or
  // file name expected to be eNNN_rNNN_sNNN_chNNN.smd.xtc.inprogress

  std::string beforeFirstDot, firstDotAndAfter;
  splitOnFirstDot(name, beforeFirstDot, firstDotAndAfter);
  m_small = boost::algorithm::starts_with(firstDotAndAfter, smallDataFromFirstDot);

  // remove all extensions, from leftmost dot on
  name = beforeFirstDot;

  // find underscore before chunk part
  size_t n = name.rfind(sep) ;
  if ( n == std::string::npos || (name.size()-n) < 3 || name[n+1] != 'c' ) return ;
  bool stat ;
  unsigned chunk = _cvt ( name.c_str()+n+2, stat ) ;
  if ( not stat ) return ;

  // remove chunk part
  name.erase(n) ;

  // find underscore before stream part
  n = name.rfind(sep) ;
  if ( n == std::string::npos || (name.size()-n) < 3 || name[n+1] != 's' )  return ;
  unsigned stream = _cvt ( name.c_str()+n+2, stat ) ;
  if ( not stat ) return ;

  // remove stream part
  name.erase(n) ;

  // find underscore before run part
  n = name.rfind(sep) ;
  if ( n == std::string::npos || (name.size()-n) < 3 || name[n+1] != 'r' ) return ;
  unsigned run = _cvt ( name.c_str()+n+2, stat ) ;
  if ( not stat ) return ;

  // remove run part
  name.erase(n) ;

  // remaining must be experiment part
  // In the LCLS2 transition, we made a transition from experiment id to experiment name.
  // Also, we dropped the e from the file name.
  // We stick whatever's there as the experiment name; this is used in a couple of places so hopefully not too impactful.
  // So we could have e665-r0511-s01-c00.smd.xtc or xcsc00118-r0006-s01-c00.xtc
  // This should take care of both the LCLS1 and LCLS2 cases..
  if ( name.size() < 2) return ;
  std::string expName(name.c_str()) ;

  MsgLog(logger, trace, "Experiment prefix from path: " << expName);

  m_expName = expName ;
  m_run = run ;
  m_stream = stream ;
  m_chunk = chunk ;
}

// Construct from dir name, experiment prefix, run number, stream and chunk
  XtcFileName::XtcFileName(const std::string& dir, const std::string& expName, unsigned run, unsigned stream, unsigned chunk, bool small)
  : m_path()
  , m_expName(expName)
  , m_run(run)
  , m_stream(stream)
  , m_chunk(chunk)
  , m_small(small)
{
  m_path = dir;
  if (not m_path.empty() and m_path[m_path.size()-1] != '/') m_path += "/";
  char buf[64];
  if (small) {
    snprintf(buf, sizeof buf, "%s-r%04u-s%02u-c%02u.smd.xtc", expName.c_str(), run, stream, chunk);
  } else {
    snprintf(buf, sizeof buf, "%s-r%04u-s%02u-c%02u.xtc", expName.c_str(), run, stream, chunk);
  }
  m_path += buf;
  MsgLog(logger, trace, "Computed XTC file name path: " << m_path);
}

// get corresponding large file for a small file
XtcFileName
XtcFileName::largeFile() const
{
  // FIXME: What about ???.smd.xtc.inprogress
  if (!small()) return *this;

  std::string name = m_path;

  std::string::size_type n1 = name.rfind('/');
  if (n1 == std::string::npos) return *this; // invalid string, just return

  std::string::size_type n2 = name.rfind('/', n1-1);
  if (n2 != std::string::npos) {
    name.erase(n2+1);
  } else {
    return *this; // invalid string, just return
  }

  name.append(largeBasename());
  return XtcFileName(name);
}

// get base name
std::string
XtcFileName::basename() const
{
  std::string name = m_path ;

  // remove dirname
  std::string::size_type n = name.rfind('/') ;
  if ( n != std::string::npos ) name.erase ( 0, n+1 ) ;

  return name ;
}

// get base name for smalldata version of the xtc file (will be the same if small)
std::string XtcFileName::smallBasename() const
{
  std::string name = basename();

  if (this->small()) return name;

  if (this->extension() != ".xtc") {
    MsgLog(logger, error, "smallBasename - extension is not .xtc. How to Transform? File is: " << m_path);
    throw std::runtime_error("XtcFileName::smallBasename");
  }
  size_t n = name.length();
  n -= 4;
  return name.substr(0,n) + ".smd.xtc";
}

// get large base name
std::string
XtcFileName::largeBasename() const
{
  std::string name = basename();

  if (not this->small()) return name;


  // remove .smd from first .smd.xtc
  std::string::size_type n = name.find(smallDataFromFirstDot);
  if ( n == std::string::npos ) {
    MsgLog(logger, error, "largeBasename can't find " << smallDataFromFirstDot << " in small file");
    return name;
  }
  return name.substr(0,n) + name.substr(n+4);
}

// get file extension, anything that appears after last '.' in file name
std::string
XtcFileName::extension() const
{
  std::string ext = m_path;

  // skip directory first
  std::string::size_type n = ext.rfind('/') ;
  if ( n == std::string::npos ) {
    n = 0;
  } else {
    ++ n;
  }
  std::string::size_type n1 = ext.rfind('.') ;
  if ( n1 == std::string::npos or n1 < n ) {
    ext.clear();
  } else {
    ext.erase ( 0, n1 ) ;
  }

  return ext;
}

// compare two names
bool
XtcFileName::operator<( const XtcFileName& other ) const
{
  if (m_small and (not other.m_small)) return true ;
  if (other.m_small and (not m_small)) return false ;

  if ( m_expName < other.m_expName) return true ;
  if ( other.m_expName < m_expName ) return false ;

  if ( m_run < other.m_run ) return true ;
  if ( other.m_run < m_run ) return false ;

  if ( m_stream < other.m_stream ) return true ;
  if ( other.m_stream < m_stream ) return false ;

  if ( m_chunk < other.m_chunk ) return true ;
  return false;
}

std::ostream&
operator<<(std::ostream& out, const XtcFileName& fn)
{
  return out << fn.path() ;
}

} // namespace XtcInput
