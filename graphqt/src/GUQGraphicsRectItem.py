#!@PYTHON@
"""
Class :py:class:`GUQGraphicsRectItem` is derived from QGraphicsRectItem to intercept events
===========================================================================================

Created on June 12, 2016 by Mikhail Dubrovin
"""
from __future__ import print_function
#import os
#import math
from PyQt5 import QtCore, QtGui, QtWidgets
from PyQt5.QtWidgets import QGraphicsRectItem
from PyQt5.QtCore import Qt
#from PyQt4.QtCore import Qt, QPointF

#from pyapps.graphqt.AxisLabeling import best_label_locs

#-----------------------------

class GUQGraphicsRectItem(QGraphicsRectItem) :    
    #                  QRectF, QGraphicsItem, QGraphicsScene
    event_on_rect = QtCore.pyqtSignal('QString')

    def __init__(self, rect, parent=None, scene=None) :
        QGraphicsRectItem.__init__(self, rect, parent)
        if scene is not None: scene.addItem(self)

        self.setAcceptHoverEvents(True)
        self.setAcceptTouchEvents(True)
        #self.setAcceptedMouseButtons(Qt.LeftButton)
        self.setCursorHover()
        self.setCursorGrab()


    def setCursorHover(self, cursor=Qt.CrossCursor) :
        #QGraphicsRectItem.setCursor(self, cursor)
        self.hover_cursor = cursor


    def setCursorGrab(self, cursor=Qt.SizeAllCursor) : # Qt.ClosedHandCursor) :
        self.grub_cursor = cursor


    def hoverEnterEvent(self, e) :
        #print 'hoverEnterEvent'
        QGraphicsRectItem.hoverEnterEvent(self, e)
        QtWidgets.QApplication.setOverrideCursor(QtGui.QCursor(self.hover_cursor))


    def hoverLeaveEvent(self, e) :
        #print 'hoverLeaveEvent'
        QGraphicsRectItem.hoverLeaveEvent(self, e)
        #QtGui.QApplication.setOverrideCursor(QtGui.QCursor(self.hover_cursor))
        QtWidgets.QApplication.restoreOverrideCursor()
        

    def hoverMoveEvent(self, e) :
        #print 'hoverMoveEvent'
        QGraphicsRectItem.hoverMoveEvent(self, e)


    def mouseMoveEvent(self, e) :
        print('GUQGraphicsRectItem: mouseMoveEvent')
        QGraphicsRectItem.mouseMoveEvent(self, e)


    def mousePressEvent(self, e) :
        #print 'mousePressEvent, at point: ', e.pos() #e.globalX(), e.globalY() 
        QGraphicsRectItem.mousePressEvent(self, e)
        QtWidgets.QApplication.setOverrideCursor(QtGui.QCursor(self.grub_cursor))


    def mouseReleaseEvent(self, e) :
        """ !!! This method does not receive control because module is distracted before...
        """
        #print 'mouseReleaseEvent'
        QGraphicsRectItem.mouseReleaseEvent(self, e)
        #QtGui.QApplication.setOverrideCursor(QtGui.QCursor(self.hover_cursor))
        QtWidgets.QApplication.restoreOverrideCursor()


#    def mouseDoubleClickEvent(self, e) :
#        QGraphicsRectItem.hoverLeaveEvent(self, e)
#        print 'mouseDoubleClickEvent, at point: ', e.pos() #e.globalX(), e.globalY() 


#    def wheelEvent(self, e) :
#        QGraphicsRectItem.wheelEvent(self, e)
#        #print 'wheelEvent, at point: ', e.pos() #e.globalX(), e.globalY() 


    def emit_signal(self, msg='click') :
        self.event_on_rect.emit(msg)
        #print msg

#-----------------------------
