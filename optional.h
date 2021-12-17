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
            if (other)
            {
                new (buffer_) T(*other);
                exist_ = true;
            }
            else
                exist_ = false;
        }

        optional(optional&& other)
        {
            if (other)
            {
                new (buffer_) T(std::move(*other));
                exist_ = true;
            }
            else
                exist_ = false;
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
            if (this != &other) {
                if (exist_ && other) reinterpret_cast<T&>(buffer_) = *other;
                else if (other) {
                    new (buffer_) T(*other);
                    exist_ = true;
                }
                else if (exist_) {
                    reinterpret_cast<T*>(buffer_)->~T(); 
                    exist_ = false; 
                }
            }
            return *this;
        }

        optional& operator=(optional&& other)
        {
            if (this != &other) {
                if (exist_ && other) 
                    reinterpret_cast<T&>(buffer_) = std::move(*other);
                else if (other) {
                    new (buffer_) T(std::move(*other));
                    exist_ = true;
                }
                else if (exist_) {
                    reinterpret_cast<T*>(buffer_)->~T(); 
                    exist_ = false; 
                }
            }
            return *this;
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
            if (this != &other) {
                if (exist_ && other) {
                    using std::swap;
                    swap(**this, *other);
                }
                else if (other) {
                    new (buffer_) T(std::move(*other));
                    exist_ = true;
                    other->~T();
                    other.exist_ = false;

                }
                else if (exist_) {
                    new (reinterpret_cast<void*>(&other)) T(std::move(**this));
                    other.exist_ = true;
                    reinterpret_cast<T*>(buffer_)->~T();
                    exist_ = false;
                }
            }
        }

        void reset()
        {
            if (exist_)
            {
                reinterpret_cast<T*>(buffer_)->~T();
                exist_ = false;
            }
        }

        template <typename... Ts> void emplace(Ts&&... args)
        {
            if (exist_)
                reinterpret_cast<T*>(buffer_)->~T();
            new (buffer_) T(std::forward<Ts>(args)...);
            exist_ = true;
        }


};

template <typename T> void swap(optional<T>& a, optional<T>& b)
{
    a.swap(b);
}

}