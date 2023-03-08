#ifndef DUCKSTATION_COMPAT_H
#define DUCKSTATION_COMPAT_H

#include "../types.h"

#include <assert.h>

#ifdef _MSC_VER
#define ALWAYS_INLINE __forceinline
#else
#define ALWAYS_INLINE __attribute__((always_inline)) inline
#endif

#define AssertMsg(cond, msg) assert(cond && msg)
#define Assert(cond) assert(cond)

#define Panic(msg) assert(false && msg)

#ifdef _MSC_VER
#define UnreachableCode() __assume(false)
#else
#define UnreachableCode() __builtin_unreachable()
#endif

#endif