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

#define MATH_H
#endif
