#ifndef VALUE_PTR_H
#define VALUE_PTR_H

template <typename T>
class ValuePtr
{

public:
    ValuePtr() { }

    ValuePtr(T* ptr) { }

    ValuePtr(const ValuePtr& other) { }

    ValuePtr(ValuePtr&& other) { }

    ~ValuePtr() { }

    ValuePtr& operator=(const ValuePtr&) = delete;
    ValuePtr& operator=(ValuePtr&&) = delete;

    T& operator*() { }

    T* operator->() { }

    T* get() { }
};

#endif