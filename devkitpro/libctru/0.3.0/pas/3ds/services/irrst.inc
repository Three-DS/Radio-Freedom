  const
     IRRST_SHAREDMEM_DEFAULT = $1000A000;     

    var
       irrstMemHandle : Handle;cvar;external;
       irrstSharedMem : pu32;cvar;external;

  function irrstInit(sharedMem:pu32):s32;cdecl;external;
  procedure irrstExit;cdecl;external;
  procedure irrstScanInput;cdecl;external;
  function irrstKeysHeld:u32;cdecl;external;
  procedure irrstCstickRead(pos:pcirclePosition);cdecl;external;
  procedure irrstWaitForEvent(nextEvent:bool);cdecl;external;


 // const
 //    hidCstickRead = irrstCstickRead;     { because why not }

  function IRRST_GetHandles(outMemHandle:pHandle; outEventHandle:pHandle):s32;cdecl;external;
  function IRRST_Initialize(unk1:u32; unk2:u8):s32;cdecl;external;
  function IRRST_Shutdown:s32;cdecl;external;
