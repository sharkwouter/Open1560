/*
    Open1560 - An Open Source Re-Implementation of Midtown Madness 1 Beta
    Copyright (C) 2020 Brick

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

/*
    stream:stream

    0x55E8B0 | public: __thiscall Stream::Stream(void *,int,class FileSystem *) | ??0Stream@@QAE@PAXHPAVFileSystem@@@Z
    0x55E940 | public: virtual __thiscall Stream::~Stream(void) | ??1Stream@@UAE@XZ
    0x55E9C0 | public: int __thiscall Stream::Read(void *,int) | ?Read@Stream@@QAEHPAXH@Z
    0x55EB00 | public: int __thiscall Stream::Write(void *,int) | ?Write@Stream@@QAEHPAXH@Z
    0x55EC00 | public: int __thiscall Stream::GetCh(void) | ?GetCh@Stream@@QAEHXZ
    0x55EC30 | public: int __thiscall Stream::PutCh(unsigned char) | ?PutCh@Stream@@QAEHE@Z
    0x55EC60 | public: int __thiscall Stream::Seek(int) | ?Seek@Stream@@QAEHH@Z
    0x55EC90 | public: int __thiscall Stream::Tell(void) | ?Tell@Stream@@QAEHXZ
    0x55ECA0 | public: int __thiscall Stream::Size(void) | ?Size@Stream@@QAEHXZ
    0x55ECC0 | public: int __thiscall Stream::Flush(void) | ?Flush@Stream@@QAEHXZ
    0x55ED30 | protected: virtual int __thiscall Stream::AlignSize(void) | ?AlignSize@Stream@@MAEHXZ
    0x55ED40 | protected: virtual int __thiscall Stream::GetError(char *,int) | ?GetError@Stream@@MAEHPADH@Z
    0x55ED80 | public: virtual void * __thiscall Stream::GetMapping(void) | ?GetMapping@Stream@@UAEPAXXZ
    0x55ED90 | public: virtual unsigned int __thiscall Stream::GetPagerHandle(void) | ?GetPagerHandle@Stream@@UAEIXZ
    0x55EDA0 | public: virtual int __thiscall Stream::GetPagingInfo(unsigned int &,unsigned int &,unsigned int &) | ?GetPagingInfo@Stream@@UAEHAAI00@Z
    0x55EDB0 | public: void __thiscall Stream::Error(char *) | ?Error@Stream@@QAEXPAD@Z
    0x55EDF0 | public: int __cdecl Stream::Printf(char const *,...) | ?Printf@Stream@@QAAHPBDZZ
    0x55EE40 | public: int __thiscall Stream::Vprintf(char const *,char *) | ?Vprintf@Stream@@QAEHPBDPAD@Z
    0x55EE90 | protected: virtual void __thiscall Stream::RawDebug(void) | ?RawDebug@Stream@@MAEXXZ
    0x55EEA0 | public: void __thiscall Stream::Debug(void) | ?Debug@Stream@@QAEXXZ
    0x55EEB0 | public: int __thiscall Stream::PutString(char *) | ?PutString@Stream@@QAEHPAD@Z
    0x55EEF0 | public: int __thiscall Stream::GetString(char *,int) | ?GetString@Stream@@QAEHPADH@Z
    0x55EF80 | public: int __thiscall Stream::Put(unsigned char) | ?Put@Stream@@QAEHE@Z
    0x55EFA0 | public: int __thiscall Stream::Put(unsigned short) | ?Put@Stream@@QAEHG@Z
    0x55EFD0 | public: int __thiscall Stream::Put(unsigned long) | ?Put@Stream@@QAEHK@Z
    0x55F020 | public: int __thiscall Stream::Put(float) | ?Put@Stream@@QAEHM@Z
    0x55F080 | public: int __thiscall Stream::Put(unsigned char *,int) | ?Put@Stream@@QAEHPAEH@Z
    0x55F0A0 | public: int __thiscall Stream::Put(unsigned short *,int) | ?Put@Stream@@QAEHPAGH@Z
    0x55F100 | public: int __thiscall Stream::Put(unsigned long *,int) | ?Put@Stream@@QAEHPAKH@Z
    0x55F170 | public: int __thiscall Stream::Get(unsigned char *,int) | ?Get@Stream@@QAEHPAEH@Z
    0x55F190 | public: int __thiscall Stream::Get(unsigned short *,int) | ?Get@Stream@@QAEHPAGH@Z
    0x55F1D0 | public: int __thiscall Stream::Get(unsigned long *,int) | ?Get@Stream@@QAEHPAKH@Z
    0x55F210 | private: static void __cdecl Stream::SwapShorts(unsigned short *,int) | ?SwapShorts@Stream@@CAXPAGH@Z
    0x55F240 | private: static void __cdecl Stream::SwapLongs(unsigned long *,int) | ?SwapLongs@Stream@@CAXPAKH@Z
    0x55F290 | public: unsigned short __thiscall Stream::GetShort(void) | ?GetShort@Stream@@QAEGXZ
    0x55F2B0 | public: unsigned long __thiscall Stream::GetLong(void) | ?GetLong@Stream@@QAEKXZ
    0x55F2D0 | void __cdecl fprintf(class Stream *,char const *,...) | ?fprintf@@YAXPAVStream@@PBDZZ
    0x55F2F0 | class Stream * __cdecl fopen(char *,char *) | ?fopen@@YAPAVStream@@PAD0@Z
    0x55F330 | int __cdecl fseek(class Stream *,int,int) | ?fseek@@YAHPAVStream@@HH@Z
    0x55F390 | _vprintf
    0x55F3B0 | _printf
    0x55F3E0 | int __cdecl fgets(char *,int,class Stream *) | ?fgets@@YAHPADHPAVStream@@@Z
    0x55F450 | int __cdecl fscanf(class Stream *,char const *,...) | ?fscanf@@YAHPAVStream@@PBDZZ
    0x55F500 | public: virtual void * __thiscall Stream::`vector deleting destructor'(unsigned int) | ??_EStream@@UAEPAXI@Z
    0x55F500 | public: virtual void * __thiscall Stream::`scalar deleting destructor'(unsigned int) | ??_GStream@@UAEPAXI@Z
    0x6218E8 | const Stream::`vftable' | ??_7Stream@@6B@
    0x907960 | int EnableBinaryFileMapping | ?EnableBinaryFileMapping@@3HA
*/

