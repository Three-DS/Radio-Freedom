
{$ifdef 3dsintf}
  function SYSTEM_VERSION(major,minor,revision : longint) : longint;  
  function osConvertVirtToPhys(vaddr:u32):u32;cdecl;external;
  function osConvertOldLINEARMemToNew(addr:u32):u32;cdecl;external;
  {Converts 0x14* vmem to 0x30*. Returns the input addr when it's already within the new vmem. Returns 0 when outside of either LINEAR mem areas. }
  function osStrError(error:u32):PChar;cdecl;external;
  function osGetFirmVersion:u32;cdecl;external;
  function osGetKernelVersion:u32;cdecl;external;
  function osGetTime:u64;cdecl;external;
{$endif 3dsintf}

{$ifdef 3dsimpl}
  function SYSTEM_VERSION(major,minor,revision : longint) : longint;
    begin
       SYSTEM_VERSION:=((major shl 24) or (minor shl 16)) or (revision shl 8);
    end;
{$endif 3dsimpl}
