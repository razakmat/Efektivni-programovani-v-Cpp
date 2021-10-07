#include <cstdlib>
#include <string>
#include <map>
#include "LookupTable.h"

class LookupTable::Impl{
        std::map<int, std::string> data_;
    public:
        void insert(int key, const std::string& name)
        {
            data_.insert(std::make_pair(key, name));
        }
        void remove(int key)
        {
            data_.erase(key);
        }
        const std::string* name(int key) const
        {
            auto iter = data_.find(key);
            if (iter != data_.end())
                return &(iter->second);
            else
                return nullptr;
        }
        size_t count() const
        {
            return data_.size();
        }
        void clear()
        {
            data_.clear();
        }
};

LookupTable::LookupTable()
: m_pimpl( new Impl()) {}

LookupTable::~LookupTable()
{
    delete m_pimpl;
}

void LookupTable::insert(int key, const std::string& name)
{
    m_pimpl->insert(key,name);
}

void LookupTable::remove(int key)
{
    m_pimpl->remove(key);
}

const std::string* LookupTable::name(int key) const
{
    return m_pimpl->name(key);
}

size_t LookupTable::count() const
{
    return m_pimpl->count();
}

void LookupTable::clear()
{
    m_pimpl->clear();
}
