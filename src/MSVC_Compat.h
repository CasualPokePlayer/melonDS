/*
    Copyright 2016-2022 melonDS team

    This file is part of melonDS.

    melonDS is free software: you can redistribute it and/or modify it under
    the terms of the GNU General Public License as published by the Free
    Software Foundation, either version 3 of the License, or (at your option)
    any later version.

    melonDS is distributed in the hope that it will be useful, but WITHOUT ANY
    WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
    FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with melonDS. If not, see http://www.gnu.org/licenses/.
*/

#pragma once

#include <io.h>
#include <intrin.h>
#include <string.h>
#include <time.h>

static __forceinline int __builtin_ctz(unsigned int mask)
{
    unsigned long index;
    if (_BitScanForward(&index, mask))
        return index;
    return 32;
}

static __forceinline int __builtin_ctzll(unsigned long long mask)
{
    unsigned long index;
#ifdef _WIN64
    if (_BitScanForward64(&index, mask))
        return index;
#else
    if (_BitScanForward(&index, mask))
        return index;
    if (_BitScanForward(&index, mask >> 32))
        return index + 32;
#endif
    return 64;
}

__declspec(noreturn) static __forceinline void __builtin_unreachable(void)
{
    __assume(0);
}

static __forceinline struct tm* localtime_r(const time_t* timer, struct tm* buf)
{
    localtime_s(buf, timer);
    return buf;
}

static __forceinline int strncasecmp(const char* s1, const char* s2, size_t n)
{
    return _strnicmp(s1, s2, n);
}

static __forceinline int strcasecmp(const char* s1, const char* s2)
{
    return _stricmp(s1, s2);
}

static __forceinline int dup(int fd)
{
    return _dup(fd);
}
