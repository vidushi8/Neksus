/** \file DMA_State.hh
 *
 * Auto generated C++ code started by /data1/home/vidushi/GemDroid_booksim_pack_grnl_sip/gem5/src/mem/slicc/symbols/Type.py:465
 */

#ifndef __DMA_State_HH__
#define __DMA_State_HH__

#include <iostream>
#include <string>

#include "mem/protocol/AccessPermission.hh"

// Class definition
/** \enum DMA_State
 *  \brief DMA states
 */
enum DMA_State {
    DMA_State_FIRST,
    DMA_State_READY = DMA_State_FIRST, /**< Ready to accept a new request */
    DMA_State_BUSY_RD, /**< Busy: currently processing a request */
    DMA_State_BUSY_WR, /**< Busy: currently processing a request */
    DMA_State_NUM
};

// Code to convert from a string to the enumeration
DMA_State string_to_DMA_State(const std::string& str);

// Code to convert state to a string
std::string DMA_State_to_string(const DMA_State& obj);

// Code to increment an enumeration type
DMA_State &operator++(DMA_State &e);

// Code to convert the current state to an access permission
AccessPermission DMA_State_to_permission(const DMA_State& obj);

std::ostream& operator<<(std::ostream& out, const DMA_State& obj);

#endif // __DMA_State_HH__
