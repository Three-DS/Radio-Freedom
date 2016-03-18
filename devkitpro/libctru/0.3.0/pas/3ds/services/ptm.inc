  function ptmInit:s32;cdecl;external;
  function ptmExit:s32;cdecl;external;
  function PTMU_GetBatteryLevel(servhandle:pHandle; blout:pu8):s32;cdecl;external;
  function PTMU_GetBatteryChargeState(servhandle:pHandle; bcout:pu8):s32;cdecl;external;
