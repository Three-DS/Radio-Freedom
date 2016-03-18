  function HTTPC_Initialize(handle:Handle):s32;cdecl;external;
  function HTTPC_InitializeConnectionSession(handle:Handle; contextHandle:Handle):s32;cdecl;external;
  function HTTPC_CreateContext(handle:Handle; url:pchar; contextHandle:pHandle):s32;cdecl;external;
  function HTTPC_CloseContext(handle:Handle; contextHandle:Handle):s32;cdecl;external;
  function HTTPC_SetProxyDefault(handle:Handle; contextHandle:Handle):s32;cdecl;external;
  function HTTPC_AddRequestHeaderField(handle:Handle; contextHandle:Handle; name:pchar; value:pchar):s32;cdecl;external;
  function HTTPC_BeginRequest(handle:Handle; contextHandle:Handle):s32;cdecl;external;
  function HTTPC_ReceiveData(handle:Handle; contextHandle:Handle; buffer:pu8; size:u32):s32;cdecl;external;
