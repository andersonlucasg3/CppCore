#pragma once

#include "RefCounter.h"

#include <cstddef>
#include <type_traits>

template<typename TPtr>
struct TSharedPtr;

template<typename TPtr>
struct TWeakPtr
{
	inline TWeakPtr() = default;

	inline TWeakPtr(const TWeakPtr& Other) : TWeakPtr()
	{
		if (!Other) return;

		_refCounter = Other._refCounter->RetainWeak();
		_deleter = Other._deleter;
		_object = Other._object;
	}

	template<typename TOtherPtr = TPtr>
	inline TWeakPtr(const TWeakPtr<TOtherPtr>& Weak) : TWeakPtr()
	{
		static_assert(std::is_base_of_v<TPtr, TOtherPtr> || std::is_same_v<TPtr, TOtherPtr>);

		if (!Weak) return;

		_refCounter = Weak._refCounter->RetainWeak();
		_deleter = Weak._deleter;
		_object = Weak._object;
	}

	template<typename TOtherPtr = TPtr>
	inline TWeakPtr(const TSharedPtr<TOtherPtr>& Shared) : TWeakPtr()
	{
		static_assert(std::is_base_of_v<TPtr, TOtherPtr> || std::is_same_v<TPtr, TOtherPtr>);

		if (!Shared) return;

		_refCounter = Shared._refCounter->RetainWeak();
		_deleter = Shared._deleter;
		_object = Shared._object;
	}

	inline TWeakPtr(std::nullptr_t) : TWeakPtr()
	{
		//
	}

	inline ~TWeakPtr()
	{
		Reset();
	}

	inline TPtr* Raw() const
	{
		if (_refCounter == nullptr) return nullptr;
		
		return _object;
	}

	inline UInt32 RefCount() const
	{
		return _refCounter != nullptr ? _refCounter->RefCount() : 0;
	}

	inline bool IsValid() const
	{
		return _refCounter != nullptr && _refCounter->IsValid() && !_refCounter->IsPendingDelete();
	}

	inline operator bool() const
	{
		return IsValid();
	}

	inline explicit operator TPtr*() const
	{
		return _object;
	}

	inline const TPtr& operator*() const
	{
		return *_object;
	}

	inline TPtr& operator*()
	{
		return *_object;
	}

	inline TPtr* operator->() const
	{
		return _object;
	}

	inline TPtr& operator[](UInt32 Index) const
	{
		return _object[Index];
	}

	inline TPtr& operator[](UInt64 Index) const
	{
		return _object[Index];
	}

	inline TPtr* operator+(UInt32 Index) const
	{
		return (_object + Index);
	}

	inline TPtr* operator+(UInt64 Index) const
	{
		return (_object + Index);
	}

	inline bool operator == (std::nullptr_t)
	{
		return _object == nullptr;
	}

	inline TWeakPtr& operator=(const TWeakPtr& Other)
	{
		Reset();

		if (!Other) return *this;

		_refCounter = Other._refCounter->RetainWeak();
		_object = Other._object;
		_deleter = Other._deleter;

		return *this;
	}

	template<typename TOtherPtr = TPtr>
	inline TWeakPtr& operator=(const TWeakPtr<TOtherPtr>& Weak)
	{
		static_assert(std::is_convertible_v<TOtherPtr*, TPtr*> || std::is_same_v<TPtr, TOtherPtr>);

		Reset();

		if (!Weak) return *this;

		_refCounter = Weak._refCounter->RetainWeak();
		_object = Weak._object;
		_deleter = Weak._deleter;

		return *this;
	}

	template<typename TOtherPtr = TPtr>
	inline TWeakPtr& operator=(const TSharedPtr<TOtherPtr>& Shared)
	{
		static_assert(std::is_convertible_v<TOtherPtr*, TPtr*> || std::is_same_v<TPtr, TOtherPtr>);

		Reset();

		if (!Shared) return *this;

		_refCounter = Shared._refCounter->RetainWeak();
		_object = Shared._object;
		_deleter = Shared._deleter;

		return *this;
	}

	inline TWeakPtr& operator=(std::nullptr_t)
	{
		Reset();

		return *this;
	}

private:
	TPtr* _object = nullptr;
	IDeleter* _deleter = nullptr;
	SRefCounter* _refCounter = nullptr;

	inline TWeakPtr(TPtr* InObject, IDeleter* InDeleter, SRefCounter* InRefCounter) : 
		_object(InObject),
		_deleter(InDeleter),
		_refCounter(InRefCounter->RetainWeak())
	{
		//
	}

	inline void Reset()
	{
		if (_refCounter == nullptr) return;

		_refCounter->ReleaseWeak();

		if (_refCounter->IsPendingDelete())
		{
			delete _refCounter;
		}

		_object = nullptr;
		_deleter = nullptr;
		_refCounter = nullptr;
	}

	friend struct TWeakPtr;
    template<typename TOtherPtr>
    friend struct TWeakPtr;
	friend struct TSharedPtr<TPtr>;

	template<typename TPointer>
	friend struct TSharedFromThis;

	template<
        typename TCastTo,
        typename TCastFrom
    >
    friend TWeakPtr<TCastTo> StaticCastWeakPtr(const TWeakPtr<TCastFrom>& Cast);
};