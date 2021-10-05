#include <cstdlib>
#include <string>

#include "LookupTable.h"

void LookupTable::insert(int key, const std::string& name)
{
    data_.insert(std::make_pair(key, name));
}

void LookupTable::remove(int key)
{
    data_.erase(key);
}

const std::string* LookupTable::name(int key) const
{
    auto iter = data_.find(key);
    if (iter != data_.end())
       return &(iter->second);
    else
       return nullptr;
}

size_t LookupTable::count() const
{
    return data_.size();
}

void LookupTable::clear()
{
    data_.clear();
}
