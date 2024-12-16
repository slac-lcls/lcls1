#ifndef PSEVT_EVENTOFFSET_H
#define PSEVT_EVENTOFFSET_H

//--------------------------------------------------------------------------
// File and Version Information:
// 	$Id$
//
// Description:
//	Class EventOffset.
//
//------------------------------------------------------------------------

//-----------------
// C/C++ Headers --
//-----------------
#include <iosfwd>
#include <vector>
#include <boost/shared_ptr.hpp>
#include <boost/utility.hpp>

//----------------------
// Base Class Headers --
//----------------------

//-------------------------------
// Collaborating Class Headers --
//-------------------------------

//------------------------------------
// Collaborating Class Declarations --
//------------------------------------

//		---------------------
// 		-- Class Interface --
//		---------------------

namespace PSEvt {

/**
 *  @ingroup PSEvt
 *
 *  @brief Class defining abstract interface for Event Offset objects.
 *
 *  Event Offset should include enough information to locate an event
 *  in the data file.  Currently we include event offsets and
 *  filenames in the Event Offset.
 *
 *  Implementation of this interface will probably be tied to a
 *  particular input data format so the interface will be implemented
 *  in the packages responsible for reading data (e.g. PSXtcInput).
 *
 *  This software was developed for the LCLS project.  If you use all or 
 *  part of it, please give an appropriate acknowledgment.
 *
 *  @version \$Id$
 *
 *  @author Elliott Slaughter
 */

class EventOffset : boost::noncopyable {
public:

  // Destructor
  virtual ~EventOffset () {}

  virtual std::vector<std::string> filenames() const = 0;
  virtual std::vector<int64_t> offsets() const = 0;
  virtual const boost::shared_ptr<std::string> lastBeginCalibCycleDgram() const = 0;

  /// Dump object in human-readable format
  virtual void print(std::ostream& os) const = 0;

protected:

  // Default constructor
  EventOffset () {}

private:

};

/// Standard stream insertion operator
std::ostream&
operator<<(std::ostream& os, const EventOffset& eid);

} // namespace PSEvt

#endif // PSEVT_EVENTOFFSET_H
