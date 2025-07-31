#pragma once

#include <cstddef>
#include <type_traits>

namespace Core::Types
{
	using SInt8 		= signed char;
	using SInt16 		= signed short;
	using SInt32 		= signed int;
	using SInt64 		= signed long long;

	using UInt8 		= unsigned char;
	using UInt16 		= unsigned short;
	using UInt32 		= unsigned int;
	using UInt64 		= unsigned long long;

	using SSizeT 		= UInt64;

	using SByte 		= SInt8; // signed byte
	using UByte			= UInt8; // unsigned byte

	using SFloat 		= float;
	using SDouble		= double;
}
