{$ifdef 3dsintf} 
  function GX_BUFFER_DIM(w,h : longint) : longint;  
  function GX_RequestDma(gxbuf:pu32; src:pu32; dst:pu32; length:u32):s32;cdecl;external;
  function GX_SetCommandList_Last(gxbuf:pu32; buf0a:pu32; buf0s:u32; flags:u8):s32;cdecl;external;
  function GX_SetMemoryFill(gxbuf:pu32; buf0a:pu32; buf0v:u32; buf0e:pu32; width0:u16; buf1a:pu32; buf1v:u32; buf1e:pu32; width1:u16):s32;cdecl;external;
  function GX_SetDisplayTransfer(gxbuf:pu32; inadr:pu32; indim:u32; outadr:pu32; outdim:u32; flags:u32):s32;cdecl;external;
  function GX_SetTextureCopy(gxbuf:pu32; inadr:pu32; indim:u32; outadr:pu32; outdim:u32; size:u32; flags:u32):s32;cdecl;external;
  function GX_SetCommandList_First(gxbuf:pu32; buf0a:pu32; buf0s:u32; buf1a:pu32; buf1s:u32; buf2a:pu32; buf2s:u32):s32;cdecl;external;
{$endif 3dsintf}

{$ifdef 3dsimpl}
  function GX_BUFFER_DIM(w,h : longint) : longint;
    begin
    //   GX_BUFFER_DIM:=(h shl 16) or (w(@($FFFF)));
    end;
{$endif 3dsimpl}
