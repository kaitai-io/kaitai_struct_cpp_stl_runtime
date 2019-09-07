#ifndef KAITAI_STRUCT_H
#define KAITAI_STRUCT_H

#include <kaitai/kaitaistream.h>

namespace kaitai {

class kstruct {
public:
    kstruct(kistream *_io) { m__io = _io; }
    virtual ~kstruct() {}
protected:
    kistream *m__io;
public:
    kistream *_io() { return m__io; }
};

}

#endif
