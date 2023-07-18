#ifndef SOUL_COLLECTIONS_PTR_VIEW_HPP
#define SOUL_COLLECTIONS_PTR_VIEW_HPP

#include "../logging.hpp"
#include "../stypes.hpp"


namespace soul 
{
    template <typename T>
    class ptr_view
    {
    private:
        byte* begin_;
        byte* end_;

    public:
        ptr_view(T* val)
        {
            if (val == nullptr) SOUL_PANIC("ptr_view: val is nullptr");

            begin_ = val;
            end_ = (byte*)(val + 1) - 1;
        }

        ptr_view(T* val, size_t size)
        {
            if (val == nullptr) SOUL_PANIC("ptr_view: val is nullptr");

            begin_ = val;
            end_ = (byte*)val + size - 1;
        }

        ptr_view(T& val)
        {
            begin_ = (byte*)&val;
            end_ = (byte*)(&val + 1) - 1;
        }

        T* operator&()
        { return (T*)begin_; }

        T operator*()
        { return *(T*)begin_; }

        void operator=(const T& ptr)
        {
            begin_ = (byte*)&ptr;
        }
        
        void operator=(const T* ptr)
        {
            begin_ = (byte*)ptr;
        }


        T* begin() const 
        {
            return (T*)begin_;
        }

        byte* end() const
        {
            return end_;
        }

        size_t size() const
        {
            return end_ - begin_ + 1;
        }

        
        void set(T* val)
        {
            if (val == nullptr) SOUL_PANIC("ptr_view: val is nullptr");

            begin_ = val;
            end_ = (byte*)(val + 1) - 1;
        }

        void set(T* val, size_t size)
        {
            if (val == nullptr) SOUL_PANIC("ptr_view: val is nullptr");

            begin_ = val;
            end_ = (byte*)val + size - 1;
        }

        void set(T& val)
        {
            begin_ = val;
            end_ = (byte*)(&val + 1) - 1;
        }
    };
}


#endif // SOUL_COLLECTIONS_PTR_VIEW_HPP
