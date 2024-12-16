#ifndef XTCINPUT_DGRAMREADER_H
#define XTCINPUT_DGRAMREADER_H

//--------------------------------------------------------------------------
// File and Version Information:
// 	$Id$
//
// Description:
//	Class DgramReader.
//
//------------------------------------------------------------------------

//-----------------
// C/C++ Headers --
//-----------------
#include <string>
#include <vector>
#include "boost/shared_ptr.hpp"
#include "boost/make_shared.hpp"

//----------------------
// Base Class Headers --
//----------------------

//-------------------------------
// Collaborating Class Headers --
//-------------------------------
#include "XtcInput/MergeMode.h"
#include "XtcInput/XtcFilesPosition.h"
#include "XtcInput/RunFileIterI.h"
#include "XtcInput/LiveAvail.h"

//------------------------------------
// Collaborating Class Declarations --
//------------------------------------

//		---------------------
// 		-- Class Interface --
//		---------------------

namespace XtcInput {

class DgramQueue ;

/// @addtogroup XtcInput

/**
 *  @ingroup XtcInput
 *
 *  @brief Thread which reads datagrams from the list of XTC files
 *
 *  This software was developed for the LUSI project.  If you use all or
 *  part of it, please give an appropriate acknowledgment.
 *
 *  @version $Id$
 *
 *  @author Andrei Salnikov
 */

class DgramReader {
public:

  typedef std::vector<std::string> FileList ;

  // full constructor with parameters for handling control streams and optionally
  // specifies file offsets before the second event (event after configure).
  template <typename Iter>
    DgramReader(Iter begin, Iter end, DgramQueue& queue,
                boost::shared_ptr<XtcInput::LiveAvail> &liveAvail,
                MergeMode mode, const std::string& liveWSConn,
                unsigned liveTimeout, unsigned runLiveTimeout, double l1OffsetSec,
                int firstControlStream, unsigned maxStreamClockDiffSec,
                boost::shared_ptr<XtcFilesPosition> thirdEvent =
                                boost::shared_ptr<XtcFilesPosition>())
    : m_files(begin, end)
    , m_queue( queue )
    , m_mode( mode )
    , m_liveWSConn(liveWSConn)
    , m_liveTimeout(liveTimeout)
    , m_runLiveTimeout(runLiveTimeout)
    , m_l1OffsetSec(l1OffsetSec)
    , m_firstControlStream(firstControlStream)
    , m_maxStreamClockDiffSec(maxStreamClockDiffSec)
    , m_thirdEvent(thirdEvent)
    , m_liveAvail(liveAvail)
  {}

  // constructor with default parameters for parameters for handling control streams
  template <typename Iter>
  DgramReader(Iter begin, Iter end, DgramQueue& queue, MergeMode mode,
              const std::string& liveWSConn, unsigned liveTimeout,
              unsigned runLiveTimeout, double l1OffsetSec=0)
    : m_files(begin, end)
    , m_queue( queue )
    , m_mode( mode )
    , m_liveWSConn(m_liveWSConn)
    , m_liveTimeout(liveTimeout)
    , m_runLiveTimeout(runLiveTimeout)
    , m_l1OffsetSec(l1OffsetSec)
    , m_firstControlStream(80)
    , m_maxStreamClockDiffSec(85)
  {}

  // Destructor
  ~DgramReader () ;

  // this is the "run" method used by the Boost.thread
  void operator() () ;

protected:

private:

  void moveDgramsThroughQueue(boost::shared_ptr<RunFileIterI> runFileIter, bool liveMode);

  // Data members
  FileList m_files ;
  DgramQueue& m_queue ;
  size_t m_maxDgSize ;
  MergeMode m_mode ;
  std::string m_liveWSConn;
  unsigned m_liveTimeout;
  unsigned m_runLiveTimeout;
  double m_l1OffsetSec ;
  int m_firstControlStream;
  unsigned m_maxStreamClockDiffSec;
  boost::shared_ptr<XtcFilesPosition> m_thirdEvent;
  boost::shared_ptr<XtcInput::LiveAvail> &m_liveAvail;
};

} // namespace XtcInput

#endif // XTCINPUT_DGRAMREADER_H
