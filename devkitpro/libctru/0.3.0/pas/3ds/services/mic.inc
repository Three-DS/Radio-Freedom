  function MIC_Initialize(sharedmem:pu32; sharedmem_size:u32; control:u8; recording:u8; unk0:u8; unk1:u8; unk2:u8):s32;cdecl;external;

  {sharedmem_size = audiodata size + 4, aligned to 0x1000-bytes. The sharedmem ptr must be 0x1000-bytes aligned. The offical 3ds-sound app uses t }
  function MIC_Shutdown:s32;cdecl;external;
  function MIC_GetSharedMemOffsetValue:u32;cdecl;external;
  function MIC_ReadAudioData(outbuf:pu8; readsize:u32; waitforevent:u32):u32;cdecl;external;

  {Reads MIC audio data. When waitforevent is non-zero, this clears the event, then waits for MIC-module to signal it again when audio data is written to shared-mem. The return value is the  }
  function MIC_MapSharedMem(handle:Handle; size:u32):s32;cdecl;external;
  function MIC_UnmapSharedMem:s32;cdecl;external;
  function MIC_cmd3_Initialize(unk0:u8; unk1:u8; sharedmem_baseoffset:u32; sharedmem_endoffset:u32; unk2:u8):s32;cdecl;external;
  function MIC_cmd5:s32;cdecl;external;
  function MIC_GetCNTBit15(CNTBout:pu8):s32;cdecl;external;
  function MIC_GetEventHandle(handle:pHandle):s32;cdecl;external;
  function MIC_SetControl(value:u8):s32;cdecl;external;

  {See here: http://3dbrew.org/wiki/MIC_Services }
  function MIC_GetControl(value:pu8):s32;cdecl;external;
  function MIC_SetRecording(value:u8):s32;cdecl;external;
  function MIC_IsRecoding(value:pu8):s32;cdecl;external;
