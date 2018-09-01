#if !defined(MATH_H)

#include "types_and_defines.h"

struct v3i
{
  s32 X;
  s32 Y;
  s32 Z;
  v3i&
    operator+=(v3i rhs)
    {
      this->X = this->X + rhs.X;
      this->Y = this->Y + rhs.Y;
      this->Z = this->Z + rhs.Z;
      return *this;
    }
  v3i&
    operator-=(v3i rhs)
    {
      this->X = this->X - rhs.X;
      this->Y = this->Y - rhs.Y;
      this->Z = this->Z - rhs.Z;
      return *this;
    }
  v3i&
    operator/=(s32 rhs)
    {
      this->X = this->X / rhs;
      this->Y = this->Y / rhs;
      this->Z = this->Z / rhs;
      return *this;
    }
  v3i&
    operator*=(s32 rhs)
    {
      this->X = this->X * rhs;
      this->Y = this->Y * rhs;
      this->Z = this->Z * rhs;
      return *this;
    }
};

inline v3i
operator+(v3i lhs, v3i rhs)
{
  lhs += rhs;
  return lhs;
}
inline v3i
operator-(v3i lhs, v3i rhs)
{
  lhs -= rhs;
  return lhs;
}
inline v3i
operator/(v3i lhs, s32 rhs)
{
  lhs /= rhs;
  return lhs;
}
inline v3i
operator*(v3i lhs, s32 rhs)
{
  lhs *= rhs;
  return lhs;
}
inline v3i
operator-(v3i rhs)
{
	rhs.X = -rhs.X;
	rhs.Y = -rhs.Y; 
	return rhs;
}

struct v2i
{
  s32 X;
  s32 Y;
  v2i&
    operator+=(v2i rhs)
    {
      this->X = this->X + rhs.X;
      this->Y = this->Y + rhs.Y;
      return *this;
    }
  v2i&
    operator-=(v2i rhs)
    {
      this->X = this->X - rhs.X;
      this->Y = this->Y - rhs.Y;
      return *this;
    }
  v2i&
    operator/=(s32 rhs)
    {
      this->X = this->X / rhs;
      this->Y = this->Y / rhs;
      return *this;
    }
  v2i&
    operator*=(s32 rhs)
    {
      this->X = this->X * rhs;
      this->Y = this->Y * rhs;
      return *this;
    }
};

inline v2i
operator+(v2i lhs, v2i rhs)
{
  lhs += rhs;
  return lhs;
}
inline v2i
operator-(v2i lhs, v2i rhs)
{
  lhs -= rhs;
  return lhs;
}
inline v2i
operator/(v2i lhs, s32 rhs)
{
  lhs /= rhs;
  return lhs;
}
inline v2i
operator*(v2i lhs, s32 rhs)
{
  lhs *= rhs;
  return lhs;
}
inline v2i
operator-(v2i rhs)
{
	rhs.X = -rhs.X;
	rhs.Y = -rhs.Y; 
	return rhs;
}

struct v3
{
	union
	{
		struct
		{
			f32 X;
			f32 Y;
			f32 Z;
		};
		struct
		{
			f32 R;
			f32 G;
			f32 B;
		};
	};
	v3&
		operator+=(v3 rhs)
		{
			this->X = this->X + rhs.X;
			this->Y = this->Y + rhs.Y;
			this->Z = this->Z + rhs.Z;
			return *this;
		}
	v3&
		operator-=(v3 rhs)
		{
			this->X = this->X - rhs.X;
			this->Y = this->Y - rhs.Y;
			this->Z = this->Z - rhs.Z;
			return *this;
		}
	v3&
		operator+=(f32 rhs)
		{
			this->X = this->X + rhs;
			this->Y = this->Y + rhs;
			this->Z = this->Z + rhs;
			return *this;
		}
	v3&
		operator-=(f32 rhs)
		{
			this->X = this->X - rhs;
			this->Y = this->Y - rhs;
			this->Z = this->Z - rhs;
			return *this;
		}
	v3&
		operator/=(f32 rhs)
		{
			this->X = this->X / rhs;
			this->Y = this->Y / rhs;
			this->Z = this->Z / rhs;
			return *this;
		}
	v3&
		operator*=(f32 rhs)
		{
			this->X = this->X * rhs;
			this->Y = this->Y * rhs;
			this->Z = this->Z * rhs;
			return *this;
		}
};

