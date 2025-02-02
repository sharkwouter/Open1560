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
    data7:hash

    0x578040 | public: void __thiscall HashIterator::Begin(void) | ?Begin@HashIterator@@QAEXXZ
    0x578050 | public: int __thiscall HashIterator::Next(void) | ?Next@HashIterator@@QAEHXZ
    0x5780A0 | public: void __thiscall HashTable::Init(int) | ?Init@HashTable@@QAEXH@Z
    0x578110 | public: void __thiscall HashTable::Kill(void) | ?Kill@HashTable@@QAEXXZ
    0x578180 | public: void __thiscall HashTable::operator=(class HashTable &) | ??4HashTable@@QAEXAAV0@@Z
    0x5781D0 | public: int __thiscall HashTable::Insert(char *,void *) | ?Insert@HashTable@@QAEHPADPAX@Z
    0x5782B0 | public: int __thiscall HashTable::Delete(char *) | ?Delete@HashTable@@QAEHPAD@Z
    0x5783F0 | public: int __thiscall HashTable::Change(char *,char *) | ?Change@HashTable@@QAEHPAD0@Z
    0x578430 | public: void * __thiscall HashTable::Access(char *) | ?Access@HashTable@@QAEPAXPAD@Z
    0x5784C0 | private: int __thiscall HashTable::Hash(char *) | ?Hash@HashTable@@AAEHPAD@Z
    0x578500 | private: int __thiscall HashTable::ComputePrime(int) | ?ComputePrime@HashTable@@AAEHH@Z
    0x578550 | private: void __thiscall HashTable::Recompute(int) | ?Recompute@HashTable@@AAEXH@Z
    0x578610 | public: static void __cdecl HashTable::KillAll(void) | ?KillAll@HashTable@@SAXXZ
    0x578630 | private: void __thiscall HashTable::RemoveMe(void) | ?RemoveMe@HashTable@@AAEXXZ
    0x90AE5C | private: static class HashTable * HashTable::First | ?First@HashTable@@0PAV1@A
*/

struct HashEntry
{
    ConstString Key;
    void* Value {};
    HashEntry* Next {};
};

check_size(HashEntry, 0xC);

class HashTable
{
public:
    HashTable(const char* name)
        : HashTable(0, name)
    {}

    // TODO: Store name
    HashTable(i32 max_entries, [[maybe_unused]] const char* name)
        : bucket_count_(max_entries)
    {
        next_table_ = First;
        First = this;
    }

    // ??1HashTable@@QAE@XZ | inline
    ARTS_EXPORT ~HashTable()
    {
        Kill();
        RemoveMe();
    }

    // ??4HashTable@@QAEXAAV0@@Z | unused
    ARTS_EXPORT void operator=(HashTable& other);

    // ?Access@HashTable@@QAEPAXPAD@Z
    ARTS_EXPORT void* Access(const char* key);

    // ?Change@HashTable@@QAEHPAD0@Z | unused
    ARTS_EXPORT b32 Change(const char* old_key, const char* new_key);

    // ?Delete@HashTable@@QAEHPAD@Z
    ARTS_EXPORT b32 Delete(const char* key);

    // ?Init@HashTable@@QAEXH@Z
    ARTS_EXPORT void Init(i32 bucket_count);

    // ?Insert@HashTable@@QAEHPADPAX@Z
    ARTS_EXPORT b32 Insert(const char* key, void* value);

    // ?Kill@HashTable@@QAEXXZ
    ARTS_EXPORT void Kill();

    void Kill(void* context, void (*callback)(void* context, const char* key, void* value));

    // ?KillAll@HashTable@@SAXXZ
    ARTS_EXPORT static void KillAll();

    i32 Size() const
    {
        return value_count_;
    }

private:
    // ?ComputePrime@HashTable@@AAEHH@Z
    ARTS_EXPORT i32 ComputePrime(i32 value);

    // ?Hash@HashTable@@AAEHPAD@Z
    ARTS_EXPORT u32 Hash(const char* key);

    // ?Recompute@HashTable@@AAEXH@Z
    ARTS_EXPORT void Recompute(i32 capacity);

    // ?RemoveMe@HashTable@@AAEXXZ
    ARTS_EXPORT void RemoveMe();

    // ?First@HashTable@@0PAV1@A
    ARTS_EXPORT static HashTable* First;

    i32 bucket_count_ {};
    i32 value_count_ {};
    Ptr<HashEntry*[]> buckets_;
    HashTable* next_table_ {};

    friend struct HashIterator;
};

check_size(HashTable, 0x10);

struct HashIterator
{
public:
    HashIterator(HashTable& table)
        : Table(&table)
    {}

    // ?Begin@HashIterator@@QAEXXZ
    ARTS_EXPORT void Begin();

    // ?Next@HashIterator@@QAEHXZ
    ARTS_EXPORT b32 Next();

    HashEntry* operator->() const
    {
        return Current;
    }

    HashTable* Table {};
    i32 Index {};
    HashEntry* Current {};
};

check_size(HashIterator, 0xC);
