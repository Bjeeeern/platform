#if !defined(RESOURCE_H)

#include "types_and_defines.h"

struct loaded_bitmap
{
	void* StartOfFile;

	s32 Height;
	s32 Width;
	u32 *Pixels;
};

#pragma pack(push, 1)
struct bitmap_header
{
	u16 FileType;
	u32 FileSize;
	u16 Reserved1;
	u16 Reserved2;
	u32 BitmapOffset;
	u32 Size;
	//TODO(bjorn): Negative values means that the order of pixels are reversed. A
	//solid BMP loader should be able to handle this.
	s32 Width;
	s32 Height;
	u16 Planes;
	u16 BitsPerPixel;
	//TODO(bjorn): Not all bitmaps have the following fields neccesarily!
	u32 Compression;
	u32 SizeOfBitmap;
	s32 HorzResolution;
	s32 VertResolution;
	u32 ColorsUsed;
	u32 ColorsImportant;

	u32 RedMask;
	u32 GreenMask;
	u32 BlueMask;
};
#pragma pack(pop)

//NOTE(bjorn) Not complete BMP loading code!!
internal_function loaded_bitmap
DEBUGLoadBMP(debug_platform_read_entire_file *ReadEntireFile, char *FileName)
{
	loaded_bitmap Result = {};

	debug_read_file_result ReadResult = ReadEntireFile(FileName);
	if(ReadResult.ContentSize != 0)
	{
		Result.StartOfFile = ReadResult.Content;
		bitmap_header *Header = (bitmap_header *)ReadResult.Content;

		u32 *Pixels = (u32 *)((u8 *)ReadResult.Content + Header->BitmapOffset); 

		Assert(Header->Compression == 3);

		u32 RedMask = Header->RedMask;
		u32 GreenMask = Header->GreenMask;
		u32 BlueMask = Header->BlueMask;
		u32 AlphaMask = ~(Header->RedMask|Header->GreenMask|Header->BlueMask);

		bit_scan_result RedShift = FindLeastSignificantSetBit(RedMask);
		bit_scan_result GreenShift = FindLeastSignificantSetBit(GreenMask);
		bit_scan_result BlueShift = FindLeastSignificantSetBit(BlueMask);
		bit_scan_result AlphaShift = FindLeastSignificantSetBit(AlphaMask);

		Assert(RedShift.Found);
		Assert(GreenShift.Found);
		Assert(BlueShift.Found);
		Assert(AlphaShift.Found);

		s32 PixelCount = (ReadResult.ContentSize - Header->BitmapOffset) / 4;
		for(s32 PixelIndex = 0;
				PixelIndex < PixelCount;
				++PixelIndex)
		{
			u32 A = (Pixels[PixelIndex] >> AlphaShift.Index) & (0xFF);
			u32 R = (Pixels[PixelIndex] >> RedShift.Index) & (0xFF);
			u32 G = (Pixels[PixelIndex] >> GreenShift.Index) & (0xFF);
			u32 B = (Pixels[PixelIndex] >> BlueShift.Index) & (0xFF);

			Pixels[PixelIndex] = (A << 24) | (R << 16) | (G << 8) | (B << 0);
		}

		Result.Pixels = Pixels;
		Result.Width = Header->Width;
		Result.Height = Header->Height;
	}

	return Result;
}

struct file_resource
{
	debug_platform_read_entire_file *ReadEntireFile;
	debug_platform_get_file_edit_timestamp *GetFileEditTimestamp;
	debug_platform_free_file_memory *FreeFileMemory;

	u8 Path[path_max_char_count];
	u64 LastEdited;
};

struct bitmap_resource
{
	b32 Valid;
	file_resource FileMeta;
	loaded_bitmap Bitmap;
};

internal_function bitmap_resource
RegisterBitmapResource(debug_platform_read_entire_file *ReadEntireFile, 
											 debug_platform_get_file_edit_timestamp *GetFileEditTimestamp, 
											 debug_platform_free_file_memory *FreeFileMemory, 
											 char *FileName)
{
	bitmap_resource Result = {};

	Result.FileMeta.LastEdited = GetFileEditTimestamp(FileName);
	{
		char* Copy = FileName;
		char* Dest = (char*)Result.FileMeta.Path;
		while(*Copy != '\0') { *Dest++ = *Copy++; }
	}

	Result.FileMeta.ReadEntireFile = ReadEntireFile;
	Result.FileMeta.GetFileEditTimestamp = GetFileEditTimestamp;
	Result.FileMeta.FreeFileMemory = FreeFileMemory;

	loaded_bitmap Bitmap = DEBUGLoadBMP(ReadEntireFile, FileName);
	if(Bitmap.Pixels)
	{
		Result.Valid = true;
		Result.Bitmap = Bitmap;
	}

	return Result;
}

	internal_function void
SyncBitmapResource(bitmap_resource* BitmapResource)
{
	u64 LastEdited = BitmapResource->FileMeta.GetFileEditTimestamp((char*)BitmapResource->FileMeta.Path);

	if(BitmapResource->FileMeta.LastEdited != LastEdited)
	{
		BitmapResource->FileMeta.LastEdited = LastEdited;
		BitmapResource->FileMeta.FreeFileMemory(BitmapResource->Bitmap.StartOfFile);

		loaded_bitmap Bitmap = DEBUGLoadBMP(BitmapResource->FileMeta.ReadEntireFile, 
																				(char*)BitmapResource->FileMeta.Path);
		if(Bitmap.Pixels)
		{
			BitmapResource->Valid = true;
			BitmapResource->Bitmap = Bitmap;
		}
		else
		{
			BitmapResource->Valid = false;
			BitmapResource->Bitmap = {};
		}
	}
}

#define RESOURCE_H
#endif
