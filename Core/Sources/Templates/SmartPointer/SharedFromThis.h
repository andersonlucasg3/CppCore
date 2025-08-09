#pragma once

#include "Defines/Asserts.h"
#include "Logger/Logger.h"

struct IDeleter;
struct SRefCounter;

struct SSharedFromThis
{
	virtual ~SSharedFromThis() = default;
};

template<typename TPtr>
struct TWeakPtr;

template<typename TPtr>
struct TSharedPtr;

template<typename TThis>
struct TSharedFromThis : public SSharedFromThis
{
	TSharedFromThis() = default;
	~TSharedFromThis() override = default;

	template<typename TOtherPtr = TThis>
	TSharedPtr<TOtherPtr> AsShared()
	{
		assert(_deleter && _refCounter);

		return TSharedPtr<TOtherPtr>(static_cast<TOtherPtr*>(this), _deleter, _refCounter);
	}

	template<typename TOtherPtr = TThis>
	TWeakPtr<TOtherPtr> AsWeak()
	{
		assert(_deleter && _refCounter);

		return TWeakPtr<TOtherPtr>(static_cast<TOtherPtr*>(this), _deleter, _refCounter);
	}

protected:
	virtual void OnInitializeShared() { }

private:
	IDeleter* _deleter = nullptr;
	SRefCounter* _refCounter = nullptr;

	void UpdateWeakPtr(IDeleter* InDeleter, SRefCounter* InRefCounter)
	{
		_deleter = InDeleter;
		_refCounter = InRefCounter;

		OnInitializeShared();
	}

	template<typename TPointer>
	friend struct TWeakPtr;

	template<typename TPointer>
	friend struct TSharedPtr;

	template<typename TPointer, typename ... TArgs>
	friend TSharedPtr<TPointer> MakeShared(TArgs...);

	template<typename TPointer, typename DeleterT>
	friend TSharedPtr<TPointer> MakeShareable(TPointer*);
};