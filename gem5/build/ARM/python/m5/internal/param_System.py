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
            fp, pathname, description = imp.find_module('_param_System', [dirname(__file__)])
        except ImportError:
            import _param_System
            return _param_System
        if fp is not None:
            try:
                _mod = imp.load_module('_param_System', fp, pathname, description)
            finally:
                fp.close()
            return _mod
    _param_System = swig_import_helper()
    del swig_import_helper
else:
    import _param_System
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
class System(m5.internal.param_MemObject.MemObject):
    thisown = _swig_property(lambda x: x.this.own(), lambda x, v: x.this.own(v), doc='The membership flag')
    def __init__(self, *args, **kwargs): raise AttributeError("No constructor defined - class is abstract")
    __repr__ = _swig_repr
    def getMemoryMode(self): return _param_System.System_getMemoryMode(self)
    def setMemoryMode(self, *args): return _param_System.System_setMemoryMode(self, *args)
System_swigregister = _param_System.System_swigregister
System_swigregister(System)

class SystemParams(m5.internal.param_MemObject.MemObjectParams):
    thisown = _swig_property(lambda x: x.this.own(), lambda x, v: x.this.own(v), doc='The membership flag')
    __repr__ = _swig_repr
    def create(self): return _param_System.SystemParams_create(self)
    load_addr_mask = _swig_property(_param_System.SystemParams_load_addr_mask_get, _param_System.SystemParams_load_addr_mask_set)
    kernel = _swig_property(_param_System.SystemParams_kernel_get, _param_System.SystemParams_kernel_set)
    cache_line_size = _swig_property(_param_System.SystemParams_cache_line_size_get, _param_System.SystemParams_cache_line_size_set)
    mem_mode = _swig_property(_param_System.SystemParams_mem_mode_get, _param_System.SystemParams_mem_mode_set)
    work_end_ckpt_count = _swig_property(_param_System.SystemParams_work_end_ckpt_count_get, _param_System.SystemParams_work_end_ckpt_count_set)
    boot_osflags = _swig_property(_param_System.SystemParams_boot_osflags_get, _param_System.SystemParams_boot_osflags_set)
    memories = _swig_property(_param_System.SystemParams_memories_get, _param_System.SystemParams_memories_set)
    work_begin_ckpt_count = _swig_property(_param_System.SystemParams_work_begin_ckpt_count_get, _param_System.SystemParams_work_begin_ckpt_count_set)
    symbolfile = _swig_property(_param_System.SystemParams_symbolfile_get, _param_System.SystemParams_symbolfile_set)
    init_param = _swig_property(_param_System.SystemParams_init_param_get, _param_System.SystemParams_init_param_set)
    readfile = _swig_property(_param_System.SystemParams_readfile_get, _param_System.SystemParams_readfile_set)
    num_work_ids = _swig_property(_param_System.SystemParams_num_work_ids_get, _param_System.SystemParams_num_work_ids_set)
    work_cpus_ckpt_count = _swig_property(_param_System.SystemParams_work_cpus_ckpt_count_get, _param_System.SystemParams_work_cpus_ckpt_count_set)
    mem_ranges = _swig_property(_param_System.SystemParams_mem_ranges_get, _param_System.SystemParams_mem_ranges_set)
    work_begin_cpu_id_exit = _swig_property(_param_System.SystemParams_work_begin_cpu_id_exit_get, _param_System.SystemParams_work_begin_cpu_id_exit_set)
    load_offset = _swig_property(_param_System.SystemParams_load_offset_get, _param_System.SystemParams_load_offset_set)
    work_end_exit_count = _swig_property(_param_System.SystemParams_work_end_exit_count_get, _param_System.SystemParams_work_end_exit_count_set)
    work_item_id = _swig_property(_param_System.SystemParams_work_item_id_get, _param_System.SystemParams_work_item_id_set)
    work_begin_exit_count = _swig_property(_param_System.SystemParams_work_begin_exit_count_get, _param_System.SystemParams_work_begin_exit_count_set)
    port_system_port_connection_count = _swig_property(_param_System.SystemParams_port_system_port_connection_count_get, _param_System.SystemParams_port_system_port_connection_count_set)
    def __init__(self): 
        this = _param_System.new_SystemParams()
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _param_System.delete_SystemParams
    __del__ = lambda self : None;
SystemParams_swigregister = _param_System.SystemParams_swigregister
SystemParams_swigregister(SystemParams)



