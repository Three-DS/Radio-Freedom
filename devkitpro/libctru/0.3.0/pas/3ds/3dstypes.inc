{$ifdef 3dsintf}
//  const
//     U64_MAX = UINT64_MAX;

  type

     mediatypes_enum = (mediatype_NAND,
                        mediatype_SDMC,
			mediatype_GAMECARD);

     u8 = cuint8;
     pu8 = ^u8;
     u16 = cuint16;
     pu16 = ^u16;
     u32 = cuint32;
     pu32 = ^u32;
     u64 = cuint64;
     pu64 = ^u64;

     s8 = cint8;
     s16 = cint16;
     s32 = cint32;
     ps32 = ^s32;
     s64 = cint64;
     ps64 = ^s64;

     bool= boolean;
     Handle  = s32;
     PHandle  = ^Handle;

     ThreadFunc = procedure (_para1:u32);cdecl;
     function BIT(n : longint) : longint;
{$endif 3dsintf}

{$ifdef 3dsimpl}  
  function BIT(n : longint) : longint;
    begin
       BIT:=1 shl n;
    end;
{$endif 3dsimpl}
