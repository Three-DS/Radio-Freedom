  function pmInit:int32_t;cdecl;external;
  function pmExit:int32_t;cdecl;external;

  { PM_LaunchTitle()
  About: Launches a title
  
    mediatype		mediatype of title
    titleid		TitleId of title to launch
    launch_flags	use if you know of any
   }
  function PM_LaunchTitle(mediatype:u8; titleid:u64):int32_t;cdecl;external;

  { PM_GetTitleExheaderFlags()
  About: Writes to a buffer the launch flags (8 bytes) from a title exheader.
  
    mediatype		mediatype of title
    titleid		TitleId of title
    out			ptr to where the flags should be written to
   }
  function PM_GetTitleExheaderFlags(mediatype:u8; titleid:u64; out:pu8):int32_t;cdecl;external;

  { PM_SetFIRMLaunchParams()
  About: Sets the FIRM launch params from in
  
    size			size of FIRM launch params	
    in			ptr to location of FIRM launch params
   }
  function PM_SetFIRMLaunchParams(size:u32; in:pu8):int32_t;cdecl;external;

  { PM_GetFIRMLaunchParams()
  About: Sets the FIRM launch params from in
  
    size			size of buffer to store FIRM launch params	
    out			ptr to location to write FIRM launch params
   }
  function PM_GetFIRMLaunchParams(size:u32; out:pu8):int32_t;cdecl;external;

  { PM_SetFIRMLaunchParams()
  About: Same as PM_SetFIRMLaunchParams(), but also triggers a FIRM launch
  
    firm_titleid_low	TitleID low of firm title to launch
    size				size of FIRM launch params	
    in				ptr to location of FIRM launch params
   }
  function PM_LaunchFIRMSetParams(firm_titleid_low:u64; size:u32; in:pu8):int32_t;cdecl;external;