#include "data7/base.h"

#include "core/endian.h"

class FileSystem;

#define ARTS_STREAM_MANAGED_BUFFER 0x1
#define ARTS_STREAM_SUPPORTS_MAPPING 0x2

class Stream : public Base
{
public:
    // ??0Stream@@QAE@PAXHPAVFileSystem@@@Z
    ARTS_EXPORT Stream(void* buffer, isize buffer_size, FileSystem* file_system);

    // ??_GStream@@UAEPAXI@Z
    // ??1Stream@@UAE@XZ
    ARTS_EXPORT ~Stream() override;

    // ?GetMapping@Stream@@UAEPAXXZ
    ARTS_EXPORT virtual void* GetMapping();

    // ?GetPagerHandle@Stream@@UAEIXZ
    ARTS_EXPORT virtual usize GetPagerHandle();

    // ?GetPagingInfo@Stream@@UAEHAAI00@Z
    ARTS_EXPORT virtual b32 GetPagingInfo(usize& handle, u32& offset, u32& size);

    virtual isize RawRead(void* arg1, isize arg2) = 0;

    virtual isize RawWrite(const void* arg1, isize arg2) = 0;

    virtual i32 RawSeek(i32 arg1) = 0;

    virtual i32 RawTell() = 0;

    virtual i32 RawSize() = 0;

    // ?Debug@Stream@@QAEXXZ | unused
    ARTS_EXPORT void Debug();

    // ?Error@Stream@@QAEXPAD@Z
    ARTS_EXPORT void Error(const char* msg);

    // ?Flush@Stream@@QAEHXZ
    ARTS_EXPORT isize Flush();

    // ?Get@Stream@@QAEHPAGH@Z
    ARTS_EXPORT isize Get(u16* values, isize count);

    // ?Get@Stream@@QAEHPAKH@Z
    ARTS_EXPORT isize Get(u32* values, isize count);

    // ?Get@Stream@@QAEHPAEH@Z
    ARTS_EXPORT isize Get(u8* values, isize count)
    {
        return Read(values, count);
    }

    // ?GetCh@Stream@@QAEHXZ
    ARTS_EXPORT i32 GetCh()
    {
        if (buffer_head_ < buffer_read_)
            return buffer_[buffer_head_++];

        u8 result = 0;

        if (Read(&result, 1) == 1)
            return result;

        return -1;
    }

    i32 UnGetCh(i32 ch)
    {
        if (buffer_read_ != 0 && buffer_head_ != 0)
        {
            buffer_[--buffer_head_] = static_cast<u8>(ch);

            return ch;
        }

        return -1;
    }

    // ?GetLong@Stream@@QAEKXZ | unused
    [[deprecated]] ARTS_EXPORT u32 GetLong()
    {
        return Get<u32>();
    }

    // ?GetShort@Stream@@QAEGXZ | unused
    [[deprecated]] ARTS_EXPORT u16 GetShort()
    {
        return Get<u16>();
    }

    // ?GetString@Stream@@QAEHPADH@Z | unused
    ARTS_EXPORT isize GetString(char* buffer, isize buffer_len);

    ConstString GetString();

    // ?Printf@Stream@@QAAHPBDZZ | unused
    ARTS_EXPORT isize Printf(ARTS_FORMAT_STRING const char* format, ...);

    i32 Scanf(const char* format, ...);

    i32 Vscanf(const char* format, std::va_list va);

    isize Gets(char* buffer, isize buffer_len);

    // ?Put@Stream@@QAEHM@Z
    ARTS_EXPORT isize Put(f32 value);

    // ?Put@Stream@@QAEHG@Z
    ARTS_EXPORT isize Put(u16 value);

    // ?Put@Stream@@QAEHK@Z
    ARTS_EXPORT isize Put(u32 value);

