
  function srvInit:s32;cdecl;external;
  function srvExit:s32;cdecl;external;
  function srvRegisterClient:s32;cdecl;external;
  function srvGetServiceHandle(SrvHandle:pHandle; name:pchar):s32;cdecl;external;
  function srvPmInit:s32;cdecl;external;
  function srvRegisterProcess(procid:u32; count:u32; serviceaccesscontrol:pointer):s32;cdecl;external;
  function srvUnregisterProcess(procid:u32):s32;cdecl;external;
