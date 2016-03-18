
  function IRU_Initialize(sharedmem_addr:pu32; sharedmem_size:u32):s32;cdecl;external;
  {The permissions for the specified memory is set to RO. This memory must be already mapped. }
  function IRU_Shutdown:s32;cdecl;external;
  function IRU_GetServHandle:Handle;cdecl;external;
  function IRU_SendData(buf:pu8; size:u32; wait:u32):s32;cdecl;external;
  function IRU_RecvData(buf:pu8; size:u32; flag:u8; transfercount:pu32; wait:u32):s32;cdecl;external;
  function IRU_SetBitRate(value:u8):s32;cdecl;external;
  function IRU_GetBitRate(BitRout:pu8):s32;cdecl;external;
  function IRU_SetIRLEDState(value:u32):s32;cdecl;external;
  function IRU_GetIRLEDRecvState(IRLEout:pu32):s32;cdecl;external;
