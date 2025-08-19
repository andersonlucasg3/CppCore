#pragma once

#include "NSObject.hpp"
#include "NSObjCRuntime.h"

namespace NS
{
    class Value : public Copying<Value>
    {
    public:
        static Value* value(const void* pValue, const char* pType);
        static Value* value(const void* pPointer);

        static Value* alloc();

        Value*        init(const void* pValue, const char* pType);
        Value*        init(const class Coder* pCoder);

        void          getValue(void* pValue, UInteger size) const;
        const char*   objCType() const;

        bool          isEqualToValue(Value* pValue) const;
        void*         pointerValue() const;
    };

    class Number : public Copying<Number, Value>
    {
    public:
        static Number*     number(char value);
        static Number*     number(unsigned char value);
        static Number*     number(short value);
        static Number*     number(unsigned short value);
        static Number*     number(int value);
        static Number*     number(unsigned int value);
        static Number*     number(long value);
        static Number*     number(unsigned long value);
        static Number*     number(long long value);
        static Number*     number(unsigned long long value);
        static Number*     number(float value);
        static Number*     number(double value);
        static Number*     number(bool value);

        static Number*     alloc();

        Number*            init(const class Coder* pCoder);
        Number*            init(char value);
        Number*            init(unsigned char value);
        Number*            init(short value);
        Number*            init(unsigned short value);
        Number*            init(int value);
        Number*            init(unsigned int value);
        Number*            init(long value);
        Number*            init(unsigned long value);
        Number*            init(long long value);
        Number*            init(unsigned long long value);
        Number*            init(float value);
        Number*            init(double value);
        Number*            init(bool value);

        char               charValue() const;
        unsigned char      unsignedCharValue() const;
        short              shortValue() const;
        unsigned short     unsignedShortValue() const;
        int                intValue() const;
        unsigned int       unsignedIntValue() const;
        long               longValue() const;
        unsigned long      unsignedLongValue() const;
        long long          longLongValue() const;
        unsigned long long unsignedLongLongValue() const;
        float              floatValue() const;
        double             doubleValue() const;
        bool               boolValue() const;
        Integer            integerValue() const;
        UInteger           unsignedIntegerValue() const;
        class String*      stringValue() const;

        ComparisonResult   compare(const Number* pOtherNumber) const;
        bool               isEqualToNumber(const Number* pNumber) const;

        class String*      descriptionWithLocale(const Object* pLocale) const;
    };
}