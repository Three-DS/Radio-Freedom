{$ifdef 3dsintf}

  function GSP_REBASE_REG(r : longint) : longint;  

  {"0=first, 1=second" }
  {"Framebuffer virtual address, for the main screen this is the 3D left framebuffer" }
  {"For the main screen: 3D right framebuffer address" }
  {"Value for 0x1EF00X90, controls framebuffer width" }
  {"Framebuffer format, this u16 is written to the low u16 for LCD register 0x1EF00X70." }
  {"Value for 0x1EF00X78, controls which framebuffer is displayed" }
  {"?" }

  type

     GSP_FramebufferInfo = record
          active_framebuf : u32;
          framebuf0_vaddr : ^u32;
          framebuf1_vaddr : ^u32;
          framebuf_widthbytesize : u32;
          format : u32;
          framebuf_dispselect : u32;
          unk : u32;
       end;
      PGSP_FramebufferInfo  = ^GSP_FramebufferInfo;

     GSP_FramebufferFormats = (GSP_RGBA8_OES := 0,
				GSP_BGR8_OES := 1,
                                GSP_RGB565_OES := 2,
				GSP_RGB5_A1_OES := 3, 
				GSP_RGBA4_OES := 4);

  {See this for GSP_CaptureInfoEntry and GSP_CaptureInfo: http://3dbrew.org/wiki/GSPGPU:ImportDisplayCaptureInfo }

     GSP_CaptureInfoEntry = record
          framebuf0_vaddr : ^u32;
          framebuf1_vaddr : ^u32;
          format : u32;
          framebuf_widthbytesize : u32;
       end;

     GSP_CaptureInfo = record
          screencapture : array[0..1] of GSP_CaptureInfoEntry;
       end;
     PGSP_CaptureInfo  = ^GSP_CaptureInfo;
  { memory fill completed }
  { display transfer finished }
  { command list processing finished }
  { used to know how many events there are }

     GSP_Event = (GSPEVENT_PSC0 := 0,GSPEVENT_PSC1,GSPEVENT_VBlank0,GSPEVENT_VBlank1,
                   GSPEVENT_PPF,GSPEVENT_P3D,GSPEVENT_DMA,GSPEVENT_MAX);

  function gspInit:s32;cdecl;external;
  procedure gspExit;cdecl;external;
  function gspInitEventHandler(gspEvent:Handle; OUT gspSharedMem: pu8; gspThreadId:u8):s32;cdecl;external;
  procedure gspExitEventHandler;cdecl;external;
//  procedure gspWaitForEvent(id:GSP_Event; nextEvent:bool);cdecl;external;
  function gspWaitForEvent(id:GSP_Event; nextEvent:bool): longint;cdecl;external;
  function gspWaitForPSC0 : longint;
  function gspWaitForPSC1 : longint;  
  function gspWaitForVBlank : longint;  
  function gspWaitForVBlank0 : longint;  
  function gspWaitForVBlank1 : longint;  
  function gspWaitForPPF : longint;  
  function gspWaitForP3D : longint;  
  function gspWaitForDMA : longint;  
  function GSPGPU_AcquireRight(handle:pHandle; flags:u8):s32;cdecl;external;
  function GSPGPU_ReleaseRight(handle:pHandle):s32;cdecl;external;
  function GSPGPU_ImportDisplayCaptureInfo(handle:pHandle; captureinfo:pGSP_CaptureInfo):s32;cdecl;external;
  function GSPGPU_SaveVramSysArea(handle:pHandle):s32;cdecl;external;
  function GSPGPU_RestoreVramSysArea(handle:pHandle):s32;cdecl;external;
  function GSPGPU_SetLcdForceBlack(handle:pHandle; flags:u8):s32;cdecl;external;
  function GSPGPU_SetBufferSwap(handle:pHandle; screenid:u32; framebufinfo:pGSP_FramebufferInfo):s32;cdecl;external;
  function GSPGPU_FlushDataCache(handle:pHandle; adr:pu8; size:u32):s32;cdecl;external;
  function GSPGPU_InvalidateDataCache(handle:pHandle; adr:pu8; size:u32):s32;cdecl;external;
  function GSPGPU_WriteHWRegs(handle:pHandle; regAddr:u32; data:pu32; size:u8):s32;cdecl;external;
  function GSPGPU_WriteHWRegsWithMask(handle:pHandle; regAddr:u32; data:pu32; datasize:u8; maskdata:pu32; masksize:u8):s32;cdecl;external;
  function GSPGPU_ReadHWRegs(handle:pHandle; regAddr:u32; data:pu32; size:u8):s32;cdecl;external;
  function GSPGPU_RegisterInterruptRelayQueue(handle:pHandle; eventHandle:Handle; flags:u32; outMemHandle:pHandle; threadID:pu8):s32;cdecl;external;
  function GSPGPU_UnregisterInterruptRelayQueue(handle:pHandle):s32;cdecl;external;
  function GSPGPU_TriggerCmdReqQueue(handle:pHandle):s32;cdecl;external;
TYPE
  gxCommandS=array[0..7] of u32;

  function GSPGPU_SubmitGxCommand(sharedGspCmdBuf:pu32; gxCommand: gxCommandS ; handle:pHandle):s32;cdecl;external;
{$endif 3dsintf}

{$ifdef 3dsimpl}
  { was #define dname(params) para_def_expr }
  { argument types are unknown }
  function GSP_REBASE_REG(r : longint) : longint;
    begin
       GSP_REBASE_REG:= r - $1EB00000;
    end;

  { was #define dname(params) para_def_expr }
  { return type might be wrong }   
  function gspWaitForPSC0 : longint;
    begin
       gspWaitForPSC0:=gspWaitForEvent(GSPEVENT_PSC0,false);
    end;

  { was #define dname(params) para_def_expr }
  { return type might be wrong }   
  function gspWaitForPSC1 : longint;
    begin
       gspWaitForPSC1:=gspWaitForEvent(GSPEVENT_PSC1,false);
    end;

  { was #define dname(params) para_def_expr }
  { return type might be wrong }   
  function gspWaitForVBlank : longint;
    begin
       gspWaitForVBlank:=gspWaitForVBlank0;
    end;

  { was #define dname(params) para_def_expr }
  { return type might be wrong }   
  function gspWaitForVBlank0 : longint;
    begin
       gspWaitForVBlank0:=gspWaitForEvent(GSPEVENT_VBlank0,true);
    end;

  { was #define dname(params) para_def_expr }
  { return type might be wrong }   
  function gspWaitForVBlank1 : longint;
    begin
       gspWaitForVBlank1:=gspWaitForEvent(GSPEVENT_VBlank1,true);
    end;

  { was #define dname(params) para_def_expr }
  { return type might be wrong }   
  function gspWaitForPPF : longint;
    begin
       gspWaitForPPF:=gspWaitForEvent(GSPEVENT_PPF,false);
    end;

  { was #define dname(params) para_def_expr }
  { return type might be wrong }   
  function gspWaitForP3D : longint;
    begin
       gspWaitForP3D:=gspWaitForEvent(GSPEVENT_P3D,false);
    end;

  { was #define dname(params) para_def_expr }
  { return type might be wrong }   
  function gspWaitForDMA : longint;
    begin
       gspWaitForDMA:=gspWaitForEvent(GSPEVENT_DMA,false);
    end;
{$endif 3dsimpl}