inline v3
operator+(v3 lhs, v3 rhs)
{
  lhs += rhs;
  return lhs;
}
inline v3
operator-(v3 lhs, v3 rhs)
{
  lhs -= rhs;
  return lhs;
}
inline v3
operator+(v3 lhs, f32 rhs)
{
  lhs += rhs;
  return lhs;
}
inline v3
operator-(v3 lhs, f32 rhs)
{
  lhs -= rhs;
  return lhs;
}
inline v3
operator/(v3 lhs, f32 rhs)
{
  lhs /= rhs;
  return lhs;
}
inline v3
operator*(v3 lhs, f32 rhs)
{
  lhs *= rhs;
  return lhs;
}
inline v3
operator-(v3 rhs)
{
	rhs.X = -rhs.X;
	rhs.Y = -rhs.Y; return rhs;
}

struct v2
{
  f32 X;
  f32 Y;
  v2&
    operator+=(v2 rhs)
    {
      this->X = this->X + rhs.X;
      this->Y = this->Y + rhs.Y;
      return *this;
    }
  v2&
    operator-=(v2 rhs)
    {
      this->X = this->X - rhs.X;
      this->Y = this->Y - rhs.Y;
      return *this;
    }
  v2&
    operator+=(f32 rhs)
    {
      this->X = this->X + rhs;
      this->Y = this->Y + rhs;
      return *this;
    }
  v2&
    operator-=(f32 rhs)
    {
      this->X = this->X - rhs;
      this->Y = this->Y - rhs;
      return *this;
    }
  v2&
    operator/=(f32 rhs)
    {
      this->X = this->X / rhs;
      this->Y = this->Y / rhs;
      return *this;
    }
  v2&
    operator*=(f32 rhs)
    {
      this->X = this->X * rhs;
      this->Y = this->Y * rhs;
      return *this;
    }
};

inline v2
operator+(v2 lhs, v2 rhs)
{
  lhs += rhs;
  return lhs;
}
inline v2
operator-(v2 lhs, v2 rhs)
{
  lhs -= rhs;
  return lhs;
}
inline v2
operator+(v2 lhs, f32 rhs)
{
  lhs += rhs;
  return lhs;
}
inline v2
operator-(v2 lhs, f32 rhs)
{
  lhs -= rhs;
  return lhs;
}
inline v2
operator/(v2 lhs, f32 rhs)
{
  lhs /= rhs;
  return lhs;
}
inline v2
operator*(v2 lhs, f32 rhs)
{
  lhs *= rhs;
  return lhs;
}
inline v2
operator-(v2 rhs)
{
	rhs.X = -rhs.X;
	rhs.Y = -rhs.Y;
  return rhs;
}

struct increasing_from_origo
{
	v2 Lower;
	v2 Upper;
};
inline increasing_from_origo
MakeVectorsIncreasingFromOrigo(v2 MaybeLower, v2 MaybeUpper)
{
	increasing_from_origo Result;

	b32 XNotFlipped = MaybeLower.X < MaybeUpper.X;
	b32 YNotFlipped = MaybeLower.Y < MaybeUpper.Y;

	Result.Lower.X = XNotFlipped ? MaybeLower.X : MaybeUpper.X;
	Result.Lower.Y = YNotFlipped ? MaybeLower.Y : MaybeUpper.Y;
	Result.Upper.X = XNotFlipped ? MaybeUpper.X : MaybeLower.X;
	Result.Upper.Y = YNotFlipped ? MaybeUpper.Y : MaybeLower.Y;

	return Result;
}

// TODO(bjorn): Not safe. Lower and upper might be flipped?
inline b32 
InBounds(v2i Point, v2i Lower, v2i Upper)
{
	return ((Lower.X <= Point.X && Point.X <= Upper.X) &&
					(Lower.Y <= Point.Y && Point.Y <= Upper.Y));
}
inline b32
InBounds(v2 Point, v2 Lower, v2 Upper)
{
	increasing_from_origo Strict = MakeVectorsIncreasingFromOrigo(Lower, Upper);

	b32 XInBounds = (Strict.Lower.X <= Point.X && Point.X <= Strict.Upper.X);
	b32 YInBounds = (Strict.Lower.Y <= Point.Y && Point.Y <= Strict.Upper.Y);

	return (XInBounds && YInBounds);
}

inline v2
V2IntToV2(v2i Vec)
{
	v2 Result;

	Result.X = (f32)Vec.X;
	Result.Y = (f32)Vec.Y;

	return Result;
}

inline v2
Hadamard(v2 A, v2 B)
{
	v2 Result;

	Result.X = A.X * B.X;
	Result.Y = A.Y * B.Y;

	return Result;
}

//TODO(bjorn): Where does this belong.
struct dimensions
{
	v2 Min;
	v2 Max;
	f32 Width() { return this->Max.X - this->Min.X; } 
	f32 Height() { return this->Max.Y - this->Min.Y; }
};

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
Lerp(f32 A, f32 t, f32 B)
{
	return A + (B - A) * t;
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

#define MATH_H
#endif
