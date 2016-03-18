  function CFGNOR_Initialize(value:u8):s32;cdecl;external;
  function CFGNOR_Shutdown:s32;cdecl;external;
  function CFGNOR_ReadData(offset:u32; buf:pu32; size:u32):s32;cdecl;external;
  function CFGNOR_WriteData(offset:u32; buf:pu32; size:u32):s32;cdecl;external;
  function CFGNOR_DumpFlash(buf:pu32; size:u32):s32;cdecl;external;
  function CFGNOR_WriteFlash(buf:pu32; size:u32):s32;cdecl;external;
