#pragma once

#include "Defines/Types.h"
#include "Templates/Functions.h"

using namespace Core::Types;

template<typename TValue>
struct TNode
{
	TValue Value {};

	TNode<TValue>* Previous = nullptr;
	TNode<TValue>* Next = nullptr;

	TNode(const TValue& Value) :
		Value(Value)
	{
	}
};

template<typename TElement>
class TLinkedList
{
public:
    using TNodeElement = TNode<TElement>;
	using TNodePtr = TNodeElement*;

private:
    TNodePtr _head = nullptr;
	TNodePtr _tail = nullptr;
	UInt32 _currentNum = 0;

public:
	TLinkedList()
    {
        _head = nullptr;
		_tail = nullptr;
    }

    TLinkedList(const TElement& Element)
    {
        Add(Element);
    }

    TLinkedList(const TLinkedList& Other) :
        TLinkedList()
    {
        Other.ForEach([this](const TElement& Each)
        {
            Add(Each);
        });
    }

    virtual ~TLinkedList()
    {
        RemoveAll();
    }

    virtual UInt32 Num()
    {
        return _currentNum;
    }

    TNodePtr Head()
    {
        return _head;
    }

    TNodePtr Tail()
    {
        return _tail;
    }

    TElement& First()
    {
        return _head->Value;
    }

    TElement& Last()
    {
        return _tail->Value;
    }

    TNodePtr Add(const TElement& Element)
    {
        ++_currentNum;

		TNodePtr NewTailPtr = new TNodeElement(Element);

		if (_head == nullptr)
		{
			_head = NewTailPtr;
			_tail = NewTailPtr;

            return NewTailPtr;
		}

        NewTailPtr->Previous = _tail;
        _tail->Next = NewTailPtr;
        _tail = NewTailPtr;

        return NewTailPtr;
    }

    bool Remove(TNodePtr NodePtr)
    {
        if (IsEmpty() || NodePtr == nullptr) return false;
        
        --_currentNum;

        TNodePtr Next = NodePtr->Next;
        TNodePtr Previous = NodePtr->Previous;

        if (NodePtr == _head)
        {
            if (_head == _tail)
            {
                _head = _tail = nullptr;
            }
            else 
            {
                _head = Next;
            }
        }

        if (NodePtr == _tail)
        {
            if (_head == _tail)
            {
                _head = _tail = nullptr;
            }
            else
            {
                _tail = Previous;
            }
        }

        if (Previous != nullptr)
        {
            Previous->Next = Next;
        }

        if (Next != nullptr)
        {
            Next->Previous = Previous;
        }

        delete NodePtr;

        return true;
    }

    bool RemoveFirst()
    {
        return Remove(_head);
    }

    bool RemoveLast()
    {
        return Remove(_tail);
    }

    void Remove(const TElement& Element)
	{
		TNodePtr Current = _head;
		while (Current != nullptr)
		{
			if (Current->Value == Element)
			{
				Remove(Current);

				return;
			}

			Current = Current->Next;
		}
	}

    void RemoveAll()
    {
        while (RemoveFirst());
    }

    bool Contains(const TElement& Element)
    {
        TNodePtr Current = _head;
		while (Current != nullptr)
		{
			if (Current->Value == Element)
			{
				return true;
			}

			Current = Current->Next;
		}

		return false;
    }

    bool IsEmpty()
	{
		return _head == nullptr;
	}
    
    void ForEach(const TFunction<void(const TElement&)>& EachFunc) const
    {
        TNodePtr Current = _head;
		while (Current != nullptr)
		{
			EachFunc(Current->Value);

			Current = Current->Next;
		}
    }

    void ForEach(const TFunction<void(TElement&)>& EachFunc)
    {
        TNodePtr Current = _head;
		while (Current != nullptr)
		{
			EachFunc(Current->Value);

			Current = Current->Next;
		}
    }

    TLinkedList& operator=(const TLinkedList& Other)
    {
        Other.ForEach([this](const TElement& Each)
        {
            Add(Each);
        });
        return *this;
    }
};
