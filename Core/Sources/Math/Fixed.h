#pragma once

#include "CoreDefinitions.h"

#include "Templates/Strings.h"

#define DECLARE_FIXED_OPERATOR(OP, T, V) \
constexpr TFixed operator OP(T Value) const { TFixed Copy = *this; Copy.Value OP##= V; return Copy; }

#define DECLARE_FIXED_OPERATOR_PRIMITIVES(OP, V) \
DECLARE_FIXED_OPERATOR(OP, SInt32, V); \
DECLARE_FIXED_OPERATOR(OP, SInt64, V); \
DECLARE_FIXED_OPERATOR(OP, SDouble, V);

#define DECLARE_FIXED_OPERATOR_REF(OP, T, V) \
constexpr TFixed& operator OP(T Value) { this->Value OP V; return *this; }

#define DECLARE_FIXED_OPERATOR_REF_PRIMITIVES(OP, V) \
DECLARE_FIXED_OPERATOR_REF(OP, SInt32, V); \
DECLARE_FIXED_OPERATOR_REF(OP, SInt64, V); \
DECLARE_FIXED_OPERATOR_REF(OP, SDouble, V);

#define DECLARE_FIXED_ARITHMETIC_OPERATOR(OP, T, V)	\
constexpr TFixed operator OP(T Value, const TFixed& Fixed) { return Fixed OP V; }

// don't need to scale here
#define DECLARE_FIXED_ARITHMETIC_OPERATOR_PRIMITIVES(OP) \
DECLARE_FIXED_ARITHMETIC_OPERATOR(OP, SInt32, Value); \
DECLARE_FIXED_ARITHMETIC_OPERATOR(OP, SInt64, Value); \
DECLARE_FIXED_ARITHMETIC_OPERATOR(OP, SDouble, Value);

#define DECLARE_FIXED_COMPARISON_OPERATOR(OP, T, V) \
constexpr bool operator OP(T Value) const { return this->Value OP V; }

#define DECLARE_FIXED_COMPARISON_OPERATORS(OP) \
DECLARE_FIXED_COMPARISON_OPERATOR(OP, const TFixed&, Value.Value); \
DECLARE_FIXED_COMPARISON_OPERATOR(OP, SInt32, Scaled(Value)); \
DECLARE_FIXED_COMPARISON_OPERATOR(OP, SInt64, Scaled(Value)); \
DECLARE_FIXED_COMPARISON_OPERATOR(OP, SDouble, Scaled(Value));

#define DECLARE_FIXED_SCALED_FUNC(T) \
static SInt64 Scaled(T Value) { return static_cast<SInt64>(Value * Precision); }

#define DECLARE_FIXED_DESCALE_FUNC(T, R) \
static R Descale(T Value) { return static_cast<R>(Value) / static_cast<R>(Precision); }

namespace Core::Maths
{
    using namespace Types;

	template<SInt64 P>
    struct TFixed
	{
		constexpr static SInt64 Precision = P;

		constexpr TFixed() = default;

		constexpr TFixed(SInt32 Value) : Value(Scaled(Value))
		{
			//
		}
		
		constexpr TFixed(SInt64 Value) : Value(Scaled(Value))
		{
			//
		}

		constexpr TFixed(SDouble Value) : Value(Scaled(Value))
		{
			//
		}

		constexpr SFloat AsFloat() const
		{
			return static_cast<SFloat>(Descale(Value));
		}

		constexpr operator SDouble() const
		{
			return Descale(Value);
		}

		constexpr SInt64 operator *() const
		{
			return Value;
		}

		constexpr TFixed operator-() const
		{
			TFixed Negated;
			Negated.Value = -Value;
			return Negated;
		}

		constexpr TFixed& operator =(SInt32 NewValue)
		{
			Value = Scaled(NewValue);
			return *this;
		}

		constexpr TFixed& operator =(SInt64 NewValue)
		{
			Value = Scaled(NewValue);
			return *this;
		}

		constexpr TFixed& operator =(SDouble NewValue)
		{
			Value = Scaled(NewValue);
			return *this;
		}

		constexpr TFixed operator+(const TFixed &Value) const 
		{
			TFixed Copy = *this;
			Copy.Value += Value.Value;
			return Copy;
		}
		
		constexpr TFixed operator+(SInt32 Value) const 
		{
			TFixed Copy = *this;
			Copy.Value += Scaled(Value);
			return Copy;
		}
		
		constexpr TFixed operator+(SInt64 Value) const 
		{
			TFixed Copy = *this;
			Copy.Value += Scaled(Value);
			return Copy;
		}
		
		constexpr TFixed operator+(SDouble Value) const 
		{
			TFixed Copy = *this;
			Copy.Value += Scaled(Value);
			return Copy;
		}

		constexpr TFixed operator-(const TFixed &Value) const 
		{
			TFixed Copy = *this;
			Copy.Value -= Value.Value;
			return Copy;
		}

		constexpr TFixed operator-(SInt32 Value) const 
		{
			TFixed Copy = *this;
			Copy.Value -= Scaled(Value);
			return Copy;
		}

		constexpr TFixed operator-(SInt64 Value) const 
		{
			TFixed Copy = *this;
			Copy.Value -= Scaled(Value);
			return Copy;
		}

		constexpr TFixed operator-(SDouble Value) const 
		{
			TFixed Copy = *this;
			Copy.Value -= Scaled(Value);
			return Copy;
		}

		constexpr TFixed operator*(const TFixed &Other) const 
		{
			TFixed Copy = *this;
			Copy.Value = static_cast<SInt64>(static_cast<SDouble>(Copy.Value) * Descale(Other.Value));
			return Copy;
		}

		constexpr TFixed operator*(SInt32 Value) const
        {
			TFixed Copy = *this;
			Copy.Value *= Value;
			return Copy;
		}
		
		constexpr TFixed operator*(SInt64 Value) const 
		{
			TFixed Copy = *this;
			Copy.Value *= Value;
			return Copy;
		}
		
		constexpr TFixed operator*(SDouble Value) const 
		{
			TFixed Copy = *this;
			Copy.Value = static_cast<SInt64>(static_cast<SDouble>(Copy.Value) * Value);
			return Copy;
		}

		constexpr TFixed operator/(const TFixed& Other) const 
		{
			TFixed Copy = *this;
			Copy.Value = static_cast<SInt64>(static_cast<SDouble>(Copy.Value) / Descale(Other.Value));
			return Copy;
		}

		constexpr TFixed operator/(SInt32 Value) const 
		{
			TFixed Copy = *this;
			Copy.Value /= Value;
			return Copy;
		}

		constexpr TFixed operator/(SInt64 Value) const 
		{
			TFixed Copy = *this;
			Copy.Value /= Value;
			return Copy;
		}

		constexpr TFixed operator/(SDouble Value) const 
		{
			TFixed Copy = *this;
			Copy.Value = static_cast<SInt64>(static_cast<SDouble>(Copy.Value) / Value);
			return Copy;
		}

		constexpr TFixed &operator+=(const TFixed &Value) 
		{
			this->Value += Value.Value;
			return *this;
		}

		constexpr TFixed &operator+=(SInt32 Value) 
		{
			this->Value += Scaled(Value);
			return *this;
		}
		
		constexpr TFixed &operator+=(SInt64 Value) 
		{
			this->Value += Scaled(Value);
			return *this;
		}
		
		constexpr TFixed &operator+=(SDouble Value) 
		{
			this->Value += Scaled(Value);
			return *this;
		}

		constexpr TFixed &operator-=(const TFixed &Value)
        {
			this->Value -= Value.Value;
			return *this;
		}

		constexpr TFixed &operator-=(SInt32 Value) 
		{
			this->Value -= Scaled(Value);
			return *this;
		}
		
		constexpr TFixed &operator-=(SInt64 Value) 
		{
			this->Value -= Scaled(Value);
			return *this;
		}

		constexpr TFixed &operator-=(SDouble Value) 
		{
			this->Value -= Scaled(Value);
			return *this;
		}

		constexpr TFixed &operator*=(const TFixed &Value) 
		{
			this->Value *= Descale(Value.Value);
			return *this;
		}

		constexpr TFixed &operator*=(SInt32 Value) 
		{
			this->Value *= Value;
			return *this;
		}

		constexpr TFixed &operator*=(SInt64 Value) 
		{
			this->Value *= Value;
			return *this;
		}

		constexpr TFixed &operator*=(SDouble Value) 
		{
			this->Value *= Value;
			return *this;
		}

		constexpr TFixed &operator/=(const TFixed &Value) 
		{
			this->Value /= Descale(Value.Value);
			return *this;
		}

		constexpr TFixed &operator/=(SInt32 Value) 
		{
			this->Value /= Value;
			return *this;
		}

		constexpr TFixed &operator/=(SInt64 Value) 
		{
			this->Value /= Value;
			return *this;
		}

		constexpr TFixed &operator/=(SDouble Value) 
		{
			this->Value /= Value;
			return *this;
		}

		constexpr bool operator>(const TFixed &Value) const 
		{
			return this->Value > Value.Value;
		}

		constexpr bool operator>(SInt32 Value) const 
		{
			return this->Value > Scaled(Value);
		}

		constexpr bool operator>(SInt64 Value) const 
		{
			return this->Value > Scaled(Value);
		}

		constexpr bool operator>(SDouble Value) const 
		{
			return this->Value > Scaled(Value);
		}

		constexpr bool operator>=(const TFixed &Value) const 
		{
			return this->Value >= Value.Value;
		}

		constexpr bool operator>=(SInt32 Value) const 
		{
			return this->Value >= Scaled(Value);
		}

		constexpr bool operator>=(SInt64 Value) const 
		{
			return this->Value >= Scaled(Value);
		}

		constexpr bool operator>=(SDouble Value) const 
		{
			return this->Value >= Scaled(Value);
		}

		constexpr bool operator<(const TFixed &Value) const
        {
			return this->Value < Value.Value;
		}
		
		constexpr bool operator<(SInt32 Value) const
        {
			return this->Value < Scaled(Value);
		}
		
		constexpr bool operator<(SInt64 Value) const
        {
			return this->Value < Scaled(Value);
		}

		constexpr bool operator<(SDouble Value) const
        {
			return this->Value < Scaled(Value);
		}

		constexpr bool operator<=(const TFixed &Value) const
        {
			return this->Value <= Value.Value;
		}

		constexpr bool operator<=(SInt32 Value) const
        {
			return this->Value <= Scaled(Value);
		}

		constexpr bool operator<=(SInt64 Value) const
        {
			return this->Value <= Scaled(Value);
		}

		constexpr bool operator<=(SDouble Value) const
        {
			return this->Value <= Scaled(Value);
		}

		constexpr bool operator==(const TFixed &Value) const 
		{
			return this->Value == Value.Value;
		}

		constexpr bool operator==(SInt32 Value) const 
		{
			return this->Value == Scaled(Value);
		}

		constexpr bool operator==(SInt64 Value) const 
		{
			return this->Value == Scaled(Value);
		}

		constexpr bool operator==(SDouble Value) const 
		{
			return this->Value == Scaled(Value);
		}

		constexpr bool operator!=(const TFixed &Value) const
		{
			return this->Value != Value.Value;
		}

		constexpr bool operator!=(SInt32 Value) const 
		{
			return this->Value != Scaled(Value);
		}

		constexpr bool operator!=(SInt64 Value) const 
		{
			return this->Value != Scaled(Value);
		}

		constexpr bool operator!=(SDouble Value) const 
		{
			return this->Value != Scaled(Value);
		}

		static SInt64 Scaled(SInt32 Value) 
		{
			return static_cast<SInt64>(Value * Precision);
		}

		static SInt64 Scaled(SInt64 Value) 
		{
			return static_cast<SInt64>(Value * Precision);
		}

		static SInt64 Scaled(SDouble Value) 
		{
			return static_cast<SInt64>(Value * Precision);
		}

		static SDouble Descale(SInt64 Value) 
		{
			return static_cast<SDouble>(Value) / static_cast<SDouble>(Precision);
		};

		CString ToString() const
		{
			return CString("(d:{}, f:{:.6f})", Value, Descale(Value));
		}

	private:
		SInt64 Value = 0;
	};

	typedef TFixed<1000000000L> SFixed;

	constexpr SFixed operator+(SInt32 Value, const SFixed &Fixed) 
	{
		return Fixed + Value;
	}

	constexpr SFixed operator+(SInt64 Value, const SFixed &Fixed) 
	{
		return Fixed + Value;
	}
	
	constexpr SFixed operator+(SDouble Value, const SFixed &Fixed) 
	{
		return Fixed + Value;
	}

	constexpr SFixed operator-(SInt32 Value, const SFixed &Fixed) 
	{
		return Fixed - Value;
	}

	constexpr SFixed operator-(SInt64 Value, const SFixed &Fixed) 
	{
		return Fixed - Value;
	}

	constexpr SFixed operator-(SDouble Value, const SFixed &Fixed) 
	{
		return Fixed - Value;
	}

	constexpr SFixed operator*(SInt32 Value, const SFixed &Fixed) 
	{
		return Fixed * Value;
	}

	constexpr SFixed operator*(SInt64 Value, const SFixed &Fixed) 
	{
		return Fixed * Value;
	}
	
	constexpr SFixed operator*(SDouble Value, const SFixed &Fixed) 
	{
		return Fixed * Value;
	}

	constexpr SFixed operator/(SInt32 Value, const SFixed &Fixed) 
	{
		return Fixed / Value;
	}

	constexpr SFixed operator/(SInt64 Value, const SFixed &Fixed) 
	{
		return Fixed / Value;
	}

	constexpr SFixed operator/(SDouble Value, const SFixed &Fixed) 
	{
		return Fixed / Value;
	}
}
