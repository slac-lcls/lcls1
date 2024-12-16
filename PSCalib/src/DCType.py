#!/usr/bin/env python

"""
Class :py:class:`DCType` for the Detector Calibration (DC) project
==================================================================

Usage::

    # Import
    from PSCalib.DCType import DCType

    # Initialization
    o = DCType(type)

    # Methods
    o.set_ctype(ctype)                 # add (str) of time ranges for ctype.
    ctype  = o.ctype()                 # returns (str) of ctype name.
    ranges = o.ranges()                # returns (dict) of time range objects.
    range  = o.range(begin, end)       # returns time stamp validity range object.
    ro     = o.range_for_tsec(tsec)    # (DCRange) range object for time stamp in (double) sec
    ro     = o.range_for_evt(evt)      # (DCRange) range object for psana.Evt object
    o.add_range(begin, end)            # add (str) of time ranges for ctype.
    kr = o.mark_range(begin, end)      # mark range from the DCType object, returns (str) key or None
    kr = o.mark_range_for_key(keyrange)# mark range specified by (str) keyrange from the DCType object, returns (str) key or None
    o.mark_ranges()                    # mark all ranges from the DCType object
    o.clear_ranges()                   # delete all range objects from dictionary.

    o.save(group)                      # saves object content under h5py.group in the hdf5 file.
    o.load(group)                      # loads object content from the hdf5 file.
    o.print_obj()                      # print info about this object and its children

See:
    * :class:`DCStore`
    * :class:`DCType`
    * :class:`DCRange`
    * :class:`DCVersion`
    * :class:`DCBase`
    * :class:`DCInterface`
    * :class:`DCUtils`
    * :class:`DCDetectorId`
    * :class:`DCConfigParameters`
    * :class:`DCFileName`
    * :class:`DCLogger`
    * :class:`DCMethods`
    * :class:`DCEmail`

This software was developed for the SIT project.
If you use all or part of it, please give an appropriate acknowledgment.

Created: 2016 by Mikhail Dubrovin
"""
from __future__ import print_function


import os
import sys
from PSCalib.DCInterface import DCTypeI
from PSCalib.DCLogger import log
from PSCalib.DCRange import DCRange, key
from PSCalib.DCUtils import sp, np, evt_time, get_subgroup, save_object_as_dset, delete_object


