
  type
     gfxScreen_t = (GFX_TOP := 0,GFX_BOTTOM := 1);
     gfx3dSide_t = (GFX_LEFT := 0,GFX_RIGHT := 1);

  {system stuff }
  procedure gfxInit;cdecl;external;
  procedure gfxExit;cdecl;external;

  {control stuff }
  procedure gfxSet3D(enable:bool);cdecl;external;
  procedure gfxFlushBuffers;cdecl;external;
  procedure gfxSwapBuffers;cdecl;external;
  procedure gfxSwapBuffersGpu;cdecl;external;

  {helper stuff }
  function gfxGetFramebuffer(screen:gfxScreen_t; side:gfx3dSide_t; width:pu16; height:pu16):pu8;cdecl;external;

    var
       gfxTopLeftFramebuffers : array[0..1] of ^u8;cvar;external;
       gfxTopRightFramebuffers : array[0..1] of ^u8;cvar;external;
       gfxBottomFramebuffers : array[0..1] of ^u8;cvar;external;
       gxCmdBuf : ^u32;cvar;external;
