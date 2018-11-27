# This file was automatically generated by SWIG (http://www.swig.org).
# Version 3.0.8
#
# Do not make changes to this file unless you know what you are doing--modify
# the SWIG interface file instead.





from sys import version_info
if version_info >= (2, 6, 0):
    def swig_import_helper():
        from os.path import dirname
        import imp
        fp = None
        try:
            fp, pathname, description = imp.find_module('_param_CommMonitor', [dirname(__file__)])
        except ImportError:
            import _param_CommMonitor
            return _param_CommMonitor
        if fp is not None:
            try:
                _mod = imp.load_module('_param_CommMonitor', fp, pathname, description)
            finally:
                fp.close()
            return _mod
    _param_CommMonitor = swig_import_helper()
    del swig_import_helper
else:
    import _param_CommMonitor
del version_info
try:
    _swig_property = property
except NameError:
    pass  # Python < 2.2 doesn't have 'property'.


def _swig_setattr_nondynamic(self, class_type, name, value, static=1):
    if (name == "thisown"):
        return self.this.own(value)
    if (name == "this"):
        if type(value).__name__ == 'SwigPyObject':
            self.__dict__[name] = value
            return
    method = class_type.__swig_setmethods__.get(name, None)
    if method:
        return method(self, value)
    if (not static):
        object.__setattr__(self, name, value)
    else:
        raise AttributeError("You cannot add attributes to %s" % self)


def _swig_setattr(self, class_type, name, value):
    return _swig_setattr_nondynamic(self, class_type, name, value, 0)


def _swig_getattr_nondynamic(self, class_type, name, static=1):
    if (name == "thisown"):
        return self.this.own()
    method = class_type.__swig_getmethods__.get(name, None)
    if method:
        return method(self)
    if (not static):
        return object.__getattr__(self, name)
    else:
        raise AttributeError(name)

def _swig_getattr(self, class_type, name):
    return _swig_getattr_nondynamic(self, class_type, name, 0)


def _swig_repr(self):
    try:
        strthis = "proxy of " + self.this.__repr__()
    except Exception:
        strthis = ""
    return "<%s.%s; %s >" % (self.__class__.__module__, self.__class__.__name__, strthis,)

try:
    _object = object
    _newclass = 1
except AttributeError:
    class _object:
        pass
    _newclass = 0



def _swig_setattr_nondynamic_method(set):
    def set_attr(self, name, value):
        if (name == "thisown"):
            return self.this.own(value)
        if hasattr(self, name) or (name == "this"):
            set(self, name, value)
        else:
            raise AttributeError("You cannot add attributes to %s" % self)
    return set_attr


import m5.internal.param_System
import m5.internal.enum_MemoryMode
import m5.internal.AbstractMemory_vector
import m5.internal.param_AbstractMemory
import m5.internal.param_MemObject
import m5.internal.param_ClockedObject
import m5.internal.param_ClockDomain
import m5.internal.param_SimObject
import m5.internal.drain
import m5.internal.serialize
import m5.internal.AddrRange_vector
class CommMonitor(m5.internal.param_MemObject.MemObject):
    thisown = _swig_property(lambda x: x.this.own(), lambda x, v: x.this.own(v), doc='The membership flag')

    def __init__(self, *args, **kwargs):
        raise AttributeError("No constructor defined - class is abstract")
    __repr__ = _swig_repr
CommMonitor_swigregister = _param_CommMonitor.CommMonitor_swigregister
CommMonitor_swigregister(CommMonitor)

