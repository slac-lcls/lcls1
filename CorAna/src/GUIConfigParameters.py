#--------------------------------------------------------------------------
# File and Version Information:
#  $Id$
#
# Description:
#  Module GUIConfigParameters...
#
#------------------------------------------------------------------------

"""GUI works with configuration parameters management"""
from __future__ import absolute_import

#------------------------------
#  Module's version from CVS --
#------------------------------
__version__ = "$Revision$"
# $Source$

#--------------------------------
#  Imports of standard modules --
#--------------------------------
import sys
import os

from PyQt5 import QtCore, QtGui, QtWidgets
#import time   # for sleep(sec)

#-----------------------------
# Imports for other modules --
#-----------------------------

from .ConfigParametersCorAna import confpars as cp
from CorAna.Logger                 import logger

#---------------------
#  Class definition --
#---------------------
class GUIConfigParameters ( QtWidgets.QWidget ) :
    """GUI works with configuration parameters management"""

    #----------------
    #  Constructor --
    #----------------
    def __init__ ( self, parent=None ) :
        """Constructor"""

        QtWidgets.QWidget.__init__(self, parent)

        #self.parent = cp.guimain

        self.setGeometry(370, 350, 530, 150)
        self.setWindowTitle('Configuration Parameters')
        self.setFrame()
        
        self.titFile     = QtWidgets.QLabel('File with configuration parameters:')
        self.titPars     = QtWidgets.QLabel('Operations on configuration parameters:')
        self.butBrowse   = QtWidgets.QPushButton("View")
        self.butRead     = QtWidgets.QPushButton("Read")
        self.butWrite    = QtWidgets.QPushButton("Save")
        self.butDefault  = QtWidgets.QPushButton("Reset default")
        self.butPrint    = QtWidgets.QPushButton("Print current")
        #self.butClose    = QtGui.QPushButton("Close")
        self.fnameEdit   = QtWidgets.QLineEdit( cp.fname_cp.value() )        

        grid = QtWidgets.QGridLayout()
        grid.addWidget(self.titFile,       0, 0, 1, 4)
        grid.addWidget(self.fnameEdit,     1, 0, 1, 4)
        grid.addWidget(self.butBrowse,     1, 4)
        grid.addWidget(self.titPars,       2, 0, 1, 4)
        grid.addWidget(self.butRead,       3, 0)
        grid.addWidget(self.butWrite,      3, 1)
        grid.addWidget(self.butDefault,    3, 2)
        grid.addWidget(self.butPrint,      3, 3)
        #grid.addWidget(self.butClose,      3, 4)
        self.setLayout(grid)

        self.fnameEdit.editingFinished .connect(self.onFileEdit)
        self.butRead.clicked.connect(self.onRead)
        self.butWrite.clicked.connect(self.onSave)
        self.butPrint.clicked.connect(self.onPrint)
        self.butDefault.clicked.connect(self.onDefault)
        self.butBrowse.clicked.connect(self.onBrowse)
        #self.connect(self.butClose,     QtCore.SIGNAL('clicked()'),          self.onClose        )

        self.showToolTips()
        self.setStyle()


    #-------------------
    #  Public methods --
    #-------------------

    def showToolTips(self):
        # Tips for buttons and fields:
        #self           .setToolTip('This GUI deals with the configuration parameters.')
        self.fnameEdit .setToolTip('Type the file path name here,\nor better use "View" button.')
        self.butBrowse .setToolTip('Select the file path name\nto read/write the configuration parameters.')
        self.butRead   .setToolTip('Read the configuration parameters from file.')
        self.butWrite  .setToolTip('Save (write) the configuration parameters in file.')
        self.butDefault.setToolTip('Reset the configuration parameters\nto their default values.')
        self.butPrint  .setToolTip('Print current values of the configuration parameters.')
        #self.butClose  .setToolTip('Close this window.')

    def setFrame(self):
        self.frame = QtWidgets.QFrame(self)
        self.frame.setFrameStyle( QtWidgets.QFrame.Box | QtWidgets.QFrame.Sunken ) #Box, Panel | Sunken, Raised 
        self.frame.setLineWidth(0)
        self.frame.setMidLineWidth(1)
        self.frame.setGeometry(self.rect())
        #self.frame.setVisible(False)

    def setStyle(self):

        self.setMinimumWidth(530)
        #width = 80
        #self.butBrowse .setFixedWidth(width)
        #self.edi_kin_win_size   .setAlignment(QtCore.Qt.AlignRight)

        self           .setStyleSheet(cp.styleBkgd)
        self.titFile   .setStyleSheet(cp.styleLabel)
        self.titPars   .setStyleSheet(cp.styleLabel)
        self.fnameEdit .setStyleSheet(cp.styleEdit) 

        self.butBrowse .setStyleSheet(cp.styleButton) 
        self.butRead   .setStyleSheet(cp.styleButton)
        self.butWrite  .setStyleSheet(cp.styleButton)
        self.butDefault.setStyleSheet(cp.styleButton)
        self.butPrint  .setStyleSheet(cp.styleButton)
        #self.butClose  .setStyleSheet(cp.styleButtonClose)

 
    def setParent(self,parent) :
        self.parent = parent

    def resizeEvent(self, e):
        #logger.debug('resizeEvent', __name__) 
        self.frame.setGeometry(self.rect())

    def moveEvent(self, e):
        #logger.debug('moveEvent', __name__) 
        #cp.posGUIMain = (self.pos().x(),self.pos().y())
        pass

    def closeEvent(self, event):
        logger.debug('closeEvent', __name__)
        #try    : del cp.guiconfigparameters 
        #except : pass

    def onClose(self):
        logger.debug('onClose', __name__)
        self.close()

    def onRead(self):
        logger.debug('onRead', __name__)
        cp.readParametersFromFile( self.getFileNameFromEditField() )
        self.fnameEdit.setText( cp.fname_cp.value() )
        #self.parent.fnameEdit.setText( cp.fname_cp.value() )
        #self.refreshGUIWhatToDisplay()

    def onWrite(self):
        fname = self.getFileNameFromEditField()
        logger.info('onWrite - save all configuration parameters in file: ' + fname, __name__)
        cp.saveParametersInFile( fname )

    def onSave(self):
        fname = cp.fname_cp.value()
        logger.info('onSave - save all configuration parameters in file: ' + fname, __name__)
        cp.saveParametersInFile( fname )

    def onDefault(self):
        logger.info('onDefault - Set default values of configuration parameters.', __name__)
        cp.setDefaultValues()
        self.fnameEdit.setText( cp.fname_cp.value() )
        #self.refreshGUIWhatToDisplay()

    def onPrint(self):
        logger.info('onPrint', __name__)
        cp.printParameters()

    def onBrowse(self):
        logger.debug('onBrowse', __name__)
        self.path = self.getFileNameFromEditField()
        self.dname,self.fname = os.path.split(self.path)
        logger.info('dname : %s' % (self.dname), __name__)
        logger.info('fname : %s' % (self.fname), __name__)
        self.path = str( QtWidgets.QFileDialog.getOpenFileName(self,'Open file',self.dname) )[0]
        self.dname,self.fname = os.path.split(self.path)

        if self.dname == '' or self.fname == '' :
            logger.info('Input directiry name or file name is empty... use default values', __name__)
        else :
            self.fnameEdit.setText(self.path)
            cp.fname_cp.setValue(self.path)

    def onFileEdit(self):
        logger.debug('onFileEdit', __name__)
        self.path = self.getFileNameFromEditField()
        cp.fname_cp.setValue(self.path)
        dname,fname = os.path.split(self.path)
        logger.info('Set dname : %s' % (dname), __name__)
        logger.info('Set fname : %s' % (fname), __name__)

    def getFileNameFromEditField(self):
        return str( self.fnameEdit.displayText() )

#-----------------------------

if __name__ == "__main__" :

    app = QtWidgets.QApplication(sys.argv)
    widget = GUIConfigParameters ()
    widget.show()
    app.exec_()

#-----------------------------
