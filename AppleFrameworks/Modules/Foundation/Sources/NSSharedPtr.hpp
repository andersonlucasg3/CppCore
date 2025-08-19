#pragma once

#include "NSDefines.h"

#include <type_traits>
#include <cstddef>

namespace NS
{
    template <class _Class>
    class SharedPtr
    {
    public:
        /**
        * Create a new null pointer.
        */
        SharedPtr();

        /**
        * Destroy this SharedPtr, decreasing the reference count.
        */
        ~SharedPtr();

        /**
        * Create a new null pointer.
        */
        SharedPtr(std::nullptr_t) noexcept;

        /**
        * SharedPtr copy constructor.
        */
        SharedPtr(const SharedPtr<_Class>& other) noexcept;

        /**
        * Construction from another pointee type.
        */
        template <class _OtherClass>
        SharedPtr(const SharedPtr<_OtherClass>& other, typename std::enable_if_t<std::is_convertible_v<_OtherClass *, _Class *>> * = nullptr) noexcept;

        /**
        * SharedPtr move constructor.
        */
        SharedPtr(SharedPtr<_Class>&& other) noexcept;

        /**
        * Move from another pointee type.
        */
        template <class _OtherClass>
        SharedPtr(SharedPtr<_OtherClass>&& other, typename std::enable_if_t<std::is_convertible_v<_OtherClass *, _Class *>> * = nullptr) noexcept;

        /**
        * Copy assignment operator.
        * Copying increases reference count. Only releases previous pointee if objects are different.
        */
        SharedPtr& operator=(const SharedPtr<_Class>& other);

        /**
        * Copy-assignment from different pointee.
        * Copying increases reference count. Only releases previous pointee if objects are different.
        */
        template <class _OtherClass>
        typename std::enable_if_t<std::is_convertible_v<_OtherClass *, _Class *>, SharedPtr &>
        operator=(const SharedPtr<_OtherClass>& other);

        /**
        * Move assignment operator.
        * Move without affecting reference counts, unless pointees are equal. Moved-from object is reset to nullptr.
        */
        SharedPtr& operator=(SharedPtr<_Class>&& other);

        /**
        * Move-asignment from different pointee.
        * Move without affecting reference counts, unless pointees are equal. Moved-from object is reset to nullptr.
        */
        template <class _OtherClass>
        typename std::enable_if_t<std::is_convertible_v<_OtherClass *, _Class *>, SharedPtr &>
        operator=(SharedPtr<_OtherClass>&& other);

        /**
        * Access raw pointee.
        * @warning Avoid wrapping the returned value again, as it may lead double frees unless this object becomes detached.
        */
        _Class* get() const;

        /**
        * Call operations directly on the pointee.
        */
        _Class* operator->() const;

        /**
        * Implicit cast to bool.
        */
        explicit operator bool() const;

        /**
        * Reset this SharedPtr to null, decreasing the reference count.
        */
        void reset();

        /**
        * Detach the SharedPtr from the pointee, without decreasing the reference count.
        */
        void detach();

        template <class _OtherClass>
        friend SharedPtr<_OtherClass> RetainPtr(_OtherClass* ptr);

        template <class _OtherClass>
        friend SharedPtr<_OtherClass> TransferPtr(_OtherClass* ptr);

    private:
        _Class* m_pObject;
    };

    /**
    * Create a SharedPtr by retaining an existing raw pointer.
    * Increases the reference count of the passed-in object.
    * If the passed-in object was in an AutoreleasePool, it will be removed from it.
    */
    template <class _Class>
    _NS_INLINE SharedPtr<_Class> RetainPtr(_Class* pObject)
    {
        SharedPtr<_Class> ret;
        ret.m_pObject = pObject->retain();
        return ret;
    }

    /*
    * Create a SharedPtr by transfering the ownership of an existing raw pointer to SharedPtr.
    * Does not increase the reference count of the passed-in pointer, it is assumed to be >= 1.
    * This method does not remove objects from an AutoreleasePool.
    */
    template <class _Class>
    _NS_INLINE SharedPtr<_Class> TransferPtr(_Class* pObject)
    {
        SharedPtr<_Class> ret;
        ret.m_pObject = pObject;
        return ret;
    }

    template <class _Class>
    _NS_INLINE SharedPtr<_Class>::SharedPtr()
        : m_pObject(nullptr)
    {
    }
    
    template <class _Class>
    _NS_INLINE SharedPtr<_Class>::~SharedPtr<_Class>() __attribute__((no_sanitize("undefined")))
    {
        m_pObject->release();
    }
    
