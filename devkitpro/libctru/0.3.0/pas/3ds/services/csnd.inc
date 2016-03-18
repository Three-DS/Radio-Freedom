  const
     CSND_SHAREDMEM_DEFAULT = $10004000;     

  type

     CSND_LOOPING = (CSND_LOOP_DISABLE,CSND_LOOP_ENABLE);
  {"3 = PSG, similar to DS?" }

     CSND_ENCODING = (CSND_ENCODING_PCM8,CSND_ENCODING_PCM16,
                      CSND_ENCODING_IMA_ADPCM,CSND_ENCODING_PSG);
  {See here regarding CSND shared-mem commands, etc: http://3dbrew.org/wiki/CSND_Shared_Memory }

  function CSND_initialize(sharedMem:pu32):s32;cdecl;external;
  function CSND_shutdown:s32;cdecl;external;
  function CSND_playsound(channel:u32; looping:u32; encoding:u32; samplerate:u32; vaddr0:pu32; 
             vaddr1:pu32; totalbytesize:u32; unk0:u32; unk1:u32):s32;cdecl;external;
  procedure CSND_setchannel_playbackstate(channel:u32; value:u32);cdecl;external;
  procedure CSND_sharedmemtype0_cmd0(channel:u32; value:u32);cdecl;external;
  procedure CSND_writesharedmem_cmdtype0(cmdid:u16; cmdparams:pu8);cdecl;external;
  function CSND_sharedmemtype0_cmdupdatestate(waitdone:longint):s32;cdecl;external;
  function CSND_getchannelstate(entryindex:u32; chanout:pu32):s32;cdecl;external;
  function CSND_getchannelstate_isplaying(entryindex:u32; status:pu8):s32;cdecl;external;
