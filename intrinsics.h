#if !defined(INTRINSICS_H)

#include "platform.h"

#if COMPILER_MSVC
#include <intrin.h>
#endif

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