    template <class _Class>
    _NS_INLINE SharedPtr<_Class>::SharedPtr(std::nullptr_t) noexcept
        : m_pObject(nullptr)
    {
    }
    
    template <class _Class>
    _NS_INLINE SharedPtr<_Class>::SharedPtr(const SharedPtr<_Class>& other) noexcept
        : m_pObject(other.m_pObject->retain())
    {
    }
    
    template <class _Class>
    template <class _OtherClass>
    _NS_INLINE SharedPtr<_Class>::SharedPtr(const SharedPtr<_OtherClass>& other, typename std::enable_if_t<std::is_convertible_v<_OtherClass *, _Class *>> *) noexcept
        : m_pObject(reinterpret_cast<_Class*>(other.get()->retain()))
    {
    }
    
    template <class _Class>
    _NS_INLINE SharedPtr<_Class>::SharedPtr(SharedPtr<_Class>&& other) noexcept
        : m_pObject(other.m_pObject)
    {
        other.m_pObject = nullptr;
    }
    
    template <class _Class>
    template <class _OtherClass>
    _NS_INLINE SharedPtr<_Class>::SharedPtr(SharedPtr<_OtherClass>&& other, typename std::enable_if_t<std::is_convertible_v<_OtherClass *, _Class *>> *) noexcept
        : m_pObject(reinterpret_cast<_Class*>(other.get()))
    {
        other.detach();
    }
    
    template <class _Class>
    _NS_INLINE _Class* SharedPtr<_Class>::get() const
    {
        return m_pObject;
    }
    
    template <class _Class>
    _NS_INLINE _Class* SharedPtr<_Class>::operator->() const
    {
        return m_pObject;
    }
    
    template <class _Class>
    _NS_INLINE SharedPtr<_Class>::operator bool() const
    {
        return nullptr != m_pObject;
    }
    
    template <class _Class>
    _NS_INLINE void SharedPtr<_Class>::reset() __attribute__((no_sanitize("undefined")))
    {
        m_pObject->release();
        m_pObject = nullptr;
    }
    
    template <class _Class>
    _NS_INLINE void SharedPtr<_Class>::detach()
    {
        m_pObject = nullptr;
    }
    
    template <class _Class>
    _NS_INLINE SharedPtr<_Class>& SharedPtr<_Class>::operator=(const SharedPtr<_Class>& other) __attribute__((no_sanitize("undefined")))
    {
        _Class* pOldObject = m_pObject;
    
        m_pObject = other.m_pObject->retain();
    
        pOldObject->release();
    
        return *this;
    }
    
    template <class _Class>
    template <class _OtherClass>
    typename std::enable_if_t<std::is_convertible_v<_OtherClass *, _Class *>, SharedPtr<_Class> &>
    _NS_INLINE SharedPtr<_Class>::operator=(const SharedPtr<_OtherClass>& other) __attribute__((no_sanitize("undefined")))
    {
        _Class* pOldObject = m_pObject;
    
        m_pObject = reinterpret_cast<_Class*>(other.get()->retain());
    
        pOldObject->release();
    
        return *this;
    }
    
    template <class _Class>
    _NS_INLINE SharedPtr<_Class>& SharedPtr<_Class>::operator=(SharedPtr<_Class>&& other) __attribute__((no_sanitize("undefined")))
    {
        if (m_pObject != other.m_pObject)
        {
            m_pObject->release();
            m_pObject = other.m_pObject;
        }
        else
        {
            m_pObject = other.m_pObject;
            other.m_pObject->release();
        }
        other.m_pObject = nullptr;
        return *this;
    }
    
    template <class _Class>
    template <class _OtherClass>
    typename std::enable_if_t<std::is_convertible_v<_OtherClass *, _Class *>, SharedPtr<_Class> &>
    _NS_INLINE SharedPtr<_Class>::operator=(SharedPtr<_OtherClass>&& other) __attribute__((no_sanitize("undefined")))
    {
        if (m_pObject != other.get())
        {
            m_pObject->release();
            m_pObject = reinterpret_cast<_Class*>(other.get());
            other.detach();
        }
        else
        {
            m_pObject = other.get();
            other.reset();
        }
        return *this;
    }
    
    template <class _ClassLhs, class _ClassRhs>
    _NS_INLINE bool operator==(const SharedPtr<_ClassLhs>& lhs, const SharedPtr<_ClassRhs>& rhs)
    {
        return lhs.get() == rhs.get();
    }
    
    template <class _ClassLhs, class _ClassRhs>
    _NS_INLINE bool operator!=(const SharedPtr<_ClassLhs>& lhs, const SharedPtr<_ClassRhs>& rhs)
    {
        return lhs.get() != rhs.get();
    }
}