#if !defined(MATH_H)

#include "types_and_defines.h"

struct v2s;
struct v3s;
struct v2u;
struct v3u;
struct v2;
struct v3;
struct m22;

struct v2s
{
	union
	{
		struct
		{
			s32 X;
			s32 Y;
		};
		s32 E[2];
	};
  v2s&
    operator+=(v2s rhs)
    {
      this->X = this->X + rhs.X;
      this->Y = this->Y + rhs.Y;
      return *this;
    }
  v2s&
    operator-=(v2s rhs)
    {
      this->X = this->X - rhs.X;
      this->Y = this->Y - rhs.Y;
      return *this;
    }
  v2s&
    operator/=(s32 rhs)
    {
      this->X = this->X / rhs;
      this->Y = this->Y / rhs;
      return *this;
    }
  v2s&
    operator*=(s32 rhs)
    {
      this->X = this->X * rhs;
      this->Y = this->Y * rhs;
      return *this;
    }
	operator v3s();
	operator v2();
};

inline v2s
operator+(v2s lhs, v2s rhs)
{
  lhs += rhs;
  return lhs;
}
inline v2s
operator-(v2s lhs, v2s rhs)
{
  lhs -= rhs;
  return lhs;
}
inline v2s
operator/(v2s lhs, s32 rhs)
{
  lhs /= rhs;
  return lhs;
}
inline v2s
operator*(v2s lhs, s32 rhs)
{
  lhs *= rhs;
  return lhs;
}
inline v2s
operator-(v2s rhs)
{
	rhs.X = -rhs.X;
	rhs.Y = -rhs.Y; 
	return rhs;
}
struct v3s
{
	union
	{
		s32 E[3];
		struct
		{
			s32 X;
			s32 Y;
			s32 Z;
		};
		struct
		{
			s32 R;
			s32 G;
			s32 B;
		};
		v2s XY;
		struct
		{
			s32 ___;
			v2s YZ;
		};
	};
  v3s&
    operator+=(v3s rhs)
    {
      this->X = this->X + rhs.X;
      this->Y = this->Y + rhs.Y;
      this->Z = this->Z + rhs.Z;
      return *this;
    }
  v3s&
    operator-=(v3s rhs)
    {
      this->X = this->X - rhs.X;
      this->Y = this->Y - rhs.Y;
      this->Z = this->Z - rhs.Z;
      return *this;
    }
  v3s&
    operator/=(s32 rhs)
    {
      this->X = this->X / rhs;
      this->Y = this->Y / rhs;
      this->Z = this->Z / rhs;
      return *this;
    }
  v3s&
    operator*=(s32 rhs)
    {
      this->X = this->X * rhs;
      this->Y = this->Y * rhs;
      this->Z = this->Z * rhs;
      return *this;
    }
	operator v3();
};

inline v3s
operator+(v3s lhs, v3s rhs)
{
  lhs += rhs;
  return lhs;
}
inline v3s
operator-(v3s lhs, v3s rhs)
{
  lhs -= rhs;
  return lhs;
}
inline v3s
operator/(v3s lhs, s32 rhs)
{
  lhs /= rhs;
  return lhs;
}
inline v3s
operator*(v3s lhs, s32 rhs)
{
  lhs *= rhs;
  return lhs;
}
inline v3s
operator-(v3s rhs)
{
	rhs.X = -rhs.X;
	rhs.Y = -rhs.Y; 
	return rhs;
}

struct v2u
{
	union
	{
		struct
		{
			u32 X;
			u32 Y;
		};
		u32 E[2];
	};
  v2u&
    operator+=(v2u rhs)
    {
      this->X = this->X + rhs.X;
      this->Y = this->Y + rhs.Y;
      return *this;
    }
  v2u&
    operator-=(v2u rhs)
    {
      this->X = this->X - rhs.X;
      this->Y = this->Y - rhs.Y;
      return *this;
    }
  v2u&
    operator/=(u32 rhs)
    {
      this->X = this->X / rhs;
      this->Y = this->Y / rhs;
      return *this;
    }
  v2u&
    operator*=(u32 rhs)
    {
      this->X = this->X * rhs;
      this->Y = this->Y * rhs;
      return *this;
    }
};

inline v2u
operator+(v2u lhs, v2u rhs)
{
  lhs += rhs;
  return lhs;
}
inline v2u
operator-(v2u lhs, v2u rhs)
{
  lhs -= rhs;
  return lhs;
}
inline v2u
operator/(v2u lhs, u32 rhs)
{
  lhs /= rhs;
  return lhs;
}
inline v2u
operator*(v2u lhs, u32 rhs)
{
  lhs *= rhs;
  return lhs;
}