class CommMonitorParams(m5.internal.param_MemObject.MemObjectParams):
    thisown = _swig_property(lambda x: x.this.own(), lambda x, v: x.this.own(v), doc='The membership flag')
    __repr__ = _swig_repr

    def create(self):
        return _param_CommMonitor.CommMonitorParams_create(self)
    disable_burst_length_hists = _swig_property(_param_CommMonitor.CommMonitorParams_disable_burst_length_hists_get, _param_CommMonitor.CommMonitorParams_disable_burst_length_hists_set)
    read_addr_mask = _swig_property(_param_CommMonitor.CommMonitorParams_read_addr_mask_get, _param_CommMonitor.CommMonitorParams_read_addr_mask_set)
    trace_file = _swig_property(_param_CommMonitor.CommMonitorParams_trace_file_get, _param_CommMonitor.CommMonitorParams_trace_file_set)
    trace_enable = _swig_property(_param_CommMonitor.CommMonitorParams_trace_enable_get, _param_CommMonitor.CommMonitorParams_trace_enable_set)
    trace_compress = _swig_property(_param_CommMonitor.CommMonitorParams_trace_compress_get, _param_CommMonitor.CommMonitorParams_trace_compress_set)
    bandwidth_bins = _swig_property(_param_CommMonitor.CommMonitorParams_bandwidth_bins_get, _param_CommMonitor.CommMonitorParams_bandwidth_bins_set)
    disable_itt_dists = _swig_property(_param_CommMonitor.CommMonitorParams_disable_itt_dists_get, _param_CommMonitor.CommMonitorParams_disable_itt_dists_set)
    system = _swig_property(_param_CommMonitor.CommMonitorParams_system_get, _param_CommMonitor.CommMonitorParams_system_set)
    disable_transaction_hists = _swig_property(_param_CommMonitor.CommMonitorParams_disable_transaction_hists_get, _param_CommMonitor.CommMonitorParams_disable_transaction_hists_set)
    sample_period = _swig_property(_param_CommMonitor.CommMonitorParams_sample_period_get, _param_CommMonitor.CommMonitorParams_sample_period_set)
    disable_latency_hists = _swig_property(_param_CommMonitor.CommMonitorParams_disable_latency_hists_get, _param_CommMonitor.CommMonitorParams_disable_latency_hists_set)
    disable_outstanding_hists = _swig_property(_param_CommMonitor.CommMonitorParams_disable_outstanding_hists_get, _param_CommMonitor.CommMonitorParams_disable_outstanding_hists_set)
    disable_bandwidth_hists = _swig_property(_param_CommMonitor.CommMonitorParams_disable_bandwidth_hists_get, _param_CommMonitor.CommMonitorParams_disable_bandwidth_hists_set)
    write_addr_mask = _swig_property(_param_CommMonitor.CommMonitorParams_write_addr_mask_get, _param_CommMonitor.CommMonitorParams_write_addr_mask_set)
    latency_bins = _swig_property(_param_CommMonitor.CommMonitorParams_latency_bins_get, _param_CommMonitor.CommMonitorParams_latency_bins_set)
    outstanding_bins = _swig_property(_param_CommMonitor.CommMonitorParams_outstanding_bins_get, _param_CommMonitor.CommMonitorParams_outstanding_bins_set)
    disable_addr_dists = _swig_property(_param_CommMonitor.CommMonitorParams_disable_addr_dists_get, _param_CommMonitor.CommMonitorParams_disable_addr_dists_set)
    burst_length_bins = _swig_property(_param_CommMonitor.CommMonitorParams_burst_length_bins_get, _param_CommMonitor.CommMonitorParams_burst_length_bins_set)
    transaction_bins = _swig_property(_param_CommMonitor.CommMonitorParams_transaction_bins_get, _param_CommMonitor.CommMonitorParams_transaction_bins_set)
    itt_bins = _swig_property(_param_CommMonitor.CommMonitorParams_itt_bins_get, _param_CommMonitor.CommMonitorParams_itt_bins_set)
    itt_max_bin = _swig_property(_param_CommMonitor.CommMonitorParams_itt_max_bin_get, _param_CommMonitor.CommMonitorParams_itt_max_bin_set)
    port_slave_connection_count = _swig_property(_param_CommMonitor.CommMonitorParams_port_slave_connection_count_get, _param_CommMonitor.CommMonitorParams_port_slave_connection_count_set)
    port_master_connection_count = _swig_property(_param_CommMonitor.CommMonitorParams_port_master_connection_count_get, _param_CommMonitor.CommMonitorParams_port_master_connection_count_set)

    def __init__(self):
        this = _param_CommMonitor.new_CommMonitorParams()
        try:
            self.this.append(this)
        except Exception:
            self.this = this
    __swig_destroy__ = _param_CommMonitor.delete_CommMonitorParams
    __del__ = lambda self: None
CommMonitorParams_swigregister = _param_CommMonitor.CommMonitorParams_swigregister
CommMonitorParams_swigregister(CommMonitorParams)



