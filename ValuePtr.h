#ifndef VALUE_PTR_H
#define VALUE_PTR_H

template <typename T>
class ValuePtr
{
    T* ptr_;
public:
    ValuePtr(): ptr_(nullptr) { }

    ValuePtr(T* ptr): ptr_(ptr) { }

    ValuePtr(const ValuePtr& other)
    {
        if (other.get() != nullptr)
            ptr_ = new T(*other);
        else ptr_ = nullptr;
    }

    ValuePtr(ValuePtr&& other)
    {
        if (other.get() != nullptr)
            ptr_ = new T(std::move(*other));
        else ptr_ = nullptr;
    }

    ~ValuePtr() { if (ptr_ != nullptr) delete ptr_;}

    ValuePtr& operator=(const ValuePtr&) = delete;
    ValuePtr& operator=(ValuePtr&&) = delete;

    T& operator*() const { return *ptr_;}

    T* operator->() { return ptr_;}

    T* get() const { return ptr_;}
};

#endif

