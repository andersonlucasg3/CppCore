#pragma once

#include "LinkedList.h"

template<typename TElement>
class TQueue : private TLinkedList<TElement>
{
	using Super = TLinkedList<TElement>;

public:
	TQueue() : Super()
	{
		
	}

	TQueue(const TElement& Element) : 
		Super(Element)
	{
		
	}

	~TQueue() override = default;

	UInt32 Num() override
	{
		return Super::Num();
	}

	void Enqueue(const TElement& Element)
	{
		Super::Add(Element);
	}

	bool Dequeue(TElement& OutElement)
	{
		// Empty queue
		if (IsEmpty()) return false;

		// One element queue
		if (Num() == 1)
		{
			OutElement = Super::First();

			Super::RemoveFirst();

			return true;
		}

		// More than one element
		OutElement = Super::First();
		
		Super::RemoveFirst();

		return true;
	}

	bool Peak(TElement& OutElement)
	{
		if (!IsEmpty())
		{
			OutElement = Super::First();
			
			return true;
		}

		return false;
	}

	bool Contains(const TElement& Element)
	{
		return Super::Contains(Element);
	}

	bool IsEmpty()
	{
		return Super::IsEmpty();
	}
};