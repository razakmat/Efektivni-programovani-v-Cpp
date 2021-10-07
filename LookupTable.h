#ifndef LOOKUPTABLE_H
#define LOOKUPTABLE_H

#include <cstdlib>
#include <map>
#include <string>

class LookupTable
{
    class Impl;
    Impl * m_pimpl;

public:
    LookupTable();
    ~LookupTable();

    // copy and move semantics deleted for sake of simplicity:
    LookupTable(const LookupTable&) = delete;
    LookupTable(LookupTable&&) = delete;
    LookupTable& operator=(const LookupTable&) = delete;
    LookupTable& operator=(LookupTable&&) = delete;

    void insert(int key, const std::string& name);
    void remove(int key);

    const std::string* name(int key) const;

    size_t count() const;
    void clear();
};

#endif
