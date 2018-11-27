# This file was automatically generated by SWIG (http://www.swig.org).
# Version 2.0.10
#
# Do not make changes to this file unless you know what you are doing--modify
# the SWIG interface file instead.



from sys import version_info
if version_info >= (2,6,0):
    def swig_import_helper():
        from os.path import dirname
        import imp
        fp = None
        try:
            fp, pathname, description = imp.find_module('_param_AmbaPioDevice', [dirname(__file__)])
        except ImportError:
            import _param_AmbaPioDevice
            return _param_AmbaPioDevice
        if fp is not None:
            try:
                _mod = imp.load_module('_param_AmbaPioDevice', fp, pathname, description)
            finally:
                fp.close()
            return _mod
    _param_AmbaPioDevice = swig_import_helper()
    del swig_import_helper
else:
    import _param_AmbaPioDevice
del version_info
try:
    _swig_property = property
except NameError:
    pass # Python < 2.2 doesn't have 'property'.
def _swig_setattr_nondynamic(self,class_type,name,value,static=1):
    if (name == "thisown"): return self.this.own(value)
    if (name == "this"):
        if type(value).__name__ == 'SwigPyObject':
            self.__dict__[name] = value
            return
    method = class_type.__swig_setmethods__.get(name,None)
    if method: return method(self,value)
    if (not static):
        self.__dict__[name] = value
    else:
        raise AttributeError("You cannot add attributes to %s" % self)

def _swig_setattr(self,class_type,name,value):
    return _swig_setattr_nondynamic(self,class_type,name,value,0)

def _swig_getattr(self,class_type,name):
    if (name == "thisown"): return self.this.own()
    method = class_type.__swig_getmethods__.get(name,None)
    if method: return method(self)
    raise AttributeError(name)

def _swig_repr(self):
    try: strthis = "proxy of " + self.this.__repr__()
    except: strthis = ""
    return "<%s.%s; %s >" % (self.__class__.__module__, self.__class__.__name__, strthis,)

try:
    _object = object
    _newclass = 1
except AttributeError:
    class _object : pass
    _newclass = 0


def _swig_setattr_nondynamic_method(set):
    def set_attr(self,name,value):
        if (name == "thisown"): return self.this.own(value)
        if hasattr(self,name) or (name == "this"):
            set(self,name,value)
        else:
            raise AttributeError("You cannot add attributes to %s" % self)
    return set_attr


import m5.internal.param_BasicPioDevice
import m5.internal.param_PioDevice
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
class AmbaPioDevice(m5.internal.param_BasicPioDevice.BasicPioDevice):
    thisown = _swig_property(lambda x: x.this.own(), lambda x, v: x.this.own(v), doc='The membership flag')
    def __init__(self, *args, **kwargs): raise AttributeError("No constructor defined - class is abstract")
    __repr__ = _swig_repr
AmbaPioDevice_swigregister = _param_AmbaPioDevice.AmbaPioDevice_swigregister
AmbaPioDevice_swigregister(AmbaPioDevice)

class AmbaPioDeviceParams(m5.internal.param_BasicPioDevice.BasicPioDeviceParams):
    thisown = _swig_property(lambda x: x.this.own(), lambda x, v: x.this.own(v), doc='The membership flag')
    __repr__ = _swig_repr
    amba_id = _swig_property(_param_AmbaPioDevice.AmbaPioDeviceParams_amba_id_get, _param_AmbaPioDevice.AmbaPioDeviceParams_amba_id_set)
    def __init__(self): 
        this = _param_AmbaPioDevice.new_AmbaPioDeviceParams()
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _param_AmbaPioDevice.delete_AmbaPioDeviceParams
    __del__ = lambda self : None;
AmbaPioDeviceParams_swigregister = _param_AmbaPioDevice.AmbaPioDeviceParams_swigregister
AmbaPioDeviceParams_swigregister(AmbaPioDeviceParams)



