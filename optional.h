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
        alignas(T) T buffer_[ sizeof(T) ];
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

        template <typename... Ts> optional(Ts&&... args)
        {
        }

        ~optional()
        {
        }

        optional& operator=(const optional& other)
        {
        }

        optional& operator=(optional&& other)
        {

        }
        const T* operator->() const
        {
        }

        T* operator->()
        {
        }

        const T& operator*() const
        {
        }

        T& operator*()
        {
        }

        operator bool() const
        {
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

using namespace std;

int main() {



}