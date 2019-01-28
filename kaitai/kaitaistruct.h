#ifndef KAITAI_STRUCT_H
#define KAITAI_STRUCT_H

#include <map>
#include <kaitai/kaitaistream.h>


namespace kaitai {

class kstruct {
public:
    kstruct(kstream *_io = 0) : m__io(_io) {}
    virtual ~kstruct() {}
    virtual kstruct* clone() const { return new kstruct(*this); }
    virtual void _read() {}
    virtual void _write() {}
    virtual std::string to_string() const { return std::string(); }
    virtual std::map<std::string, const void*> get_named_data() const { return std::map<std::string, const void*>(); }
protected:
    kstream *m__io;
public:
    kstream *_io() { return m__io; }
    void _set_io(kstream *_io) { m__io = _io; }
};

}


#endif
