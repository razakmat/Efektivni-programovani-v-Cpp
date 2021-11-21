#include <iostream>
#include <string>

// header file optional.h

namespace epc {

struct in_place_t {
  explicit in_place_t() = default;
};

template <typename T>
class optional
{
    private:
        alignas(T) unsigned char buffer_[ sizeof(T) ];
        bool exist_;

    public:
        optional(): exist_(false)
        {
        }

        optional(const optional& other)
        {
        }

        optional(optional&& other)
        {
        }

        template <typename... Ts> optional(epc::in_place_t, Ts&&... args)
        {
            new (buffer_) T(std::forward<Ts>(args)...);
            exist_ = true;
        }

        ~optional()
        {
            if (exist_) reinterpret_cast<T*>(buffer_)->~T();
        }

        optional& operator=(const optional& other)
        {
        }

        optional& operator=(optional&& other)
        {

        }
        const T* operator->() const
        {
            return reinterpret_cast<const T*>(buffer_);
        }

        T* operator->()
        {
            return reinterpret_cast<T*>(buffer_);
        }

        const T& operator*() const
        {
            return reinterpret_cast<const T&>(buffer_);
        }

        T& operator*()
        {
            return reinterpret_cast<T&>(buffer_);
        }

        operator bool() const
        {
            return exist_;
        }

        void swap(optional& other)
        {
        }

        void reset()
        {
        }

        template <typename... Ts> void emplace(Ts&&... args)
        {
        }


};

template <typename T> void swap(optional<T>& a, optional<T>& b)
{
}

}