    // ?Put@Stream@@QAEHE@Z
    ARTS_EXPORT isize Put(u8 value);

    // ?Put@Stream@@QAEHPAGH@Z
    ARTS_EXPORT isize Put(const u16* values, isize count);

    // ?Put@Stream@@QAEHPAKH@Z
    ARTS_EXPORT isize Put(const u32* values, isize count);

    // ?Put@Stream@@QAEHPAEH@Z
    ARTS_EXPORT isize Put(const u8* values, isize count);

    // ?PutCh@Stream@@QAEHE@Z
    ARTS_EXPORT i32 PutCh(u8 value)
    {
        if ((buffer_read_ == 0) && (buffer_head_ < buffer_capacity_))
        {
            buffer_[buffer_head_++] = value;

            return value;
        }

        if (Write(&value, 1) == 1)
            return value;

        return -1;
    }

    // ?PutString@Stream@@QAEHPAD@Z
    ARTS_EXPORT isize PutString(const char* str);

    // ?Read@Stream@@QAEHPAXH@Z
    ARTS_EXPORT isize Read(void* ptr, isize size);

    // ?Seek@Stream@@QAEHH@Z
    ARTS_EXPORT i32 Seek(i32 position);

    // ?Size@Stream@@QAEHXZ
    ARTS_EXPORT i32 Size();

    // ?Tell@Stream@@QAEHXZ
    ARTS_EXPORT i32 Tell()
    {
        return position_ + buffer_head_;
    }

    // ?Vprintf@Stream@@QAEHPBDPAD@Z
    ARTS_EXPORT isize Vprintf(const char* format, std::va_list va);

    // ?Write@Stream@@QAEHPAXH@Z
    ARTS_EXPORT isize Write(const void* ptr, isize size);

    template <typename T>
    T Get();

    template <typename T>
    void GetN(T* values, isize count);

    // Returns file mapping if available, otherwise allocates a buffer and reads
    template <typename T>
    /*const */ T* ReadMapped(isize count);

    bool SupportsMapping() const
    {
        return flags_ & ARTS_STREAM_SUPPORTS_MAPPING;
    }

protected:
    // ?RawDebug@Stream@@MAEXXZ
    ARTS_EXPORT virtual void RawDebug();

    // ?AlignSize@Stream@@MAEHXZ
    ARTS_EXPORT virtual i32 AlignSize();

    // ?GetError@Stream@@MAEHPADH@Z
    ARTS_EXPORT virtual i32 GetError(char* buf, isize buf_len);

    u8* buffer_ {};

    // TODO: Use u64
    u32 position_ {};

    u32 buffer_head_ {};
    u32 buffer_read_ {};
    u32 buffer_capacity_ {};

    FileSystem* file_system_ {};

    // ARTS_STREAM_*
    u8 flags_ {};

    u8 swap_endian_ {};
    u8 little_endian_ {};
    u8 initialized_ {};

private:
    // ?SwapLongs@Stream@@CAXPAKH@Z
    ARTS_EXPORT static void SwapLongs(u32* values, isize count);

    // ?SwapShorts@Stream@@CAXPAGH@Z
    ARTS_EXPORT static void SwapShorts(u16* values, isize count);
};

check_size(Stream, 0x20);

// ?fgets@@YAHPADHPAVStream@@@Z
ARTS_EXPORT isize arts_fgets(char* buffer, isize buffer_len, Stream* stream);

// ?fopen@@YAPAVStream@@PAD0@Z
ARTS_EXPORT Stream* arts_fopen(const char* path, const char* mode);

// ?fprintf@@YAXPAVStream@@PBDZZ
ARTS_EXPORT void arts_fprintf(Stream* stream, ARTS_FORMAT_STRING const char* format, ...);

// ?fscanf@@YAHPAVStream@@PBDZZ
ARTS_EXPORT i32 arts_fscanf(Stream* stream, const char* format, ...);

// ?fseek@@YAHPAVStream@@HH@Z
ARTS_EXPORT i32 arts_fseek(Stream* stream, i32 offset, i32 origin);

// ?EnableBinaryFileMapping@@3HA
ARTS_EXPORT extern b32 EnableBinaryFileMapping;

// _printf | void

// _vprintf | void

template <typename T>
ARTS_NOINLINE inline T Stream::Get()
{
    T value {};

    // TODO: Handle incomplete read
    Read(&value, sizeof(value));

    if (swap_endian_)
        value = ByteSwap<T>(value);

    return value;
}

template <typename T>
ARTS_NOINLINE inline void Stream::GetN(T* values, isize count)
{
    // TODO: Handle incomplete read
    Read(values, sizeof(T) * count);

    if (swap_endian_)
        ByteSwapN(values, count);
}

template <typename T>
inline T* Stream::ReadMapped(isize count)
{
    T* result = nullptr;

    if (EnableBinaryFileMapping && SupportsMapping())
    {
        result = reinterpret_cast<T*>(static_cast<u8*>(GetMapping()) + Tell());
        Seek(Tell() + count * sizeof(T));
    }
    else
    {
        result = new T[count];
        Read(result, count * sizeof(T));
    }

    return result;
}
