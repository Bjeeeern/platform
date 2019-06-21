#if !defined(INTRINSICS_H)

#if COMPILER_MSVC
#include <immintrin.h>
#include <intrin.h>
#include <float.h>

extern "C" f32 _handmade_intrinsic_sin(f32);
#endif

inline void
ActivateSignalingNaNs()
{
#if COMPILER_MSVC
	u32 CurrentWord = 0;
	//TODO(bjorn): This is not working, and when it works, make stuff be assignable without crashing.
	//_controlfp_s(&CurrentWord, _MCW_EM & (~_EM_INVALID), _MCW_EM);
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

inline f32
Sin(f32 Value)
{
	f32 Result = 0;

	//TODO(bjorn): Compile and link my own assembly on windows.
#if COMPILER_MSVC
#if 0
	__m128 Buff = _mm_setr_ps(Value, 0, 0, 0);
	__m128 DestIntrin = _mm_sin_ps(Buff);
	float* Dest = (float*)&DestIntrin;
	Result = Dest[0];
#elif 0
    __asm
    {
        mov xmm0, dword ptr[Value]
        fsin xmm1
        mov dword ptr[Result], xmm0
    }
#else
		Result = _handmade_intrinsic_sin(Value);
#endif
#else
	//TODO IMPORTANT STUDY(bjorn): Get this to be higher accuracy.
	//TODO(bjorn): Handle negative input.
	Assert(Value >= 0);

	s32 Divisors = FloorF32ToS32(Value * (1.0f/(tau32/4.0f)));
	s32 Quadrant = Divisors % 4;

	Value -= Divisors * (tau32/4.0f);

	if(Quadrant == 1 || Quadrant == 3)
	{
		Value = (tau32/4.0f) - Value;
	}

	Assert(0.0f <= Value && Value <= (tau32/4.0f));

	f32 x2 = Value * Value;
	f32 x3 = Value * x2;
	f32 x5 = x3 * x2;
	f32 x7 = x5 * x2;
	f32 x9 = x7 * x2;
	f32 x11 = x9 * x2;
	Result = (Value 
						- x3 * (1.0f/(1*2*3)) 
						+ x5 * (1.0f/(1*2*3*4*5)) 
						- x7 * (1.0f/(1*2*3*4*5*6*7)) 
						//+ x9 * (1.0f/(1*2*3*4*5*6*7*8*9))
						//- x11 * (1.0f/(1*2*3*4*5*6*7*8*9*10*11))
						);

	Assert(0.0f <= Result && Result <= 1.0001f);

	if(Quadrant == 2 || Quadrant == 3)
	{
		Result = -Result;
	}
#endif

	return Result;
}

inline f32
Cos(f32 Value)
{
	return Sin(Value + pi32*0.5f);
}


#define INTRINSICS_H
#endif
