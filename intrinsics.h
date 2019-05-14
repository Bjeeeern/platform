#if !defined(INTRINSICS_H)

#include "platform.h"

#if COMPILER_MSVC
#include <intrin.h>
#include <float.h>
#endif

inline void
ActivateSignalingNaNs()
{
#if COMPILER_MSVC
	u32 CurrentWord = 0;
	_controlfp_s(&CurrentWord, _EM_INVALID, _MCW_EM);
#endif
}

inline u32
RotateLeft(u32 Value, s32 Steps)
{
#if COMPILER_MSVC
	return _rotl(Value, Steps);
#else
	return (Steps > 0) ? (Value << Steps) : (Value >> -Steps);
#endif
}

inline u32
RotateRight(u32 Value, s32 Steps)
{
#if COMPILER_MSVC
	return _rotr(Value, Steps);
#else
	return (Steps > 0) ? (Value >> Steps) : (Value << -Steps);
#endif
}

struct bit_scan_result
{
	b32 Found;
	s32 Index;
};

inline bit_scan_result
FindLeastSignificantSetBit(u32 Value)
{
	bit_scan_result Result = {};

#if COMPILER_MSVC
	Result.Found = _BitScanForward((unsigned long*)(&Result.Index), Value);
#else
	for(s32 Test = 0;
			Test < 32;
			Test++)
	{
		if(Value & (1 << Test))
		{
			Result.Index = Test;
			Result.Found = true;
			break;
		}
	}
#endif

	return Result;
}

#define INTRINSICS_H
#endif
