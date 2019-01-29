#ifndef KAITAI_STRUCT_H
#define KAITAI_STRUCT_H

#include <map>
#include <kaitai/kaitaistream.h>


namespace kaitai {

class kstruct {
public:
    kstruct(kstream *_io = 0, bool own_io = false)
        : m__io(_io)
        , m_own_io(own_io) {}
    kstruct(const kstruct &other)
        : m__io(other.m__io)
        , m_own_io(other.m_own_io) {
        if (m_own_io && m__io) {
            m__io = new kstream(*m__io);
        }
    }
    virtual ~kstruct() {
        if (m_own_io && m__io) {
            delete m__io;
        }
    }
    virtual kstruct* clone() const {
        return new kstruct(*this);
    }
    virtual void _read() {}
    virtual void _write() {}
    virtual std::string to_string() const {
        return std::string();
    }
    virtual std::map<std::string, const void*> get_named_data() const {
        return std::map<std::string, const void*>();
    }

public:
    kstream *_io() {
        return m__io;
    }
    void set_io(kstream *_io) {
        m__io = _io;
    }
    bool own_io() {
        return m_own_io;
    }
    void set_own_io(bool own_io) {
        m_own_io = own_io;
    }

protected:
    kstream *m__io;
    bool m_own_io;
};

}


#endif
