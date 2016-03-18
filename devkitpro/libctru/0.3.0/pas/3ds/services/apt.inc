{$ifdef 3dsintf}

(** unsupported pragma#pragma once*)
  { TODO : find a better place to put this }
  { was #define dname def_expr }
  function RUNFLAG_APTWORKAROUND : longint;
      { return type might be wrong }

  { Home Menu }
  { Camera applet }
  { Internet Browser }
  { Application }

  type

     NS_APPID = (APPID_HOMEMENU := $101,APPID_CAMERA := $110,
       APPID_WEB := $114,APPID_APPLICATION := $300);
     PNS_APPID  = ^NS_APPID;
  { cf http://3dbrew.org/wiki/NS#AppIDs }

     APP_STATUS = (APP_NOTINITIALIZED,APP_RUNNING,APP_SUSPENDED,
       APP_EXITING,APP_SUSPENDING,APP_SLEEPMODE,
       APP_PREPARE_SLEEPMODE,APP_APPLETSTARTED,
       APP_APPLETCLOSED);
(* error 
enum {
  { 2: sleep-mode related? }
  { 4: triggered when ptm:s GetShellStatus() returns 5. }
in declaration at line 37 *)

      var
         aptEvents : array[0..2] of Handle;cvar;external;

    function aptInit:s32;cdecl;external;

    procedure aptExit;cdecl;external;

    procedure aptOpenSession;cdecl;external;

    procedure aptCloseSession;cdecl;external;

    procedure aptSetStatus(status:APP_STATUS);cdecl;external;

    function aptGetStatus:APP_STATUS;cdecl;external;

    function aptGetStatusPower:u32;cdecl;external;

    {This can be used when the status is APP_SUSPEND* to check how the return-to-menu was triggered: 0 = home-button, 1 = power-button. }
    procedure aptSetStatusPower(status:u32);cdecl;external;

    procedure aptReturnToMenu;cdecl;external;

    {This should be called by the user application when aptGetStatus() returns APP_SUSPENDING, not calling this will int32_t in return-to-menu being disabled with the status left at APP_SUSPENDING. This function will not return until th }
    procedure aptWaitStatusEvent;cdecl;external;

    procedure aptSignalReadyForSleep;cdecl;external;

    function aptGetMenuAppID:NS_APPID;cdecl;external;

    function aptMainLoop:bool;cdecl;external;

    { Use like this in your main(): while (aptMainLoop())  your code here...  }
    function APT_GetLockHandle(handle:pHandle; flags:u16; lockHandle:pHandle):s32;cdecl;external;

    function APT_Initialize(handle:pHandle; appId:NS_APPID; eventHandle1:pHandle; eventHandle2:pHandle):s32;cdecl;external;

    function APT_HardwareResetAsync(handle:pHandle):s32;cdecl;external;

    function APT_Enable(handle:pHandle; a:u32):s32;cdecl;external;

    function APT_GetAppletManInfo(handle:pHandle; inval:u8; outval8:pu8; outval32:pu32; menu_appid:pNS_APPID; 
               active_appid:pNS_APPID):s32;cdecl;external;

    function APT_PrepareToJumpToHomeMenu(handle:pHandle):s32;cdecl;external;

    function APT_JumpToHomeMenu(handle:pHandle; a:u32; b:u32; c:u32):s32;cdecl;external;

    function APT_IsRegistered(handle:pHandle; appID:NS_APPID; Regout:pu8):s32;cdecl;external;

    function APT_InquireNotification(handle:pHandle; appID:u32; signalType:pu8):s32;cdecl;external;

    function APT_NotifyToWait(handle:pHandle; appID:NS_APPID):s32;cdecl;external;

    function APT_AppletUtility(handle:pHandle; Appout:pu32; a:u32; size1:u32; buf1:pu8;
               size2:u32; buf2:pu8):s32;cdecl;external;

    function APT_GlanceParameter(handle:pHandle; appID:NS_APPID; bufferSize:u32; buffer:pu32; actualSize:pu32; 
               signalType:pu8):s32;cdecl;external;

    function APT_ReceiveParameter(handle:pHandle; appID:NS_APPID; bufferSize:u32; buffer:pu32; actualSize:pu32; 
               signalType:pu8):s32;cdecl;external;

    function APT_SendParameter(handle:pHandle; src_appID:NS_APPID; dst_appID:NS_APPID; bufferSize:u32; buffer:pu32; 
               paramhandle:Handle; signalType:u8):s32;cdecl;external;

    function APT_SendCaptureBufferInfo(handle:pHandle; bufferSize:u32; buffer:pu32):s32;cdecl;external;

    function APT_ReplySleepQuery(handle:pHandle; appID:NS_APPID; a:u32):s32;cdecl;external;

    function APT_ReplySleepNotificationComplete(handle:pHandle; appID:NS_APPID):s32;cdecl;external;

    function APT_PrepareToCloseApplication(handle:pHandle; a:u8):s32;cdecl;external;

    function APT_CloseApplication(handle:pHandle; a:u32; b:u32; c:u32):s32;cdecl;external;

    function APT_SetAppCpuTimeLimit(handle:pHandle; percent:u32):s32;cdecl;external;

    function APT_GetAppCpuTimeLimit(handle:pHandle; percent:pu32):s32;cdecl;external;

    function APT_CheckNew3DS_Application(handle:pHandle; Appout:pu8):s32;cdecl;external;

    {*Application and *System use APT commands 0x01010000 and 0x01020000. Using APT_CheckNew3DS() is recommended, this determines which of those two funcs to use automatically. When this is first ca }
    function APT_CheckNew3DS_System(handle:pHandle; Sysout:pu8):s32;cdecl;external;

    function APT_CheckNew3DS(handle:pHandle; Checkout:pu8):s32;cdecl;external;

    function APT_PrepareToDoAppJump(handle:pHandle; flags:u8; programID:u64; mediatype:u8):s32;cdecl;external;

    function APT_DoAppJump(handle:pHandle; NSbuf0Size:u32; NSbuf1Size:u32; NSbuf0Ptr:pu8; NSbuf1Ptr:pu8):s32;cdecl;external;

    function APT_PrepareToStartLibraryApplet(handle:pHandle; appID:NS_APPID):s32;cdecl;external;

    function APT_StartLibraryApplet(handle:pHandle; appID:NS_APPID; inhandle:Handle; parambuf:pu32; parambufsize:u32):s32;cdecl;external;

    function APT_LaunchLibraryApplet(appID:NS_APPID; inhandle:Handle; parambuf:pu32; parambufsize:u32):s32;cdecl;external;

    {This should be used for launching library applets, this uses the above APT_StartLibraryApplet/APT_PrepareToStartLibraryApplet funcs + apt*Session(). parambu }
{$endif 3dsintf}

{$ifdef 3dsimpl}
  function RUNFLAG_APTWORKAROUND : longint;
      { return type might be wrong }
      begin
         RUNFLAG_APTWORKAROUND:=BIT(0);
      end;
{$endif 3dsimpl}