class DCType(DCTypeI):

    """Class for the Detector Calibration (DC) project

    Parameters

    ctype: gu.CTYPE - enumerated calibration type
    cmt  : str - comment
    """

    def __init__(self, ctype, cmt=None):
        DCTypeI.__init__(self, ctype, cmt)
        self._name = self.__class__.__name__
        self._dicranges = {}
        self._ctype = ctype
        log.debug('In c-tor for ctype: %s' % ctype, self._name)

    def ctype(self): return self._ctype

    def set_ctype(self, ctype): self._ctype = ctype

    def ranges(self): return self._dicranges

    def range(self, begin, end=None):
        return self._dicranges.get(key(begin, end), None) if begin is not None else None


    def add_range(self, begin, end=None, cmt=False):
        keyrng = key(begin, end)
        if keyrng in list(self._dicranges.keys()):
            return self._dicranges[keyrng]
        o = self._dicranges[keyrng] = DCRange(begin, end)

        #print('XXX add_range self._dicranges', self._dicranges)

        rec = self.make_record('add range', keyrng, cmt)
        if cmt is not False: self.add_history_record(rec)
        log.info(rec, self.__class__.__name__)
        return o


    def mark_range_for_key(self, keyrng, cmt=False):
        """Marks child object for deletion in save()"""
        if keyrng in list(self._dicranges.keys()):
            #o = self._dicranges[keyrng]
            #o.mark_versions()
            self._lst_del_keys.append(keyrng)

            rec = self.make_record('del range', keyrng, cmt)
            if cmt is not False: self.add_history_record(rec)
            log.info(rec, self.__class__.__name__)
            return keyrng
        else:
            msg = 'Marking of non-existent range %s' % str(keyrng)
            log.warning(msg, self._name)
            return None


    def mark_range(self, begin, end=None):
        """Marks child object for deletion in save()"""
        return self.mark_range_for_key(key(begin, end))


    def mark_ranges(self):
        """Marks all child objects for deletion in save()"""
        if keyrng in list(self._dicranges.keys()):
            self.mark_range_for_key(keyrng)
            #self._lst_del_keys.append(keyrng)


    def __del__(self):
        del self._dicranges
        #for keyrng in self._dicranges.keys():
        #    del self._dicranges[keyrng]


    def clear_ranges(self):
        self._dicranges.clear()


    def range_for_tsec(self, tsec):
        """Return DCRange object from all available which range validity is matched to tsec.
        """
        ranges = sorted(self.ranges().values())
        #print('XXX tsec, ranges:', tsec, ranges)
        for ro in ranges[::-1]:
            if ro.tsec_in_range(tsec): return ro
        return None


    def range_for_evt(self, evt):
        """Return DCRange object from all available which range validity is matched to the evt time.
        """
        return self.range_for_tsec(evt_time(evt))


    def save(self, group):
        grp = get_subgroup(group, self.ctype())
        ds1 = save_object_as_dset(grp, 'ctype', data=self.ctype()) # dtype='str'

        msg = '== save(), group %s object for %s' % (grp.name, self.ctype())
        log.debug(msg, self._name)

        # save/delete objects in/from hdf5 file
        for k,v in self._dicranges.items():
            if k in self._lst_del_keys: delete_object(grp, k)
            else: v.save(grp)

        # deletes items from dictionary
        for k in self._lst_del_keys:
            del self._dicranges[k]

        self._lst_del_keys = []

        self.save_base(grp)


    def load(self, grp):
        msg = '== load data from group %s and fill object %s' % (grp.name, self._name)
        log.debug(msg, self._name)

        #print('XXX DCType.load group file name: "%s"' % grp.file.name)

        for k,v in dict(grp).items():
            #subgrp = v
            #print 'XXX    ', k , v# , "   ", subg.name #, val, subg.len(), type(subg),

            if isinstance(v, sp.dataset_t):
                log.debug('load dataset "%s"' % k, self._name)
                if   k == 'ctype': self.set_ctype(v[0])
                else: log.warning('group "%s" has unrecognized dataset "%s"' % (grp.name, k), self._name)

            elif isinstance(v, sp.group_t):
                if self.is_base_group(k,v): continue
                log.debug('load group "%s"' % k, self._name)

                begin = v.get('begin')
                #if begin is None:
                if (begin is None) or (not isinstance(begin[0], float)):
                    msg = 'File: "%s"\n       has corrupted structure - group "%s" does not contain key "begin", keys: "%s"'%\
                          (grp.file.name, v.name, list(v.keys()))
                    log.error(msg, self._name)
                    print('ERROR:', self._name, msg)
                    continue

                end = v.get('end', None)

                #print('YYYY DCType end', end)
                #str_end = end[0].decode('utf-8') if isinstance(end[0], np.bytes_) else str(end[0])
                #print('YYYY DCType end, str_end', end, str_end)

                #if end is None or str_end!='end':
                #    msg = 'File: "%s"\n       has structure - group "%s" does not contain key "end", keys: "%s"'%\
                #          (grp.file.name, v.name, list(v.keys()))
                #    log.error(msg, self._name)
                #    print('ERROR:', self._name, msg)
                #    continue

                #print('ZZZ: name, k, v', v.name, v.keys(), v.values())
                #print("XXX:v['begin'][0], v['end'][0]", v['begin'][0], v['end'][0])
                #print("YYY: begin, end", begin, end)
                #print("YYY: begin, end", begin[0], end)

                end = 'end' if end is None else end[0]

                o = self.add_range(begin[0], end, cmt=False)
                o.load(v)

                #sys.exit('TEST EXIT')


    def print_obj(self):
        offset = 2 * self._offspace
        self.print_base(offset)
        print('%s ctype    %s' % (offset, self.ctype()))
        print('%s N ranges %s' % (offset, len(self.ranges())))
        print('%s ranges   %s' % (offset, str(list(self.ranges().keys()))))

        for k,v in self.ranges().items():
            v.print_obj()

#----------- TEST -------------

def test_DCType():

    o = DCType('pedestals')

    r = o.ctype()
    r = o.ranges()
    r = o.range(None)
    o.add_range(None)
    o.mark_range(None)
    o.mark_ranges()
    o.clear_ranges()

    #o.save(None)
    o.load(None)


def test():
    log.setPrintBits(0o377)
    if   len(sys.argv)==1: print('For test(s) use command: python %s <test-number=1-4>' % sys.argv[0])
    elif(sys.argv[1]=='1'): test_DCType()
    else: print('Non-expected arguments: sys.argv = %s use 1,2,...' % sys.argv)


if __name__ == "__main__":
    test()
    sys.exit( 'End of %s test.' % sys.argv[0])

# EOF
