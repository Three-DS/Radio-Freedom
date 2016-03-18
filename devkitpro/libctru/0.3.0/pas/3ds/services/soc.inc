  function SOC_Initialize(context_addr:pu32; context_size:u32):s32;cdecl;external;
  {Example context_size: 0x48000. The specified context buffer can no longer be accessed by the process which called this function, since the userland permissions for this block are set to no-acces }
  function SOC_Shutdown:s32;cdecl;external;
  function SOC_GetErrno:s32;cdecl;external;
//  function SOC_Shutdown:longint;cdecl;external;
//  function SOC_GetErrno:longint;cdecl;external;

  { this is supposed to be in unistd.h but newlib only puts it for cygwin  }
  function gethostid:longint;cdecl;external;
