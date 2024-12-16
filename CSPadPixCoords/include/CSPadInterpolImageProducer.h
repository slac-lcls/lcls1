#ifndef CSPADPIXCOORDS_CSPADINTERPOLIMAGEPRODUCER_H
#define CSPADPIXCOORDS_CSPADINTERPOLIMAGEPRODUCER_H

//--------------------------------------------------------------------------
// File and Version Information:
// 	$Id$
//
// Description:
//	Class CSPadInterpolImageProducer.
//
//------------------------------------------------------------------------

//-----------------
// C/C++ Headers --
//-----------------
#include <ostream>

//----------------------
// Base Class Headers --
//----------------------
#include "psana/Module.h"

//-------------------------------
// Collaborating Class Headers --
//-------------------------------
#include "PSCalib/CSPadCalibPars.h"

#include "CSPadPixCoords/QuadParameters.h"
#include "CSPadPixCoords/PixCoords2x1.h"
#include "CSPadPixCoords/PixCoordsQuad.h"
#include "CSPadPixCoords/PixCoordsCSPad.h"

//------------------------------------
// Collaborating Class Declarations --
//------------------------------------

#include "PSEvt/Source.h"


//		---------------------
// 		-- Class Interface --
//		---------------------

namespace CSPadPixCoords {

/// @addtogroup CSPadPixCoords

/**
 *  @ingroup CSPadPixCoords
 *
 *  @brief CSPadInterpolImageProducer produces the CSPad image for each event and add it to the event in psana framework.
 *
 *  CSPadInterpolImageProducer works in psana framework. It does a few operation as follows:
 *  1) get the pixel coordinates from PixCoords2x1, PixCoordsQuad, and PixCoordsCSPad classes,
 *  2) get data from the event,
 *  3) produce the Image2D object with CSPad image for each event,
 *  4) add the Image2D object in the event for further modules.
 *
 *  Time consumed to fill the CSPad image array (currently [1750][1750]) 
 *  is measured to be about 40 msec/event on psana0105. 
 *
 *  This class should not be used directly in the code of users modules. 
 *  Instead, it should be added as a module in the psana.cfg file with appropriate parameters.
 *  Then, the produced Image2D object can be extracted from event and used in other modules.
 *
 *  This software was developed for the LCLS project.  If you use all or 
 *  part of it, please give an appropriate acknowledgment.
 *
 *  @see PixCoords2x1, PixCoordsQuad, PixCoordsCSPad, CSPadImageGetTest
 *
 *  @version \$Id$
 *
 *  @author Mikhail S. Dubrovin
 */

/**
  * Array address descriptor for CSPad pixel
  */

struct ArrAddr {
    int quad;
    int sect;
    int row;
    int col;
};

std::ostream& operator<< (std::ostream& s, const ArrAddr& a) ;
bool areEqual( const ArrAddr& a1, const ArrAddr& a2 ) ;

class CSPadInterpolImageProducer : public Module {
public:

  enum { NQuadsMax    = Psana::CsPad::MaxQuadsPerSensor  };  // 4
  enum { N2x1         = Psana::CsPad::SectorsPerQuad     };  // 8
  enum { NCols2x1     = Psana::CsPad::ColumnsPerASIC     };  // 185
  enum { NRows2x1     = Psana::CsPad::MaxRowsPerASIC * 2 };  // 388
  enum { SizeOf2x1Arr = NRows2x1 * NCols2x1              };  // 185*388;

  // Default constructor
  CSPadInterpolImageProducer (const std::string& name) ;

  // Destructor
  virtual ~CSPadInterpolImageProducer () ;

  /// Method which is called once at the beginning of the job
  virtual void beginJob(Event& evt, Env& env);
  
  /// Method which is called at the beginning of the run
  virtual void beginRun(Event& evt, Env& env);
  
  /// Method which is called at the beginning of the calibration cycle
  virtual void beginCalibCycle(Event& evt, Env& env);
  
  /// Method which is called with event data, this is the only required 
  /// method, all other methods are optional
  virtual void event(Event& evt, Env& env);
  
  /// Method which is called at the end of the calibration cycle
  virtual void endCalibCycle(Event& evt, Env& env);

  /// Method which is called at the end of the run
  virtual void endRun(Event& evt, Env& env);

  /// Method which is called once at the end of the job
  virtual void endJob(Event& evt, Env& env);

protected:

  void init_address_table_1();
  void fill_address_table_1();
  void init_address_and_weights_of_4_neighbors();
  void fill_address_and_weights_of_4_neighbors();
  void get_address_of_4_neighbors(unsigned ix, unsigned iy);
  void get_weight_of_4_neighbors(unsigned ix, unsigned iy);

  void getConfigPars(Env& env);
  void cspad_image_init();
  void cspad_image_save_in_file(const std::string &filename = "cspad_image.txt");
  void cspad_image_add_in_event(Event& evt);
  //void cspad_image_interpolated_fill (int16_t* data[], QuadParameters* quadpars[], bool quadIsAvailable[]);
  void cspad_image_interpolated_fill (ndarray<const int16_t, 3> data[], QuadParameters* quadpars[], bool quadIsAvailable[]);

private:

  // Data members, this is for example purposes only

  std::string m_calibDir;       // i.e. ./calib
  std::string m_typeGroupName;  // i.e. CsPad::CalibV1
  std::string m_source;         // i.e. CxiDs1.0:Cspad.0
   
  Source      m_src;            // Data source set from config file
  Pds::Src    m_actualSrc;
  std::string m_inkey;          // i.e. "" or "calibrated"
  std::string m_imgkey;         // i.e. "CSPad:Image"
  unsigned    m_maxEvents;
  bool        m_filter;
  bool        m_tiltIsApplied;
  unsigned    m_print_bits;
  long        m_count;

  uint32_t m_roiMask        [4];
  uint32_t m_numAsicsStored [4];

  CSPadPixCoords::PixCoords2x1::COORDINATE XCOOR;
  CSPadPixCoords::PixCoords2x1::COORDINATE YCOOR;
  CSPadPixCoords::PixCoords2x1::COORDINATE ZCOOR;

  PSCalib::CSPadCalibPars        *m_cspad_calibpar;
  CSPadPixCoords::PixCoords2x1   *m_pix_coords_2x1;
  CSPadPixCoords::PixCoordsQuad  *m_pix_coords_quad;
  CSPadPixCoords::PixCoordsCSPad *m_pix_coords_cspad;

  uint32_t  m_cspad_ind;
  double   *m_coor_x_pix;
  double   *m_coor_y_pix;
  uint32_t *m_coor_x_int;
  uint32_t *m_coor_y_int;

  enum{ NX_QUAD=850, 
        NY_QUAD=850 };

  enum{ NX_CSPAD=1750, 
        NY_CSPAD=1750 };
  double m_arr_cspad_image [NX_CSPAD][NY_CSPAD];

  ArrAddr m_addr_empty;
  ArrAddr m_address_table_1[NX_CSPAD][NY_CSPAD];
  ArrAddr m_address        [NX_CSPAD][NY_CSPAD][4];
  double  m_weight         [NX_CSPAD][NY_CSPAD][4];

};

} // namespace CSPadPixCoords

#endif // CSPADPIXCOORDS_CSPADINTERPOLIMAGEPRODUCER_H
