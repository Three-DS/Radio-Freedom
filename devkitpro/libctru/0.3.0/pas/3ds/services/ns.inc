
  function nsInit:int32_t;cdecl;external;
  function nsExit:int32_t;cdecl;external;

  { NS_LaunchTitle()
    titleid			TitleId of title to launch, if 0, gamecard assumed
    launch_flags		use if you know of any
    procid			ptr to where the process id of the launched title will be written to, leave a NULL, if you don't care
   }
  function NS_LaunchTitle(titleid:u64; launch_flags:u32; procid:pu32):int32_t;cdecl;external;

  { NS_RebootToTitle()
    mediatype			mediatype for title
    titleid			TitleId of title to launch
   }
  function NS_RebootToTitle(mediatype:u8; titleid:u64):int32_t;cdecl;external;