struct v3u
{
	union
	{
		u32 E[3];
		struct
		{
			u32 X;
			u32 Y;
			u32 Z;
		};
		struct
		{
			u32 R;
			u32 G;
			u32 B;
		};
		v2u XY;
		struct
		{
			u32 ___;
			v2u YZ;
		};
	};
  v3u&
    operator+=(v3u rhs)
    {
      this->X = this->X + rhs.X;
      this->Y = this->Y + rhs.Y;
      this->Z = this->Z + rhs.Z;
      return *this;
    }
  v3u&
    operator+=(v3s rhs)
    {
      this->X = this->X + rhs.X;
      this->Y = this->Y + rhs.Y;
      this->Z = this->Z + rhs.Z;
      return *this;
    }
  v3u&
    operator-=(v3u rhs)
    {
      this->X = this->X - rhs.X;
      this->Y = this->Y - rhs.Y;
      this->Z = this->Z - rhs.Z;
      return *this;
    }
  v3u&
    operator/=(u32 rhs)
    {
      this->X = this->X / rhs;
      this->Y = this->Y / rhs;
      this->Z = this->Z / rhs;
      return *this;
    }
  v3u&
    operator*=(u32 rhs)
    {
      this->X = this->X * rhs;
      this->Y = this->Y * rhs;
      this->Z = this->Z * rhs;
      return *this;
    }
	operator v3();
	operator v3s();
};

inline v3u
operator+(v3u lhs, v3u rhs)
{
  lhs += rhs;
  return lhs;
}
inline v3u
operator-(v3u lhs, v3u rhs)
{
  lhs -= rhs;
  return lhs;
}
inline v3u
operator/(v3u lhs, u32 rhs)
{
  lhs /= rhs;
  return lhs;
}
inline v3u
operator*(v3u lhs, u32 rhs)
{
  lhs *= rhs;
  return lhs;
}

struct v2
{
	union
	{
		struct
		{
			f32 X;
			f32 Y;
		};
		f32 E[2];
	};
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
	operator v3();
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
operator-(v2 lhs, v2s rhs)
{
  lhs -= (v2)rhs;
  return lhs;
}
inline v2
operator/(v2 lhs, f32 rhs)
{
  lhs /= rhs;
  return lhs;
}
inline v2
operator/(v2u lhs, f32 rhs)
{
  return {lhs.X / rhs, lhs.Y / rhs};
}
inline v2
operator*(v2 lhs, f32 rhs)
{
  lhs *= rhs;
  return lhs;
}
inline v2
operator*(f32 lhs, v2 rhs)
{
  return {rhs.X * lhs, rhs.Y * lhs};
}
inline v2
operator*(v2 lhs, s32 rhs)
{
  lhs *= (f32)rhs;
  return lhs;
}
inline v2
operator*(v2s lhs, f32 rhs)
{
  return {lhs.X * rhs, lhs.Y * rhs};
}
inline v2
operator-(v2 rhs)
{
	rhs.X = -rhs.X;
	rhs.Y = -rhs.Y;
  return rhs;
}

struct m22
{
	union
	{
		struct
		{
			f32 A; f32 B;
			f32 C; f32 D;
		};
		f32 E[4];
	};
};

inline v2
operator*(m22 lhs, v2 rhs)
{
	v2 Result = {};
	Result.X = lhs.A * rhs.X + lhs.B * rhs.Y;
	Result.Y = lhs.C * rhs.X + lhs.D * rhs.Y;
  return Result;
}
inline m22
operator*(m22 lhs, m22 rhs)
{
	m22 Result = {};
	Result.A = lhs.A * rhs.A + lhs.B * rhs.C; Result.B = lhs.A * rhs.B + lhs.B * rhs.D;
	Result.C = lhs.C * rhs.A + lhs.D * rhs.C; Result.D = lhs.C * rhs.B + lhs.D * rhs.D;
  return Result;
}

struct v3
{
	union
	{
		f32 E[3];
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
		v2 XY;
		struct
		{
			f32 ___;
			v2 YZ;
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

inline v2::operator 
v3()
{
	return {v2::X, v2::Y, 0};
}
inline v3u::operator 
v3()
{
	return {(f32)v3u::X, (f32)v3u::Y, (f32)v3u::Z};
}
inline v3s::operator 
v3()
{
	return {(f32)v3s::X, (f32)v3s::Y, (f32)v3s::Z};
}
inline v3u::operator 
v3s()
{
	return {(s32)v3u::X, (s32)v3u::Y, (s32)v3u::Z};
}
inline v2s::operator 
v3s()
{
	return {v2s::X, v2s::Y, 0};
}
inline v2s::operator 
v2()
{
	return {(f32)v2s::X, (f32)v2s::Y};
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
InBounds(v2s Point, v2s Lower, v2s Upper)
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
Hadamard(v2 A, v2 B)
{
	v2 Result;

	Result.X = A.X * B.X;
	Result.Y = A.Y * B.Y;

	return Result;
}
inline f32
Dot(v2 A, v2 B)
{
	f32 Result = A.X*B.X + A.Y*B.Y;
	
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
  inline v2s
RoundV2ToV2S(v2 A)
{
  return {RoundF32ToS32(A.X), RoundF32ToS32(A.Y)};
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
RoofF32ToS32(f32 Number)
{
	Number++;
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
inline f32
Square(f32 Number)
{
	return Number * Number;
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
inline s64
AbsoluteS64(s64 Number)
{
	if(Number < 0)
	{
		return Number * -1;
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
LenghtSquared(v2 A)
{
	return Square(A.X) + Square(A.Y);
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

inline v2
Normalize(v2 A)
{
	f32 SquaredLenght = LenghtSquared(A);

	if(SquaredLenght > 0.0f)
	{
		f32 InverseLength = InverseSquareRoot(SquaredLenght);
		A *= InverseLength;
	}

	return A;
}

#define MATH_H
#endif
