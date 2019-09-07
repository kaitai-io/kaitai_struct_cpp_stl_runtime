#ifndef KAITAI_STREAM_H
#define KAITAI_STREAM_H

#include "kistream.h"

// Kaitai Struct runtime API version: x.y.z = 'xxxyyyzzz' decimal
#define KAITAI_STRUCT_VERSION 9000L

namespace kaitai {

// This typedef exists for API compatibility with previous versions of the
// KaitaiStruct C++ runtime.
typedef kistream kstream;

}

#endif
