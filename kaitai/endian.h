#ifndef KAITAI_ENDIAN_H
#define KAITAI_ENDIAN_H

#if defined(__APPLE__)
#include <machine/endian.h>
#include <libkern/OSByteOrder.h>
#define bswap_16(x) OSSwapInt16(x)
#define bswap_32(x) OSSwapInt32(x)
#define bswap_64(x) OSSwapInt64(x)
#define __BIG_ENDIAN    BIG_ENDIAN
#define __LITTLE_ENDIAN LITTLE_ENDIAN
#define __BYTE_ORDER    BYTE_ORDER
#elif defined(_MSC_VER) // !__APPLE__
#include <stdlib.h>
#define bswap_16(x) _byteswap_ushort(x)
#define bswap_32(x) _byteswap_ulong(x)
#define bswap_64(x) _byteswap_uint64(x)
#define __BIG_ENDIAN    4321
#define __LITTLE_ENDIAN 1234
#define __BYTE_ORDER    __LITTLE_ENDIAN
#else // !__APPLE__ or !_MSC_VER
#include <endian.h>
#include <byteswap.h>
#endif

#endif
