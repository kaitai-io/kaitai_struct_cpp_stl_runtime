#ifndef KAITAI_DETAIL_MAKE_UNSIGNED_H
#define KAITAI_DETAIL_MAKE_UNSIGNED_H

namespace kaitai {
    // poor man's implementation of `std::make_unsigned` in pre-C++11 versions
    // (https://stackoverflow.com/a/27577556)
    //
    // Don't use this externally. This is an internal implementation helper
    // and may be removed at any time.
    template<typename T> struct make_unsigned { typedef T type; };
    template<> struct make_unsigned<char> { typedef unsigned char type; };
    template<> struct make_unsigned<signed char> { typedef unsigned char type; };
    template<> struct make_unsigned<short> { typedef unsigned short type; };
    template<> struct make_unsigned<int> { typedef unsigned int type; };
    template<> struct make_unsigned<long> { typedef unsigned long type; };
    // `long long` is available only since C++11
}

#endif
