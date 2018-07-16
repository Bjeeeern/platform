#if !defined(INTRINSICS_H)

#include "platform.h"

//
// NOTE(bjorn): Compilers.
//

#if !defined COMPILER_MSVC
#define COMPILER_MSVC 0
#endif

#if !defined COMPILER_LLVM
#define COMPILER_LLVM 0
#endif

#if !COMPILER_MSVC && !COMPILER_LLVM

#if _MSC_VER
#undef COMPILER_MSVC
#define COMPILER_MSVC 1
#else
//TODO(bjorn): Moar compilerz!!
#undef COMPILER_LLVM
#define COMPILER_LLVM 1
#endif

#endif

#if COMPILER_MSVC
#include <intrin.h>
#endif

inline u8 
EndianSwap(u8 Endian)
{
	return Endian;
}
inline s8 
EndianSwap(s8 Endian)
{
	return Endian;
}
inline u16 
EndianSwap(u16 Endian)
{
	return (((Endian & 0x00FF) << 8) | 
					((Endian & 0xFF00) >> 8));
}
inline s16 
EndianSwap(s16 Endian)
{
	return (s16)EndianSwap((u16)Endian);
}
inline u32 
EndianSwap(u32 Endian)
{
	return (((Endian & 0x000000FF) << 24) | 
					((Endian & 0x0000FF00) << 8) |
					((Endian & 0x00FF0000) >> 8) |
					((Endian & 0xFF000000) >> 24));
}
inline s32 
EndianSwap(s32 Endian)
{
	return (s32)EndianSwap((u32)Endian);
}
inline u64
EndianSwap(u64 Endian)
{
	return (((Endian & 0x00000000000000FF) << 56) | 
					((Endian & 0x000000000000FF00) << 40) | 
					((Endian & 0x0000000000FF0000) << 24) | 
					((Endian & 0x00000000FF000000) << 8) |
					((Endian & 0x000000FF00000000) >> 8) |
					((Endian & 0x0000FF0000000000) >> 24) |
					((Endian & 0x00FF000000000000) >> 40) |
					((Endian & 0xFF00000000000000) >> 56));
}
inline s64
EndianSwap(s64 Endian)
{
	return (s64)EndianSwap((u64)Endian);
}

  inline s32
RoundF32ToS32(f32 Number)
{
  return Number >= 0.0f ? (s32)(Number + 0.5f) : (s32)(Number - 0.5f);
}
  inline s32
FloorF32ToS32(f32 Number)
{
  if(Number < 0)
  {
    Number -= 1.0f;
  }
  return (s32)(Number);
}
  inline s32
TruncateF32ToS32(f32 Number)
{
  return (s32)(Number);
}

internal_function u32
SafeTruncateU64(u64 Value)
{
  // TODO(bjorn): Defines for maximum values u32MAX etc.
  Assert(Value <= 0xFFFFFFFF);
  return (u32)Value;
}

// TODO(bjorn): Implement sine on my own.

//NOTE(bjorn): The quake fast inverse sqare.
	inline f32
InverseSquareRoot(f32 Number)
{
	s32 i;
	f32 x2, y;
	f32 ThreeHalfs = 1.5f;

	x2 = Number * 0.5f;
	y  = Number;

	i  = *(s32*)&y;                       // evil floating point bit level hacking
	i  = 0x5F375A86 - (i>>1);               // what the fuck? 
	y  = *(f32*)&i;

	y  = y * (ThreeHalfs - (x2 * y*y));   // 1st iteration
	y  = y * (ThreeHalfs - (x2 * y*y));   // 2nd iteration, this can be removed

	return y;
}
	inline f32
SquareRoot(f32 Number)
{
	return InverseSquareRoot(Number) * Number;
}

inline v3
Normalize(v3 D)
{
  return D * InverseSquareRoot(D.X*D.X + D.Y*D.Y + D.Z*D.Z);
}

inline f32
Absolute(f32 Number)
{
	if(Number < 0.0f)
	{
		return Number * -1.0f;
	}
	else
	{
		return Number;
	}
}

	inline s32
Sign(s32 Number)
{
	if(Number == 0)
	{
		return 0;
	}
	if(Number > 0)
	{
		return 1;
	}
	return -1;
}

	inline f32
Lerp(f32 Scale, f32 Zero, f32 One)
{
	return One * Scale + Zero * (1.0f - Scale);
}

inline f32
Distance(v2 A, v2 B)
{
	v2 D = A - B;
	return SquareRoot(D.X*D.X + D.Y*D.Y);
}

inline f32
Distance(v3 A, v3 B)
{
	v3 D = A - B;
	return SquareRoot(D.X*D.X + D.Y*D.Y + D.Z*D.Z);
}

#define INTRINSICS_H
#endif
